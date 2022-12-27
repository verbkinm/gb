import QtQuick
import QtQuick.Controls

Rectangle {
    id: authForm
    width: 300
    height: 400
    color: "lightblue"
    radius: 5
    border.width: 1
    border.color: "white"
    anchors.centerIn: parent

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 10

        TextField {
            id: login
            height: 40
            width: 120
            placeholderText: "Введите логин"
            placeholderTextColor: "grey"
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        TextField {
            id: passwd
            height: login.height
            width: login.width
            placeholderText: "Введите пароль"
            placeholderTextColor: login.placeholderTextColor
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            echoMode: TextInput.Password
        }
        Button {
            id: btn
            height: login.height
            width: login.width
            text: "Войти"
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                if (login.text === "login" && passwd.text === "password")
                    root.state = app.step2
            }
        }
    }
}
