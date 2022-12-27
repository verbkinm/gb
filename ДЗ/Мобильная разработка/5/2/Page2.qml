import QtQuick
import QtQuick.Controls

Rectangle {
    color: "lightblue"
    anchors.fill: parent

    Button {
        height: 40
        width: 120
        text: "Назад"
        anchors.centerIn: parent

        onClicked: {
            root.state = app.step2
        }
    }
}
