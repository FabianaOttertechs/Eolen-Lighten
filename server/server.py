from flask import Flask, request, jsonify
from flask_cors import CORS
import time
import threading

app = Flask(__name__)
CORS(app)

# Estado dos LEDs
led_states = {
    "head": {"impact": False, "color": "white"},
    "chest": {"impact": False, "color": "white"},
    "belly": {"impact": False, "color": "white"},
    "feet": {"impact": False, "color": "white"}
}

@app.route('/api/led', methods=['POST'])  # Endpoint unificado
def handle_led():
    data = request.get_json()
    
    # Validação
    if not data or 'led' not in data or 'color' not in data:
        return jsonify({"error": "Requira 'led' e 'color'"}), 400
    
    zone = data['led']
    color = data['color'].lower()
    
    if zone not in led_states:
        return jsonify({"error": "Zona inválida"}), 400

    # Lógica principal
    if color == "red":
        led_states[zone]["impact"] = True
        led_states[zone]["color"] = "red"
        reset_after_delay(zone)  # Auto-reset após 1 segundo
        status = "DANGER"
    elif color == "green":
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "green"
        status = "SAFE"
    elif color == "white":
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "white"
        status = "NEUTRAL"
    else:
        return jsonify({"error": "Cor inválida (use red/green/white)"}), 400

    print(f"LED {zone} -> {color} ({status})")
    return jsonify({
        "status": status,
        "led": zone,
        "color": color,
        "timestamp": time.time()
    })

@app.route('/api/led/all', methods=['POST'])  # Novo endpoint para reset
def reset_all():
    for zone in led_states:
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "white"
    return jsonify({"status": "ALL_RESET"})

@app.route('/api/led/status', methods=['GET'])
def get_status():
    return jsonify(led_states)

def reset_after_delay(zone):
    def reset():
        time.sleep(1)
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "white"
    threading.Thread(target=reset).start()

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)