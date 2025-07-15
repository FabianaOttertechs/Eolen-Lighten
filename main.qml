import QtQuick 2.15
import QtQuick.Controls 2.15
import ImpactVisualizer 1.0

Window {
    width: 900
    height: 1200
    visible: true

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

        // LED indicators
        Item {
            // Head LED
            Rectangle {
                id: headLed
                width: 40; height: 40
                radius: width/2
                color: impactVisualizer.headImpact ? "red" : "transparent"
                border.color: "white"
                border.width: 2
                x: 430//parent.width/2 //- width/2
                y: 60

                SequentialAnimation on opacity {
                    running: impactVisualizer.headImpact
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.3; duration: 200 }
                    NumberAnimation { to: 1.0; duration: 200 }
                }
            }

            // Chest LED
            Rectangle {
                id: chestLed
                width: 50; height: 50
                radius: width/2
                color: impactVisualizer.chestImpact ? "red" : "transparent"
                border.color: "white"
                border.width: 2
                x: 425
                y: 300

                SequentialAnimation on opacity {
                    running: impactVisualizer.chestImpact
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.3; duration: 200 }
                    NumberAnimation { to: 1.0; duration: 200 }
                }
            }

            // Belly LED
            Rectangle {
                id: bellyLed
                width: 60; height: 60
                radius: width/2
                color: impactVisualizer.bellyImpact ? "red" : "transparent"
                border.color: "white"
                border.width: 2
                x: 415
                y: 500

                SequentialAnimation on opacity {
                    running: impactVisualizer.bellyImpact
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.3; duration: 200 }
                    NumberAnimation { to: 1.0; duration: 200 }
                }
            }

            // Feet LED
            Rectangle {
                id: feetLed
                width: 70; height: 70
                radius: width/2
                color: impactVisualizer.feetImpact ? "red" : "transparent"
                border.color: "white"
                border.width: 2
                x: 415
                y: 900

                SequentialAnimation on opacity {
                    running: impactVisualizer.feetImpact
                    loops: Animation.Infinite
                    NumberAnimation { to: 0.3; duration: 200 }
                    NumberAnimation { to: 1.0; duration: 200 }
                }
            }
        }

        // Timer to simulate sensor input
        Timer {
            interval: 2000
            running: true
            repeat: true
            onTriggered: {
                impactVisualizer.headImpact = Math.random() > 0.7
                impactVisualizer.chestImpact = Math.random() > 0.7
                impactVisualizer.bellyImpact = Math.random() > 0.7
                impactVisualizer.feetImpact = Math.random() > 0.7

                if (impactVisualizer.headImpact) resetTimer.start()
            }
        }

        Timer {
            id: resetTimer
            interval: 1000
            onTriggered: {
                impactVisualizer.headImpact = false
                impactVisualizer.chestImpact = false
                impactVisualizer.bellyImpact = false
                impactVisualizer.feetImpact = false
            }
        }

        // Debug controls
        Column {
            anchors.right: parent.right
            anchors.top: parent.top
            spacing: 10
            padding: 20

            Button {
                text: "Simulate Head Impact"
                onClicked: impactVisualizer.headImpact = true
            }
            Button {
                text: "Simulate Chest Impact"
                onClicked: impactVisualizer.chestImpact = true
            }
            Button {
                text: "Simulate Belly Impact"
                onClicked: impactVisualizer.bellyImpact = true
            }
            Button {
                text: "Simulate Feet Impact"
                onClicked: impactVisualizer.feetImpact = true
            }
        }
    }
}
