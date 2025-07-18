// import QtQuick 2.15
// import QtQuick.Controls 2.15
// import ImpactVisualizer 1.0

// Window {
//     id: mainWindow
//     width: 900
//     height: 1200
//     visible: true
//     property bool isConnected: false
//     property bool selfTestRunning: true

//     // LED control properties
//     property color headLedColor: "white"
//     property color chestLedColor: "white"
//     property color bellyLedColor: "white"
//     property color feetLedColor: "white"

//     function sendLedCommand(zone, color) {
//         var xhr = new XMLHttpRequest();
//         var url = "http://localhost:5000/api/led";
//         var data = JSON.stringify({
//             led: zone,
//             color: color
//         });

//         xhr.open("POST", url);
//         xhr.setRequestHeader("Content-Type", "application/json");

//         xhr.onreadystatechange = function() {
//             if (xhr.readyState === XMLHttpRequest.DONE) {
//                 if (xhr.status === 200) {
//                     var response = JSON.parse(xhr.responseText);
//                     console.log("Success:", response);

//                     // Atualização dupla (opcional):
//                     impactVisualizer.setLedColor(zone, color); // Atualiza o C++
//                     setLedColor(zone, color); // Atualiza o QML
//                 } else {
//                     console.error("Error:", xhr.status, xhr.responseText);
//                 }
//             }
//         };
//         xhr.send(data);
//     }

//     function setLedColor(led, color) {
//         console.log("Setting", led, "to", color);

//         switch(led) {
//             case "head":
//                 headLedColor = color;
//                 break;
//             case "chest":
//                 chestLedColor = color;
//                 break;
//             case "belly":
//                 bellyLedColor = color;
//                 break;
//             case "feet":
//                 feetLedColor = color;
//                 break;
//         }

//         // Force update
//         headLed.color = Qt.binding(function() { return headLedColor; });
//         chestLed.color = Qt.binding(function() { return chestLedColor; });
//         bellyLed.color = Qt.binding(function() { return bellyLedColor; });
//         feetLed.color = Qt.binding(function() { return feetLedColor; });
//     }

//     function resetAllLeds() {
//         headLedColor = "white";
//         chestLedColor = "white";
//         bellyLedColor = "white";
//         feetLedColor = "white";
//     }

//     ImpactVisualizer {
//         id: impactVisualizer
//         anchors.fill: parent

//         // Background image
//         Image {
//             id: bodySilhouette
//             source: "qrc:/HumanBody.png"
//             anchors.fill: parent
//             fillMode: Image.PreserveAspectFit
//         }

//         // LED indicators - now using the color properties
//         Item {
//             // Head LED
//             Rectangle {
//                 id: headLed
//                 width: 50; height: 50
//                 radius: width/2
//                 color: mainWindow.selfTestRunning ? "white" : mainWindow.headLedColor
//                 border.color: "black"
//                 border.width: 2
//                 x: 425
//                 y: 30
//             }

//             // Chest LED
//             Rectangle {
//                 id: chestLed
//                 width: 50; height: 50
//                 radius: width/2
//                 color: mainWindow.selfTestRunning ? "white" : mainWindow.chestLedColor
//                 border.color: "black"
//                 border.width: 2
//                 x: 425
//                 y: 200
//             }


//             // Belly LED
//             Rectangle {
//                 id: bellyLed
//                 width: 50; height: 50
//                 radius: width/2
//                 color: mainWindow.selfTestRunning ? "white" : mainWindow.bellyLedColor
//                 border.color: "black"
//                 border.width: 2
//                 x: 425
//                 y: 400
//             }

//             // Feet LED
//             Rectangle {
//                 id: feetLed
//                 width: 50; height: 50
//                 radius: width/2
//                 color: mainWindow.selfTestRunning ? "white" : mainWindow.feetLedColor
//                 border.color: "black"
//                 border.width: 2
//                 x: 425
//                 y: 900
//             }
//         }

