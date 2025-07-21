from flask import Flask, request, jsonify
from flask_cors import CORS
import json
import time
from flask_socketio import SocketIO, emit
import os
from threading import Thread
import subprocess


app = Flask(__name__)
CORS(app)
#socketio = SocketIO(app, 
#                   cors_allowed_origins="*",
#                   async_mode='eventlet',  # Explicitly specify async mode
#                   logger=True,            # Enable logging
#                   engineio_logger=True)   # Enable engineio logging
socketio = SocketIO(app, 
                   ping_timeout=60,
                   ping_interval=40,
                   cors_allowed_origins="*",
                    async_mode='threading',
                    logger = True,
                    engineio_logger=True) #add para compatibilidade com ngrok

# Add connection tracking
connected_clients = set()
# Add this handler for WebSocket messages
@socketio.on('led_update')
def handle_led_update(data):
    # This will broadcast to all clients except sender
    emit('led_update', data, broadcast=True, include_self=False)
    print(f"Broadcasting LED update: {data}")

@socketio.on('impact_update') 
def handle_impact_update(data):
    emit('impact_update', data, broadcast=True, include_self=False)
    print(f"Broadcasting impact update: {data}")

@socketio.on('connect')
def handle_connect():
    sid = request.sid
    connected_clients.add(sid)
    print(f'Client connected: {sid}')
    emit('status_update', {
        'leds': led_states,
        'impacts': impact_states,
        'timestamp': time.time()
    })

@socketio.on('disconnect')
def handle_disconnect():
    sid = request.sid
    connected_clients.discard(sid)
    print(f'Client disconnected: {sid}')

# Global state storage
led_states = {
    "capacete": "white",
    "cinto": "white", 
    "travaquedas": "white",
    "botas": "white"
}

impact_states = {
    "capacete": False,
    "cinto": False,
    "travaquedas": False,
    "botas": False
}

# Track last update time for each state
last_update = time.time()

@app.route('/api/status', methods=['GET'])
def get_status():
    """Get current LED and impact status"""
    return jsonify({
        "success": True,
        "leds": led_states,
        "impacts": impact_states,
        "timestamp": time.time(),
        "last_update": last_update
    })

#@app.route('/api/led', methods=['POST'])
#def set_led():
#    """Set individual LED color"""
#    global last_update
#    
#    data = request.get_json()
#    led_zone = data.get('led')
#    color = data.get('color')
#    
#    if led_zone not in led_states:
#        return jsonify({"success": False, "error": "Invalid LED zone"}), 400
#    
    # Update LED state
#    led_states[led_zone] = color
#    last_update = time.time()
#    
#    print(f"LED {led_zone} set to {color}")
#    socketio.emit('led_update', {'led': led_zone, 'color': color})
#
#    return jsonify({
#        "success": True,
#        "led": led_zone,
#        "color": color,
#        "timestamp": last_update
#    })
@app.route('/api/led', methods=['POST'])
def set_led():
    """Set individual LED color"""
    global last_update
    
    data = request.get_json()
    led_zone = data.get('led')
    color = data.get('color')
    
    if led_zone not in led_states:
        return jsonify({"success": False, "error": "Invalid LED zone"}), 400
    
    # Update LED state
    led_states[led_zone] = color
    
    # Update impact state based on color
    if color == "red":
        impact_states[led_zone] = True
    elif color in ["green", "white", "yellow"]:
        impact_states[led_zone] = False
    
    last_update = time.time()
    
    print(f"LED {led_zone} set to {color}")
    # Emit both updates
    socketio.emit('led_update', {'led': led_zone, 'color': color})
    socketio.emit('impact_update', {
        'zone': led_zone,
        'impact': impact_states[led_zone],
        'led_color': color
    })

    return jsonify({
        "success": True,
        "led": led_zone,
        "color": color,
        "impact": impact_states[led_zone],
        "timestamp": last_update
    })

