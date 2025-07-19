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
    "head": "white",
    "chest": "white", 
    "belly": "white",
    "feet": "white"
}

impact_states = {
    "head": False,
    "chest": False,
    "belly": False,
    "feet": False
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
    last_update = time.time()
    
    print(f"LED {led_zone} set to {color}")
    socketio.emit('led_update', {'led': led_zone, 'color': color})

    return jsonify({
        "success": True,
        "led": led_zone,
        "color": color,
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

@app.route('/api/impact', methods=['POST'])
def set_impact():
    """Set impact status for a zone"""
    global last_update
    
    data = request.get_json()
    zone = data.get('zone')
    impact = data.get('impact', False)
    
    if zone not in impact_states:
        return jsonify({"success": False, "error": "Invalid impact zone"}), 400
    
    # Update impact state
    impact_states[zone] = impact
    
    # Automatically set LED color based on impact
    if impact:
        led_states[zone] = "red"
    else:
        led_states[zone] = "green"
    
    last_update = time.time()
    
    print(f"Impact {zone} set to {impact}")
    socketio.emit('impact_update', {
    'zone': zone,
    'impact': impact,
    'led_color': led_states[zone]
})

    return jsonify({
        "success": True,
        "zone": zone,
        "impact": impact,
        "led_color": led_states[zone],
        "timestamp": last_update
    })

@app.route('/api/simulate/impact', methods=['POST'])
def simulate_impact():
    """Simulate an impact for testing"""
    global last_update
    
    data = request.get_json()
    zone = data.get('zone', 'head')
    duration = data.get('duration', 3)  # Impact duration in seconds
    
    if zone not in impact_states:
        return jsonify({"success": False, "error": "Invalid zone"}), 400
    
    # Set impact state
    impact_states[zone] = True
    led_states[zone] = "red"
    last_update = time.time()
    
    print(f"Simulating impact on {zone} for {duration} seconds")
    
    # In a real application, you might want to use a background task
    # to automatically reset the impact after the duration
    
    return jsonify({
        "success": True,
        "zone": zone,
        "impact": True,
        "duration": duration,
        "timestamp": last_update
    })

@app.route('/api/simulate/clear', methods=['POST'])
def clear_impact():
    """Clear impact simulation"""
    global last_update
    
    data = request.get_json()
    zone = data.get('zone')
    
    if zone and zone in impact_states:
        impact_states[zone] = False
        led_states[zone] = "green"
    else:
        # Clear all impacts
        for z in impact_states:
            impact_states[z] = False
            led_states[z] = "white"
    
    last_update = time.time()
    
    print(f"Cleared impact for {zone if zone else 'all zones'}")
    
    # Emit updates
    socketio.emit('state_update', {
        "leds": led_states,
        "impacts": impact_states,
        "timestamp": time.time()
    })
    
    return jsonify({
        "success": True,
        "cleared": zone if zone else "all",
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
                <strong>Head:</strong>
                <button onclick="setLed('head', 'green')">Green</button>
                <button onclick="setLed('head', 'red')">Red</button>
                <button onclick="setLed('head', 'white')">White</button>
            </div>
            <div class="zone">
                <strong>Chest:</strong>
                <button onclick="setLed('chest', 'green')">Green</button>
                <button onclick="setLed('chest', 'red')">Red</button>
                <button onclick="setLed('chest', 'white')">White</button>
            </div>
            <div class="zone">
                <strong>Belly:</strong>
                <button onclick="setLed('belly', 'green')">Green</button>
                <button onclick="setLed('belly', 'red')">Red</button>
                <button onclick="setLed('belly', 'white')">White</button>
            </div>
            <div class="zone">
                <strong>Feet:</strong>
                <button onclick="setLed('feet', 'green')">Green</button>
                <button onclick="setLed('feet', 'red')">Red</button>
                <button onclick="setLed('feet', 'white')">White</button>
            </div>
        </div>
        
        <div class="controls">
            <h3>Impact Simulation</h3>
            <div class="zone">
                <button onclick="simulateImpact('head')">Head Impact</button>
                <button onclick="simulateImpact('chest')">Chest Impact</button>
                <button onclick="simulateImpact('belly')">Belly Impact</button>
                <button onclick="simulateImpact('feet')">Feet Impact</button>
            </div>
            <button onclick="clearAllImpacts()">Clear All Impacts</button>
        </div>
        
        <div class="controls">
            <button onclick="resetAll()">Reset All</button>
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
            
            function simulateImpact(zone) {
                fetch('/api/simulate/impact', {
                    method: 'POST',
                    headers: {'Content-Type': 'application/json'},
                    body: JSON.stringify({zone: zone})
                })
                .then(response => response.json())
                .then(data => {
                    console.log('Impact simulated:', data);
                    refreshStatus();
                });
            }
            
            function clearAllImpacts() {
                fetch('/api/simulate/clear', {
                    method: 'POST',
                    headers: {'Content-Type': 'application/json'},
                    body: JSON.stringify({})
                })
                .then(response => response.json())
                .then(data => {
                    console.log('Impacts cleared:', data);
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
                    document.getElementById('led-status').innerHTML = 
                        '<strong>LEDs:</strong> ' + JSON.stringify(data.leds);
                    document.getElementById('impact-status').innerHTML = 
                        '<strong>Impacts:</strong> ' + JSON.stringify(data.impacts);
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
    print("  POST /api/simulate/impact - Simulate impact")
    print("  POST /api/simulate/clear - Clear impacts")
    
    socketio.run(app, debug=True, host='0.0.0.0', port=5000,allow_unsafe_werkzeug=True)  # Necessário para algumas versões do Flask