//         // Self-test sequence
//         SequentialAnimation {
//             running: true
//             onStarted: console.log("Starting LED self-test...")
//             onStopped: {
//                 mainWindow.selfTestRunning = false
//                 console.log("LED self-test completed")
//                 // Reset all LEDs to white after test
//                 resetAllLeds()
//             }

//             // Test sequence remains the same...
//             ScriptAction { script: headLed.color = "yellow" }
//             PauseAnimation { duration: 500 }
//             ScriptAction { script: headLed.color = "black" }
//             PauseAnimation { duration: 200 }

//             ScriptAction { script: chestLed.color = "yellow" }
//             PauseAnimation { duration: 500 }
//             ScriptAction { script: chestLed.color = "black" }
//             PauseAnimation { duration: 200 }

//             ScriptAction { script: bellyLed.color = "yellow" }
//             PauseAnimation { duration: 500 }
//             ScriptAction { script: bellyLed.color = "black" }
//             PauseAnimation { duration: 200 }

//             ScriptAction { script: feetLed.color = "yellow" }
//             PauseAnimation { duration: 500 }
//             ScriptAction { script: feetLed.color = "black" }
//             PauseAnimation { duration: 100 }
//             ScriptAction { script: feetLed.color = "white" }

//             ParallelAnimation {
//                 ScriptAction { script: resetAllLeds() }
//             }
//             PauseAnimation { duration: 1000 }
//         }

//         // Connection button para o caso da Serial
//         // Button {
//         //     width: 100
//         //     height: 50
//         //     text: mainWindow.isConnected ? "Disconnect" : "Connect"
//         //     anchors.right: parent.right
//         //     anchors.verticalCenter: parent.verticalCenter
//         //     enabled: !mainWindow.selfTestRunning
//         //     onClicked: mainWindow.isConnected = !mainWindow.isConnected
//         // }

//     // Debug controls - now properly connected
//         Column {
//                     anchors.right: parent.right
//                     anchors.top: parent.top
//                     spacing: 10
//                     padding: 20
//                     visible: !selfTestRunning

//                     // Head LED controls
//                     Row {
//                         spacing: 5
//                         Button {
//                             text: "Head Green"
//                             onClicked: {
//                                 console.log("🟢 Head Green button pressed");
//                                 setLedColor("head", "#32cd32");
//                                 sendLedCommand("head", "green");
//                             }
//                         }
//                         Button {
//                             text: "Head Red"
//                             onClicked: {
//                                 console.log("🔴 Head Red button pressed");
//                                 setLedColor("head", "red");
//                                 sendLedCommand("head", "red");
//                             }
//                         }
//                     }

//                     // Chest LED controls
//                     Row {
//                         spacing: 5
//                         Button {
//                             text: "Chest Green"
//                             onClicked: {
//                                 console.log("🟢 Chest Green button pressed");
//                                 setLedColor("chest", "#32cd32");
//                                 sendLedCommand("chest", "green");
//                             }
//                         }
//                         Button {
//                             text: "Chest Red"
//                             onClicked: {
//                                 console.log("🔴 Chest Red button pressed");
//                                 setLedColor("chest", "red");
//                                 sendLedCommand("chest", "red");
//                             }
//                         }
//                     }

//                     // Belly LED controls
//                     Row {
//                         spacing: 5
//                         Button {
//                             text: "Belly Green"
//                             onClicked: {
//                                 console.log("🟢 Belly Green button pressed");
//                                 setLedColor("belly", "#32cd32");
//                                 sendLedCommand("belly", "green");
//                             }
//                         }
//                         Button {
//                             text: "Belly Red"
//                             onClicked: {
//                                 console.log("🔴 Belly Red button pressed");
//                                 setLedColor("belly", "red");
//                                 sendLedCommand("belly", "red");
//                             }
//                         }
//                     }

//                     // Feet LED controls
//                     Row {
//                         spacing: 5
//                         Button {
//                             text: "Feet Green"
//                             onClicked: {
//                                 console.log("🟢 Feet Green button pressed");
//                                 setLedColor("feet", "#32cd32");
//                                 sendLedCommand("feet", "green");
//                             }
//                         }
//                         Button {
//                             text: "Feet Red"
//                             onClicked: {
//                                 console.log("🔴 Feet Red button pressed");
//                                 setLedColor("feet", "red");
//                                 sendLedCommand("feet", "red");
//                             }
//                         }
//                     }

