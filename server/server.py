from flask import Flask, request, jsonify
import datetime
from flask_cors import CORS

app = Flask(__name__)

CORS(app)

# LED states storage
led_states = {
    'head': 'white',
    'chest': 'white',
    'belly': 'white',
    'feet': 'white'
}

@app.route('/api/led', methods=['POST'])
def set_led():
    data = request.get_json()
    
    # Input validation
    if not data or 'led' not in data or 'color' not in data:
        return jsonify({'error': 'Missing parameters'}), 400
    
    led = data['led'].lower()
    color = data['color'].lower()
    
    # Special case: reset all LEDs
    if led == 'all':
        for key in led_states:
            led_states[key] = color
        print(f"{datetime.datetime.now()} - All LEDs set to {color}")
        return jsonify({'status': 'success', 'action': 'set_all', 'color': color})
    
    # Validate LED and color
    valid_leds = ['head', 'chest', 'belly', 'feet']
    valid_colors = ['white', 'red', 'green']
    
    if led not in valid_leds:
        return jsonify({'error': f'Invalid LED. Valid options: {valid_leds}'}), 400
    if color not in valid_colors:
        return jsonify({'error': f'Invalid color. Valid options: {valid_colors}'}), 400
    
    # Update state
    led_states[led] = color
    print(f"{datetime.datetime.now()} - LED {led} set to {color} (From IP: {request.remote_addr})")
    
    return jsonify({
        'status': 'success',
        'led': led,
        'color': color,
        'timestamp': datetime.datetime.now().isoformat()
    })

@app.route('/api/leds', methods=['GET'])
def get_leds():
    return jsonify(led_states)

@app.route('/control')
def control_panel():
    return '''
    <!DOCTYPE html>
    <html>
    <head>
        <title>LED Control Panel</title>
        <style>
            body { font-family: Arial, sans-serif; margin: 20px; }
            .led-section { margin: 15px; padding: 10px; border: 1px solid #ddd; border-radius: 5px; width: 300px; }
            button { padding: 8px 15px; margin: 5px; cursor: pointer; }
            .red { background: #ff6b6b; color: white; }
            .green { background: #51cf66; color: white; }
            .white { background: #f8f9fa; border: 1px solid #ddd; }
            .current-state { margin-top: 10px; font-weight: bold; }
        </style>
    </head>
    <body>
        <h1>LED Control Panel</h1>
        <p>Controls your Qt application's LEDs in real-time.</p>

        <!-- Head LED -->
        <div class="led-section">
            <h3>Head</h3>
            <button class="red" onclick="sendCommand('head', 'red')">Red</button>
            <button class="green" onclick="sendCommand('head', 'green')">Green</button>
            <button class="white" onclick="sendCommand('head', 'white')">White</button>
            <div class="current-state">Current: <span id="head-state">white</span></div>
        </div>

        <!-- Chest LED (repeat for belly/feet) -->
        <div class="led-section">
            <h3>Chest</h3>
            <button class="red" onclick="sendCommand('chest', 'red')">Red</button>
            <button class="green" onclick="sendCommand('chest', 'green')">Green</button>
            <button class="white" onclick="sendCommand('chest', 'white')">White</button>
            <div class="current-state">Current: <span id="chest-state">white</span></div>
        </div>

        <!-- All LEDs -->
        <div class="led-section">
            <h3>All LEDs</h3>
            <button class="red" onclick="sendCommand('all', 'red')">All Red</button>
            <button class="green" onclick="sendCommand('all', 'green')">All Green</button>
            <button class="white" onclick="sendCommand('all', 'white')">Reset All</button>
        </div>

        <script>
            // Fetch current LED states on page load
            fetch('/api/leds')
                .then(response => response.json())
                .then(data => {
                    Object.keys(data).forEach(led => {
                        document.getElementById(`${led}-state`).textContent = data[led];
                    });
                });

            // Send commands to Flask (which forwards to Qt)
            function sendCommand(led, color) {
                fetch('/api/led', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json' },
                    body: JSON.stringify({ led, color })
                })
                .then(response => response.json())
                .then(data => {
                    if (led === 'all') {
                        // Update all states
                        Object.keys(data).forEach(led => {
                            document.getElementById(`${led}-state`).textContent = color;
                        });
                    } else {
                        // Update single LED
                        document.getElementById(`${led}-state`).textContent = color;
                    }
                    alert(`Success: ${led} set to ${color}`);
                })
                .catch(error => alert(`Error: ${error}`));
            }
        </script>
    </body>
    </html>
    '''

if __name__ == '__main__':
    print("Starting LED API server on http://localhost:5000")
    print("Test page available at http://localhost:5000/test")
    app.run(host='0.0.0.0', port=5000)