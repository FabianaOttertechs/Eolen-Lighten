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

    function sendLedCommand(zone, color) {
        var xhr = new XMLHttpRequest();
        var url = "http://localhost:5000/api/led";//"https://211b584c6427.ngrok-free.app/api/led";
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
                    impactVisualizer.setLedColor(zone, color);
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
                    if (xhr.readyState === XMLHttpRequest.DONE) {
                        if (xhr.status === 200) {
                            console.log("Reset successful");
                        } else {
                            console.error("Reset failed:", xhr.status);
                            // Fallback to local reset if API fails
                            impactVisualizer.resetAllLeds();
                            impactVisualizer.resetAllImpacts();
                        }
                    }
                };
                xhr.send();
    }

    // function safeSendCommand(zone, color) {
    //     if (impactVisualizer.websocketConnected) {
    //         sendLedCommand(zone, color);
    //     } else {
    //         // Atualiza localmente quando offline
    //         impactVisualizer.setLedColor(zone, color);
    //         console.log("Modo offline: LED", zone, "definido para", color);
    //     }
    // }

    ImpactVisualizer {
        id: impactVisualizer
        //anchors.fill: parent
        width: parent.width
        height: parent.height - footer.height - 20 // Reserve space for footer + margin
        // Background image
        Image {
            id: bodySilhouette
            source: "qrc:/HumanBody.png"
            anchors.centerIn: parent
            width: 900 // Adjust scale factor as needed
            height: 1000 // Maintain aspect ratio
            fillMode: Image.PreserveAspectFit
        }
        Component.onCompleted: {
            resetAllLeds() // Garante que todos começam no estado padrão
            startConnection()
        }
        // LED indicators - properly bound to C++ properties
        Item {
            // Head LED
            Rectangle {
                id: headLed
                width: 50; height: 50
                radius: width/2
                color: impactVisualizer.headLedColor
                border.color: "black"
                border.width: 2
                x: 425
                y: 38
            }

            // Chest LED
            Rectangle {
                id: chestLed
                width: 50; height: 50
                radius: width/2
                color: impactVisualizer.chestLedColor
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
                color: impactVisualizer.bellyLedColor
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
                color: impactVisualizer.feetLedColor
                border.color: "black"
                border.width: 2
                x: 425
                y: 900
            }
        }

        // Debug controls
        Column {
            anchors.right: parent.right
            anchors.top: parent.top
            spacing: 10
            padding: 20

            // Reset button
            Rectangle {
                id:resetButton
                width: 150
                height: 60
                radius: width / 2
                color: "#ffa500"////"transparent""#ffb74d""#ffd54f""#ff8c00"
                border.color: "black"
                border.width: 3

                Text {
                    text: "Reset All"
                    anchors.centerIn: parent
                    font.pixelSize: 16
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("⚪ Reset All button pressed");
                        resetAllLeds();
                    }
                }
            }

        }
        Column {
            anchors.left: parent.left
            anchors.top: parent.top
            spacing: 5
            padding: 20

            Text {

                text: {
                        if (impactVisualizer.webSocketConnected) {
                            return "Estado: Conectado";
                        } else {
                            return "Estado: Desconectado";
                        }
                    }
                    color: impactVisualizer.webSocketConnected ? "green" : "red"
                    font.bold: true
                    font.pixelSize: 14

                }

            // Capacete (Head)
            Text {
                text: {
                    var color = impactVisualizer.headLedColor;
                    this.color = (color.toString() === "#ffffff") ? "black" : color;

                    if (color.toString() === "#ff0000") return "Capacete: UNSAFE (IMPACT)";
                    else if (color.toString() === "#ffd300") return "Capacete: WARNING - UNSAFE";
                    else if (color.toString() === "#32cd32") return "Capacete: SAFE";
                    else return "Capacete: No Data";
                }
                font.pixelSize: 14
            }

            // Cinto (Chest)
            Text {
                text: {
                    var color = impactVisualizer.chestLedColor;
                    this.color = (color.toString() === "#ffffff") ? "black" : color;

                    if (color.toString() === "#ff0000") return "Cinto: UNSAFE (IMPACT)";
                    else if (color.toString() === "#ffd300") return "Cinto: WARNING - UNSAFE";
                    else if (color.toString() === "#32cd32") return "Cinto: SAFE";
                    else return "Cinto: No Data";
                }
                font.pixelSize: 14
            }

            // Travaquedas (Belly)
            Text {
                text: {
                    var color = impactVisualizer.bellyLedColor;
                    this.color = (color.toString() === "#ffffff") ? "black" : color;

                    if (color.toString() === "#ff0000") return "Travaquedas: UNSAFE (IMPACT)";
                    else if (color.toString() === "#ffd300") return "Travaquedas: WARNING - UNSAFE";
                    else if (color.toString() === "#32cd32") return "Travaquedas: SAFE";
                    else return "Travaquedas: No Data";
                }
                font.pixelSize: 14
            }

            // Botas (Feet)
            Text {
                text: {
                    var color = impactVisualizer.feetLedColor;
                    this.color = (color.toString() === "#ffffff") ? "black" : color;

                    if (color.toString() === "#ff0000") return "Botas: UNSAFE (IMPACT)";
                    else if (color.toString() === "#ffd300") return "Botas: WARNING - UNSAFE";
                    else if (color.toString() === "#32cd32") return "Botas: SAFE";
                    else return "Botas: No Data";
                }
                font.pixelSize: 14
            }
        }
    }

    Row {
        id: footer
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 40
        //spacing: 8  // Space between image and text

        Image {
            id: logoOttertech
            source: "qrc:/logoOttertechs.png"
            height: developedByText.height * 0.9  // Slightly smaller than text height
            width: height  // Keep aspect ratio (assuming square logo)
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: developedByText
            text: "Developed by Ottertechs"
            color: "black"  // Or your preferred color
            font.pixelSize: 14
            anchors.verticalCenter: logoOttertech.verticalCenter
        }
    }
        Row {
            id: i
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: -25
            spacing: 15  // Space between image and text

        Image {
            id: logoEolen
            source: "qrc:/logo_eolen.png"
            height: 100  // Slightly smaller than text height
            width: height  // Keep aspect ratio (assuming square logo)
            fillMode: Image.PreserveAspectFit
        }
    }

}
