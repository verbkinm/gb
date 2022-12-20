import QtQuick 2.9

Window {
    width: 480
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect
        height: parent.height / 2
        width: height
        anchors.centerIn: parent
        color: "red"

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onClicked: (mouse) => {
                if (mouse.button === Qt.LeftButton)
                    rect.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                else if (mouse.button === Qt.RightButton)
                    animRotate.start()
            }
            onDoubleClicked: (mouse) =>{
                if (mouse.button === Qt.LeftButton)
                    animRadius.start()
            }
        }
    }

    SequentialAnimation {
        id: animRadius
        running: false

        PropertyAnimation {
            target: rect
            property: "radius"
            to: 0
            duration: 200
        }
        PropertyAnimation {
            target: rect
            property: "radius"
            to: rect.height / 2
            duration: 1000
        }
    }

    ParallelAnimation {
        id: animRotate
        running: false

        PropertyAnimation {
            target: rect
            property: "radius"
            to: 0
            duration: 200
        }
        RotationAnimation {
            target: rect
            from: 0
            to: 360
            duration: 2000
        }
    }
}
