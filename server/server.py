from flask import Flask, request, jsonify
from flask_cors import CORS  # Para evitar problemas de CORS com QML

app = Flask(__name__)
CORS(app)  # Permite requisições do QML

# Estado dos LEDs (simulando seu ImpactVisualizer.cpp)
led_states = {
    "head": {"impact": False, "color": "white"},
    "chest": {"impact": False, "color": "white"},
    "belly": {"impact": False, "color": "white"},
    "feet": {"impact": False, "color": "white"}
}

@app.route('/api/impact', methods=['POST'])
def handle_impact():
    data = request.get_json()
    zone = data.get('zone')
    action = data.get('action')
    
    if zone not in led_states:
        return jsonify({"error": "Zona inválida"}), 400
    
    # Simula o comportamento do seu código C++
    if action == "trigger":
        led_states[zone]["impact"] = True
        led_states[zone]["color"] = "red"
        # Simula o timer de reset após 1 segundo
        reset_after_delay(zone)
        return jsonify({"status": f"{zone} impact triggered", "color": "red"})
    
    elif action == "reset":
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "white"
        return jsonify({"status": f"{zone} reset", "color": "white"})
    
    return jsonify({"error": "Ação inválida"}), 400

@app.route('/api/impact/all', methods=['POST'])
def reset_all():
    for zone in led_states:
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "white"
    return jsonify({"status": "all zones reset", "color": "white"})

@app.route('/api/impact/status', methods=['GET'])
def get_status():
    return jsonify(led_states)

def reset_after_delay(zone):
    # Simula o QTimer::singleShot do seu código C++
    import threading
    def reset():
        import time
        time.sleep(1)  # 1 segundo de delay
        led_states[zone]["impact"] = False
        led_states[zone]["color"] = "white"
    
    thread = threading.Thread(target=reset)
    thread.start()

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)