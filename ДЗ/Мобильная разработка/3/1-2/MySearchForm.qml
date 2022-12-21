import QtQuick
import QtQuick.Controls

Rectangle {
    id: searchForm
    width: 500
    height: 200
    color: "lightgreen"
    radius: 5
    border.width: 1
    border.color: "white"
    anchors.centerIn: parent

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 10

        TextField {
            id: search
            height: 40
            width: 400
            placeholderText: "Введите поисковый запрос"
            placeholderTextColor: "grey"
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Button {
            id: btn
            height: 40
            width: 120
            text: "Поиск"
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                root.state = searching
            }
        }
        Button {
            height: 40
            width: 120
            text: "Выход"
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                root.state = offline
            }
        }
    }
}
