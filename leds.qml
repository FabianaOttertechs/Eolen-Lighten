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
    //LED control properties
    property color headLedColor: "white"
    property color chestLedColor: "white"
    property color bellyLedColor: "white"
    property color feetLedColor: "white"

    function sendLedCommand(zone, color) {
        var xhr = new XMLHttpRequest();
        var url = "http://localhost:5000/api/led";
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

                    // Update C++ backend with the new color
                    impactVisualizer.setLedColor(zone, color);
                } else {
                    console.error("API Error:", xhr.status, xhr.responseText);
                }
            }
        };
        xhr.send(data);
    }

    function resetAllLeds() {
        var xhr = new XMLHttpRequest();
        xhr.open("POST", "http://localhost:5000/api/led/all");
        xhr.setRequestHeader("Content-Type", "application/json");

        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
                impactVisualizer.resetAllLeds(); // Reset C++ backend
            }
        };
        xhr.send(JSON.stringify({}));
    }

    function setLedColor(led, color) {
            console.log("Setting", led, "to", color);

            switch(led) {
                case "head":
                    headLedColor = color;
                    break;
                case "chest":
                    chestLedColor = color;
                    break;
                case "belly":
                    bellyLedColor = color;
                    break;
                case "feet":
                    feetLedColor = color;
                    break;
            }

            // Force update
            headLed.color = Qt.binding(function() { return headLedColor; });
            chestLed.color = Qt.binding(function() { return chestLedColor; });
            bellyLed.color = Qt.binding(function() { return bellyLedColor; });
            feetLed.color = Qt.binding(function() { return feetLedColor; });
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

        // LED indicators - now using C++ properties
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

                // Debug text
                Text {
                    anchors.centerIn: parent
                    text: "H"
                    font.bold: true
                    color: parent.color === "white" //? "black" : "white"
                }
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

                Text {
                    anchors.centerIn: parent
                    text: "C"
                    font.bold: true
                    color: parent.color === "white" //? "black" : "white"
                }
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

                Text {
                    anchors.centerIn: parent
                    text: "B"
                    font.bold: true
                    color: parent.color === "white" //? "black" : "white"
                }
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

                Text {
                    anchors.centerIn: parent
                    text: "F"
                    font.bold: true
                    color: parent.color === "white" //? "black" : "white"
                }
            }
        }

        // Self-test sequence
        SequentialAnimation {
            running: true
            onStarted: console.log("Starting LED self-test...")
            onStopped: {
                mainWindow.selfTestRunning = false
                console.log("LED self-test completed")
                impactVisualizer.resetAllLeds()
            }

            // Test sequence
            ScriptAction { script: headLed.color = "yellow" }
            PauseAnimation { duration: 500 }
            ScriptAction { script: headLed.color = "black" }
            PauseAnimation { duration: 200 }

            ScriptAction { script: chestLed.color = "yellow" }
            PauseAnimation { duration: 500 }
            ScriptAction { script: chestLed.color = "black" }
            PauseAnimation { duration: 200 }

            ScriptAction { script: bellyLed.color = "yellow" }
            PauseAnimation { duration: 500 }
            ScriptAction { script: bellyLed.color = "black" }
            PauseAnimation { duration: 200 }

            ScriptAction { script: feetLed.color = "yellow" }
            PauseAnimation { duration: 500 }
            ScriptAction { script: feetLed.color = "black" }
            PauseAnimation { duration: 100 }
            ScriptAction { script: feetLed.color = "white" }

            PauseAnimation { duration: 1000 }
        }

        // Debug controls
        Column {
            anchors.right: parent.right
            anchors.top: parent.top
            spacing: 10
            padding: 20
            visible: !selfTestRunning

            Text {
                text: "LED Controls"
                font.bold: true
                font.pixelSize: 16
            }

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

            Button {
                text: "Reset All"
                onClicked: {
                    console.log("⚪ Reset All button pressed");
                    resetAllLeds();
                }
            }

            // Status display
            Rectangle {
                width: 200
                height: 120
                border.color: "gray"
                border.width: 1
                color: "transparent"

                Column {
                    anchors.margins: 10
                    anchors.fill: parent
                    spacing: 5

                    Text {
                        text: "LED Status:"
                        font.bold: true
                    }
                    Text { text: "Head: " + impactVisualizer.headLedColor }
                    Text { text: "Chest: " + impactVisualizer.chestLedColor }
                    Text { text: "Belly: " + impactVisualizer.bellyLedColor }
                    Text { text: "Feet: " + impactVisualizer.feetLedColor }
                }
            }
        }

        Timer {
            id: statusTimer
            interval: 1000 // Aumente para 1 segundo
            //running: !socket.active // Só roda se WebSocket falhar
            onTriggered: {
                var xhr = new XMLHttpRequest()
                xhr.open("GET", "http://localhost:5000/api/led/status")
                xhr.onreadystatechange = function() {
                    if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
                        var status = JSON.parse(xhr.responseText)
                        // Atualize apenas se diferente do estado atual
                        if (headLed.color !== status.head.color) {
                            headLed.color = status.head.color
                        }
                        // Repita para outros LEDs...
                    }
                }
                xhr.send()
            }
        }
    }
}