@app.route('/api/led/all', methods=['POST'])
def reset_all_leds():
    """Reset all LEDs to white"""
    global last_update
    
    for zone in led_states:
        led_states[zone] = "white"
    
    for zone in impact_states:
        impact_states[zone] = False
    
    last_update = time.time()
    
    print("All LEDs reset to white")
    # Emit both updates to ensure all clients sync
    socketio.emit('state_update', {
        "leds": led_states,
        "impacts": impact_states,
        "timestamp": time.time()
    })
    socketio.emit('led_update', {'led': 'all', 'color': 'white'}, broadcast=True)

    return jsonify({
        "success": True,
        "message": "All LEDs reset",
        "leds": led_states,
        "impacts": impact_states,
        "timestamp": last_update
    })

#@app.route('/api/impact', methods=['POST'])
#def set_impact():
#    """Set impact status for a zone"""
#    global last_update
#    
#    data = request.get_json()
#    zone = data.get('zone')
#    impact = data.get('impact', False)
#    
#    if zone not in impact_states:
#        return jsonify({"success": False, "error": "Invalid impact zone"}), 400
#    
#    # Update impact state
#    impact_states[zone] = impact
#    
    # Automatically set LED color based on impact
#    if impact:
#        led_states[zone] = "red"
#    else:
#        led_states[zone] = "green"
#    
#    last_update = time.time()
#    
#    print(f"Impact {zone} set to {impact}")
#    socketio.emit('impact_update', {
#    'zone': zone,
#    'impact': impact,
#    'led_color': led_states[zone]
#})
#
#    return jsonify({
#        "success": True,
#        "zone": zone,
#        "impact": impact,
#        "led_color": led_states[zone],
#        "timestamp": last_update
#    })
@app.route('/api/impact', methods=['POST'])
def set_impact():
    """Set impact status for a zone"""
    global last_update
    
    data = request.get_json()
    zone = data.get('zone')
    impact = data.get('impact', False)
    warning = data.get('warning', False)  # New warning state
    
    if zone not in impact_states:
        return jsonify({"success": False, "error": "Invalid impact zone"}), 400
    
    # Update impact state
    impact_states[zone] = impact
    
    # Automatically set LED color based on impact and warning
    if impact:
        led_states[zone] = "red"
    elif warning:
        led_states[zone] = "yellow"
    else:
        led_states[zone] = "green"
    
    last_update = time.time()
    
    print(f"Impact {zone} set to {impact}, warning: {warning}")
    socketio.emit('impact_update', {
        'zone': zone,
        'impact': impact,
        'warning': warning,
        'led_color': led_states[zone]
    })

    return jsonify({
        "success": True,
        "zone": zone,
        "impact": impact,
        "warning": warning,
        "led_color": led_states[zone],
        "timestamp": last_update
    })

