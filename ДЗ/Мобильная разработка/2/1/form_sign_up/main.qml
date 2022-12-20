import QtQuick
import QtQuick.Controls 2.5

Window {
    width: 440
    height: 850
    visible: true
    title: qsTr("Hello World")

    Column {
        anchors.fill: parent
        padding: 10
        spacing: 15

        Label {
            text: "Ваше имя:"
        }
        TextField {
            placeholderText: "Введите своё имя"
            placeholderTextColor: "grey"
        }

        Label {
            text: "Ваш пол:"
        }
        ComboBox {
            model: ["женский", "мужской"]
        }

        Label {
            text: "Ваш возраст:"
        }
        TextField {
            placeholderText: "Введите ваш возраст"
            placeholderTextColor: "grey"
            validator: IntValidator {bottom: 18; top: 100}
        }

        Label {
            text: "Вашe образование:"
        }
        TextField {
            placeholderText: "Введите ваше образование"
            placeholderTextColor: "grey"
        }

        Label {
            text: "Вашe хобби:"
        }
        TextField {
            placeholderText: "Введите ваше хобби"
            placeholderTextColor: "grey"
        }

        Label {
            text: "Ваш город:"
        }
        TextField {
            placeholderText: "Введите ваш город"
            placeholderTextColor: "grey"
        }

        Label {
            text: "О себе:"
        }
        TextField {
            placeholderText: "Введите информацию о себе"
            placeholderTextColor: "grey"
        }


        Label {
            text: "\nПараметры для поиска партнёра:"
        }

        Label {
            text: "Возрастные границы:"
        }

        RangeSlider {
            id: ageSlide
            from: 18
            to: 100
            stepSize: 1
            first.value: 25
            second.value: 45
            snapMode: RangeSlider.SnapAlways
        }
        Label {
            text: ageSlide.first.value + " - " + ageSlide.second.value
        }
        Label {
            text: "Пол:"
        }
        ComboBox {
            model: ["женский", "мужской"]
        }
        Label {
            text: "Образование:"
        }
        ComboBox {
            model: ["среднее", "специальное", "высшее"]
        }

        Button {
            text: "Регистрация"

            onClicked: {

            }
        }
    }
}
