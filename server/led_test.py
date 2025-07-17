#!/usr/bin/env python3
"""
Python HTTP Test Script for LED Control
Make sure your Flask server is running on localhost:5000
"""

import requests
import json
import time
import sys

BASE_URL = "http://localhost:5000"

def send_led_command(zone, color):
    """Send LED command to the API"""
    try:
        response = requests.post(
            f"{BASE_URL}/api/led",
            json={"led": zone, "color": color},
            headers={"Content-Type": "application/json"}
        )
        if response.status_code == 200:
            print(f"✅ {zone} LED set to {color}")
            print(f"   Response: {response.json()}")
        else:
            print(f"❌ Error: {response.status_code} - {response.text}")
    except requests.exceptions.RequestException as e:
        print(f"❌ Connection error: {e}")

def get_status():
    """Get current LED status"""
    try:
        response = requests.get(f"{BASE_URL}/api/led/status")
        if response.status_code == 200:
            print("📊 Current LED Status:")
            print(json.dumps(response.json(), indent=2))
        else:
            print(f"❌ Error: {response.status_code} - {response.text}")
    except requests.exceptions.RequestException as e:
        print(f"❌ Connection error: {e}")

def reset_all():
    """Reset all LEDs to white"""
    try:
        response = requests.post(
            f"{BASE_URL}/api/led/all",
            json={},
            headers={"Content-Type": "application/json"}
        )
        if response.status_code == 200:
            print("🔄 All LEDs reset to white")
            print(f"   Response: {response.json()}")
        else:
            print(f"❌ Error: {response.status_code} - {response.text}")
    except requests.exceptions.RequestException as e:
        print(f"❌ Connection error: {e}")

def run_demo():
    """Run a demo sequence"""
    print("🎬 Running LED demo sequence...")
    
    # Demo sequence
    sequences = [
        ("head", "red"),
        ("chest", "green"),
        ("belly", "red"),
        ("feet", "green"),
    ]
    
    for zone, color in sequences:
        send_led_command(zone, color)
        time.sleep(1.5)
    
    print("⏸️  Demo complete, resetting...")
    time.sleep(2)
    reset_all()

def run_danger_simulation():
    """Simulate danger scenario"""
    print("🚨 Danger simulation: All LEDs RED")
    zones = ["head", "chest", "belly", "feet"]
    
    for zone in zones:
        send_led_command(zone, "red")
        time.sleep(0.5)
    
    print("🚨 Danger simulation complete")

def run_safe_simulation():
    """Simulate safe scenario"""
    print("✅ Safe simulation: All LEDs GREEN")
    zones = ["head", "chest", "belly", "feet"]
    
    for zone in zones:
        send_led_command(zone, "green")
        time.sleep(0.5)
    
    print("✅ Safe simulation complete")

def interactive_mode():
    """Interactive mode for testing"""
    print("\n=== Interactive LED Control ===")
    print("Commands: head/chest/belly/feet [color], status, reset, demo, danger, safe, quit")
    
    while True:
        try:
            command = input("\n> ").strip().lower()
            
            if command == "quit" or command == "q":
                break
            elif command == "status":
                get_status()
            elif command == "reset":
                reset_all()
            elif command == "demo":
                run_demo()
            elif command == "danger":
                run_danger_simulation()
            elif command == "safe":
                run_safe_simulation()
            elif " " in command:
                parts = command.split()
                if len(parts) == 2:
                    zone, color = parts
                    if zone in ["head", "chest", "belly", "feet"]:
                        send_led_command(zone, color)
                    else:
                        print("❌ Invalid zone. Use: head, chest, belly, feet")
                else:
                    print("❌ Invalid format. Use: [zone] [color]")
            else:
                print("❌ Unknown command. Type 'quit' to exit.")
                
        except KeyboardInterrupt:
            print("\n👋 Goodbye!")
            break
        except Exception as e:
            print(f"❌ Error: {e}")

def main():
    """Main function"""
    print("🔌 LED Control Test Script")
    print("Make sure your Flask server is running on localhost:5000")
    print("-" * 50)
    
    if len(sys.argv) < 2:
        print("Usage options:")
        print("  python led_test.py demo          - Run demo sequence")
        print("  python led_test.py status        - Get LED status")
        print("  python led_test.py reset         - Reset all LEDs")
        print("  python led_test.py danger        - Simulate danger (all red)")
        print("  python led_test.py safe          - Simulate safe (all green)")
        print("  python led_test.py interactive   - Interactive mode")
        print("  python led_test.py [zone] [color] - Set specific LED")
        print("\nZones: head, chest, belly, feet")
        print("Colors: red, green, white")
        return
    
    command = sys.argv[1].lower()
    
    if command == "demo":
        run_demo()
    elif command == "status":
        get_status()
    elif command == "reset":
        reset_all()
    elif command == "danger":
        run_danger_simulation()
    elif command == "safe":
        run_safe_simulation()
    elif command == "interactive":
        interactive_mode()
    elif command in ["head", "chest", "belly", "feet"]:
        if len(sys.argv) >= 3:
            color = sys.argv[2].lower()
            send_led_command(command, color)
        else:
            print("❌ Please specify a color (red, green, white)")
    else:
        print(f"❌ Unknown command: {command}")

if __name__ == "__main__":
    main()