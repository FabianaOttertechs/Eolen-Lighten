from flask import Flask, request, jsonify
from flask_cors import CORS
import datetime
import logging

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

# Configure logging
logging.basicConfig(level=logging.DEBUG)
app.logger.setLevel(logging.DEBUG)

led_states = {
    'head': 'white',
    'chest': 'white',
    'belly': 'white',
    'feet': 'white'
}

@app.route('/api/led', methods=['POST'])
def set_led():
    try:
        app.logger.debug(f"Incoming request: {request.method} {request.path}")
        app.logger.debug(f"Headers: {request.headers}")
        app.logger.debug(f"Body: {request.get_data(as_text=True)}")

        data = request.get_json()
        if not data:
            app.logger.error("No JSON data received")
            return jsonify({'error': 'No JSON data received'}), 400

        led = data.get('led', '').lower()
        color = data.get('color', '').lower()

        # Validation
        valid_leds = ['head', 'chest', 'belly', 'feet', 'all']
        valid_colors = ['white', 'red', 'green']

        if not led or led not in valid_leds:
            return jsonify({'error': f'Invalid LED. Must be one of: {valid_leds}'}), 400
        if not color or color not in valid_colors:
            return jsonify({'error': f'Invalid color. Must be one of: {valid_colors}'}), 400

        # Update state
        if led == 'all':
            for key in led_states:
                led_states[key] = color
        else:
            led_states[led] = color

        app.logger.info(f"Updated LED {led} to {color}")
        return jsonify({
            'status': 'success',
            'led': led,
            'color': color,
            'timestamp': datetime.datetime.now().isoformat()
        })

    except Exception as e:
        app.logger.error(f"Error processing request: {str(e)}", exc_info=True)
        return jsonify({'error': 'Internal server error', 'details': str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)