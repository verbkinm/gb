import QtQuick 2.12
import QtQuick.Controls 2.12
ApplicationWindow {
    height: 450
    width: 330
    visible: true

    ListModel{
        id: users
        ListElement {
            img: "qrc:/img/азбука.jpg"
            name: "Азбука"
            author: "Просвещение"
            genre: "1 класс"
        }
        ListElement {
            img: "qrc:/img/литературное чтение.jpeg"
            name: "Литературное чтение"
            author: "Просвещение"
            genre: "1 класс"
        }
        ListElement {
            img: "qrc:/img/математика.jpeg"
            name: "Математика"
            author: "Просвещение"
            genre: "1 класс"
        }
        ListElement {
            img: "qrc:/img/русский язык 2.jpeg"
            name: "Русский язык"
            author: "Просвещение"
            genre: "2 класс"
        }
        ListElement {
            img: "qrc:/img/литературное чтение 2.jpeg"
            name: "Литературное чтение"
            author: "Просвещение"
            genre: "2 класс"
        }
        ListElement {
            img: "qrc:/img/технология 2.jpeg"
            name: "Технология"
            author: "Просвещение"
            genre: "2 класс"
        }
    }
    ListView {
        id: list
        anchors.fill: parent
        model: users
        spacing: 5
        // Хэдер
        header: Rectangle {
            width: parent.width
            height: 30
            color: "darkblue"
            Text {
                anchors.centerIn: parent
                text: "Школьная библиотека"
                color: "white"
            }
        }
        // Футер
        footer: Rectangle {
            width: parent.width
            height: 30
            color: "darkgreen"
            Text {
                anchors.centerIn: parent
                text: "Автор - Я"
                color: "white"
            }
        }
        // Секции по группам пользователей
        section.delegate: Rectangle {
            width: parent.width
            height: 40
            color: "lightblue"
            Text {
                anchors.centerIn: parent
                text: section
                color: "darkblue"
                font.weight: Font.Bold
            }
        }
        section.property: "genre"
        // Сами элементы
        delegate: Rectangle {
            width: list.width
            height: 70
            radius: 3
            border.width: 1
            border.color: "darkgray"
            color: "lightgray"
//            MouseArea {
//                anchors.fill: parent
//                onDoubleClicked: {
//                    list.model.remove(index)
//                }
//            }
            Image {
                height: 50
                source: img
                fillMode: Image.PreserveAspectFit
                anchors {
                    left: parent.left
                    top: parent.top
                    leftMargin: 20
                    topMargin: 10
                }
            }

            Column {
                anchors.fill: parent
                anchors.topMargin: 15

                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text { text: "Название"; font.weight: Font.Bold}
                    Text { text: name }
                    spacing: 20
                }
                Row {
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text { text: "Автор"; font.weight: Font.Bold}
                    Text { text: author }
                    spacing: 20
                }
            } // Column
        }// Rectangle
        focus: true
        // Анимация появления элементов модели
        populate: Transition {
            NumberAnimation { properties: "x,y"; duration: 500; easing.type:
                    Easing.OutExpo}
        }
//        // Анимация добавления элементов
//        add: Transition {
//            NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration:
//                    400 }
//            NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 100
//            }
//        }
//        // Удаление элемента
//        remove: Transition {
//            PropertyAnimation{ property: "opacity"; to: 0; duration: 1000}
//        }
//        // Вставка дефолтного пользователя при нажатии на пробел
//        Keys.onSpacePressed: model.insert(1, { group: "Пользователь",
//                                              name: "user", messagesCnt: 0,
//                                              registrationDate: "01.01.1970"})
    }// ListView
}// Item
