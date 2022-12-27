import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: app
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    readonly property string step1: "step1"
    readonly property string step2: "step2"
    readonly property string step3: "step3"

    Button {
        height: 40
        width: 120
        text: "Выход"

        anchors {
            top: parent.top
            right: parent.right
            rightMargin: 25
            topMargin: 25
        }

        onClicked: {
            root.state = app.step1
        }
    }

    Item {
        id:root
        anchors.fill: parent

        state: step1

        Loader {
            id: loader
            anchors.centerIn: parent
        }

        states: [
            State {
                name: step1
                PropertyChanges {
                    target: loader
                    source: "MyAuthForm.qml"
                }
            },
            State {
                name: step2
                PropertyChanges {
                    target: loader
                    source: "Page1.qml"
                }
            },
            State {
                name: step3
                PropertyChanges {
                    target: loader
                    source: "Page2.qml"
                }
            }
        ]
    }
}
