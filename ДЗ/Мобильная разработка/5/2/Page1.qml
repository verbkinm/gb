import QtQuick
import QtQuick.Controls

Rectangle {
    color: "green"
    anchors.fill: parent

    Button {
        height: 40
        width: 120
        text: "Вперёд"
        anchors.centerIn: parent

        onClicked: {
            root.state = app.step3
        }
    }
}