//                     Button {
//                         text: "Reset All via API"
//                         onClicked: {
//                             console.log("⚪ Reset All button pressed");

//                             var xhr = new XMLHttpRequest();
//                             xhr.open("POST", "http://localhost:5000/api/led/all");
//                             xhr.setRequestHeader("Content-Type", "application/json");

//                             xhr.onreadystatechange = function() {
//                                 if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
//                                     resetAllLeds(); // Atualiza UI após confirmação
//                                 }
//                             };

//                             xhr.send(JSON.stringify({})); // Corpo vazio ou com {"action": "reset"}
//                         }
//                     }
//                 }
//     }
// }
import QtQuick 2.15
import QtQuick.Controls 2.15
import ImpactVisualizer 1.0

Window {
    id: mainWindow
    width: 900
    height: 1200
    visible: true
    property bool isConnected: false
    property bool selfTestRunning: true

    function sendLedCommand(zone, color) {
        var xhr = new XMLHttpRequest();
        var url = "https://7248700b1416.ngrok-free.app/api/led";//"http://localhost:5000/api/led";
        var data = JSON.stringify({
            led: zone,
            color: color
        });

        xhr.open("POST", url);
        xhr.setRequestHeader("Content-Type", "application/json");

        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    var response = JSON.parse(xhr.responseText);
                    console.log("API Success:", response);

                    // Update both color and impact state via C++ method
                    //impactVisualizer.setLedColor(zone, color);
                } else {
                    console.error("API Error:", xhr.status, xhr.responseText);
                }
            }
        };
        xhr.send(data);
    }

    function resetAllLeds() {
        var xhr = new XMLHttpRequest();
        xhr.open("POST", "https://7248700b1416.ngrok-free.app/api/led/all");//"http://localhost:5000/api/led/all");
        xhr.setRequestHeader("Content-Type", "application/json");

        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
                impactVisualizer.resetAllLeds();
                impactVisualizer.resetAllImpacts();
            }
        };
        xhr.send();
    }

    ImpactVisualizer {
        id: impactVisualizer
        anchors.fill: parent

        // Background image
        Image {
            id: bodySilhouette
            source: "qrc:/HumanBody.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        // LED indicators - properly bound to C++ properties
        Item {
            // Head LED
            Rectangle {
                id: headLed
                width: 50; height: 50
                radius: width/2
                color: mainWindow.selfTestRunning ? "white" : impactVisualizer.headLedColor
                border.color: "black"
                border.width: 2
                x: 425
                y: 30
            }

            // Chest LED
            Rectangle {
                id: chestLed
                width: 50; height: 50
                radius: width/2
                color: mainWindow.selfTestRunning ? "white" : impactVisualizer.chestLedColor
                border.color: "black"
                border.width: 2
                x: 425
                y: 200
            }

            // Belly LED
            Rectangle {
                id: bellyLed
                width: 50; height: 50
                radius: width/2
                color: mainWindow.selfTestRunning ? "white" : impactVisualizer.bellyLedColor
                border.color: "black"
                border.width: 2
                x: 425
                y: 400
            }

            // Feet LED
            Rectangle {
                id: feetLed
                width: 50; height: 50
                radius: width/2
                color: mainWindow.selfTestRunning ? "white" : impactVisualizer.feetLedColor
                border.color: "black"
                border.width: 2
                x: 425
                y: 900
            }
        }

        SequentialAnimation {
            running: true
            onStarted: console.log("Starting LED self-test...")
            onStopped: {
                mainWindow.selfTestRunning = false
                console.log("LED self-test completed")
                resetAllLeds()
            }
            // Test Head LED
            ScriptAction {
                    script: sendLedCommand("head", "yellow")
                }
                PauseAnimation { duration: 500 }
                ScriptAction {
                    script: sendLedCommand("head", "white")
                }

            // Test Chest LED
                ScriptAction {
                        script: sendLedCommand("chest", "yellow")
                    }
                    PauseAnimation { duration: 500 }
                    ScriptAction {
                        script: sendLedCommand("chest", "white")
                    }

            // Test Belly LED
                    ScriptAction {
                            script: sendLedCommand("belly", "yellow")
                        }
                        PauseAnimation { duration: 500 }
                        ScriptAction {
                            script: sendLedCommand("belly", "white")
                        }

            // Test Feet LED
                        ScriptAction {
                                script: sendLedCommand("feet", "yellow")
                            }
                            PauseAnimation { duration: 500 }
                            ScriptAction {
                                script: sendLedCommand("feet", "white")
                            }
        }

        // Debug controls
        Column {
            anchors.right: parent.right
            anchors.top: parent.top
            spacing: 10
            padding: 20
            visible: !selfTestRunning

            // Head LED controls
            Row {
                spacing: 5
                Button {
                    text: "Head Green"
                    onClicked: {
                        console.log("🟢 Head Green button pressed");
                        sendLedCommand("head", "green");
                    }
                }
                Button {
                    text: "Head Red"
                    onClicked: {
                        console.log("🔴 Head Red button pressed");
                        sendLedCommand("head", "red");
                    }
                }
            }

            // Chest LED controls
            Row {
                spacing: 5
                Button {
                    text: "Chest Green"
                    onClicked: {
                        console.log("🟢 Chest Green button pressed");
                        sendLedCommand("chest", "green");
                    }
                }
                Button {
                    text: "Chest Red"
                    onClicked: {
                        console.log("🔴 Chest Red button pressed");
                        sendLedCommand("chest", "red");
                    }
                }
            }

            // Belly LED controls
            Row {
                spacing: 5
                Button {
                    text: "Belly Green"
                    onClicked: {
                        console.log("🟢 Belly Green button pressed");
                        sendLedCommand("belly", "green");
                    }
                }
                Button {
                    text: "Belly Red"
                    onClicked: {
                        console.log("🔴 Belly Red button pressed");
                        sendLedCommand("belly", "red");
                    }
                }
            }

            // Feet LED controls
            Row {
                spacing: 5
                Button {
                    text: "Feet Green"
                    onClicked: {
                        console.log("🟢 Feet Green button pressed");
                        sendLedCommand("feet", "green");
                    }
                }
                Button {
                    text: "Feet Red"
                    onClicked: {
                        console.log("🔴 Feet Red button pressed");
                        sendLedCommand("feet", "red");
                    }
                }
            }

            // Reset button
            Button {
                text: "Reset All via API"
                onClicked: {
                    console.log("⚪ Reset All button pressed");
                    resetAllLeds();
                }
            }
        }

        // Impact status indicators (optional - shows impact state)
        Column {
            anchors.left: parent.left
            anchors.top: parent.top
            spacing: 5
            padding: 20
            visible: !selfTestRunning

            Text {
                text: "WebSocket: " + (impactVisualizer.websocketConnected ? "✔ Connected" : "✖ Disconnected")
                color: impactVisualizer.websocketConnected ? "green" : "red"
                font.bold: true

            }
            Text {
                text: "Head: " + (impactVisualizer.headImpact ? "IMPACT" : "Safe")
                color: impactVisualizer.headImpact ? "red" : "green"
            }
            Text {
                text: "Chest: " + (impactVisualizer.chestImpact ? "IMPACT" : "Safe")
                color: impactVisualizer.chestImpact ? "red" : "green"
            }
            Text {
                text: "Belly: " + (impactVisualizer.bellyImpact ? "IMPACT" : "Safe")
                color: impactVisualizer.bellyImpact ? "red" : "green"
            }
            Text {
                text: "Feet: " + (impactVisualizer.feetImpact ? "IMPACT" : "Safe")
                color: impactVisualizer.feetImpact ? "red" : "green"
            }

        }
    }
}
