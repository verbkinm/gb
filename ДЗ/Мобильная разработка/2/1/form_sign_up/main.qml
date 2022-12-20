import QtQuick 2.9
import QtQuick.Controls 2.5

Window {
    width: 440
    height: 640
    visible: true
    title: qsTr("Hello World")

    Flickable {
        anchors.fill: parent
        contentHeight: 850

        Column {
            id: mainColumn
            anchors.fill: parent
            padding: 10
            spacing: 15

            Label {
                text: "Ваше имя:"
            }
            TextField {
                id: you_name
                placeholderText: "Введите своё имя"
                placeholderTextColor: "grey"
            }

            Label {
                text: "Ваш пол:"
            }
            ComboBox {
                id: you_sex
                model: ["женский", "мужской"]
            }

            Label {
                text: "Ваш возраст:"
            }
            TextField {
                id: you_age
                placeholderText: "Введите ваш возраст"
                placeholderTextColor: "grey"
                validator: IntValidator {bottom: 18; top: 100}
            }

            Label {
                text: "Вашe образование:"
            }
            TextField {
                id: you_education
                placeholderText: "Введите ваше образование"
                placeholderTextColor: "grey"
            }

            Label {
                text: "Вашe хобби:"
            }
            TextField {
                id: you_hobby
                placeholderText: "Введите ваше хобби"
                placeholderTextColor: "grey"
            }

            Label {
                text: "Ваш город:"
            }
            TextField {
                id: you_city
                placeholderText: "Введите ваш город"
                placeholderTextColor: "grey"
            }

            Label {
                id: you_about
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
                id: partner_sex
                model: ["женский", "мужской"]
            }
            Label {
                text: "Образование:"
            }
            ComboBox {
                id: partner_education
                model: ["среднее", "специальное", "высшее"]
            }

            Button {
                text: "Регистрация"

                onClicked: {
                    console.log(you_name.text)
                    console.log(you_sex.currentText)
                    console.log(you_age.text)
                    console.log(you_education.text)
                    console.log(you_hobby.text)
                    console.log(you_city.text)
                    console.log(you_about.text)
                    console.log(ageSlide.first.value, " - " ,ageSlide.second.value)
                    console.log(partner_sex.currentText)
                    console.log(partner_education.currentText)
                }
            }
        }
    }
}