# Web interface for testing
@app.route('/')
def index():
    return '''
    <!DOCTYPE html>
<html>
<head>
    <title>Impact Visualizer Control</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        .controls { margin: 20px 0; }
        .zone { margin: 10px 0; padding: 10px; border: 1px solid #ccc; }
        button { margin: 5px; padding: 5px 10px; }
        .status { background: #f0f0f0; padding: 10px; margin: 10px 0; }
        .red { background-color: #ffcccc; }
        .yellow { background-color: #ffffcc; }
        .green { background-color: #ccffcc; }
        .white { background-color: #ffffff; }
    </style>
</head>
<body>
    <h1>Impact Visualizer Control Panel</h1>
    
    <div class="status" id="status">
        <h3>Current Status</h3>
        <div id="led-status"></div>
        <div id="impact-status"></div>
    </div>
    
    <div class="controls">
        <h3>LED Controls</h3>
        <div class="zone">
            <strong>Capacete:</strong>
            <button class="green" onclick="setLed('capacete', 'green')">Safe (Green)</button>
            <button class="red" onclick="setLed('capacete', 'red')">Unsafe (Red)</button>
            <button class="yellow" onclick="setLed('capacete', 'yellow')">Warning (Yellow)</button>
            <button class="white" onclick="setLed('capacete', 'white')">Reset (White)</button>
        </div>
        <div class="zone">
            <strong>Cinto:</strong>
            <button class="green" onclick="setLed('cinto', 'green')">Safe (Green)</button>
            <button class="red" onclick="setLed('cinto', 'red')">Unsafe (Red)</button>
            <button class="yellow" onclick="setLed('cinto', 'yellow')">Warning (Yellow)</button>
            <button class="white" onclick="setLed('cinto', 'white')">Reset (White)</button>
        </div>
        <div class="zone">
            <strong>Travaquedas:</strong>
            <button class="green" onclick="setLed('travaquedas', 'green')">Safe (Green)</button>
            <button class="red" onclick="setLed('travaquedas', 'red')">Unsafe (Red)</button>
            <button class="yellow" onclick="setLed('travaquedas', 'yellow')">Warning (Yellow)</button>
            <button class="white" onclick="setLed('travaquedas', 'white')">Reset (White)</button>
        </div>
        <div class="zone">
            <strong>Botas:</strong>
            <button class="green" onclick="setLed('botas', 'green')">Safe (Green)</button>
            <button class="red" onclick="setLed('botas', 'red')">Unsafe (Red)</button>
            <button class="yellow" onclick="setLed('botas', 'yellow')">Warning (Yellow)</button>
            <button class="white" onclick="setLed('botas', 'white')">Reset (White)</button>
        </div>
    </div>
    
    <div class="controls">
        <button onclick="resetAll()">Reset All (White)</button>
        <button onclick="refreshStatus()">Refresh Status</button>
    </div>
    
    <script>
        function setLed(zone, color) {
            fetch('/api/led', {
                method: 'POST',
                headers: {'Content-Type': 'application/json'},
                body: JSON.stringify({led: zone, color: color})
            })
            .then(response => response.json())
            .then(data => {
                console.log('LED set:', data);
                refreshStatus();
            });
        }
        
        function resetAll() {
            fetch('/api/led/all', {
                method: 'POST',
                headers: {'Content-Type': 'application/json'},
                body: JSON.stringify({})
            })
            .then(response => response.json())
            .then(data => {
                console.log('All reset:', data);
                refreshStatus();
            });
        }
        
        function refreshStatus() {
            fetch('/api/status')
            .then(response => response.json())
            .then(data => {
                let ledHtml = '<strong>LEDs:</strong><ul>';
                for (const [zone, color] of Object.entries(data.leds)) {
                    ledHtml += `<li>${zone}: <span class="${color}">${color}</span></li>`;
                }
                ledHtml += '</ul>';
                
                let impactHtml = '<strong>Impacts:</strong><ul>';
                for (const [zone, impact] of Object.entries(data.impacts)) {
                    impactHtml += `<li>${zone}: ${impact ? 'UNSAFE' : 'Safe'}</li>`;
                }
                impactHtml += '</ul>';
                
                document.getElementById('led-status').innerHTML = ledHtml;
                document.getElementById('impact-status').innerHTML = impactHtml;
            });
        }
        
        // Auto-refresh every 5 seconds
        setInterval(refreshStatus, 5000);
        
        // Initial load
        refreshStatus();
    </script>
</body>
</html>
    '''
def start_ngrok():
    ngrok_path = os.path.join(os.path.expanduser('~'), 'ngrok')  # Ajuste para o caminho do seu Ngrok
    if os.path.exists(ngrok_path):
        subprocess.run([ngrok_path, 'http', '5000'], stdout=subprocess.PIPE)

if __name__ == '__main__':
    print("Starting Impact Visualizer Server...")
    print("Web interface: http://localhost:5000")
    print("API endpoints:")
    print("  GET  /api/status - Get current status")
    print("  POST /api/led - Set LED color")
    print("  POST /api/led/all - Reset all LEDs")
    print("  POST /api/impact - Set impact status")
        
    socketio.run(app, debug=True, host='0.0.0.0', port=5000,allow_unsafe_werkzeug=True)  # Necessário para algumas versões do Flask