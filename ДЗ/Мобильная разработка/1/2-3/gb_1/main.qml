import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Площадь треугольника")

    Column {
        anchors.fill: parent
        padding: 10
        spacing: 15

        MyTextField {
            id: sideA
            height: 40
            width: 200
            popertyPlaceholderText: "Введите длину стороны A"
        }

        MyTextField {
            id: sideB
            height: sideA.height
            width: sideA.width
            popertyPlaceholderText: "Введите длину стороны B"
        }
        MyTextField {
            id: sideC
            height: sideA.height
            width: sideA.width
            popertyPlaceholderText: "Введите длину стороны C"
        }

        TextField {
            id: result
            height: sideA.height
            width: sideA.width
            readOnly: true
            placeholderText: "Нажмите кнопку \"Рассчитать\""
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }

        Button {
            height: sideA.height
            width: sideA.width
            text: "Расчитать"
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                var errorA = checkInput(sideA)
                var errorB = checkInput(sideB)
                var errorC = checkInput(sideC)

                if (!(errorA && errorB && errorC))
                    return

                var a = Number(sideA.text.replace(",", "."))
                var b = Number(sideB.text.replace(",", "."))
                var c = Number(sideC.text.replace(",", "."))

                var p = (a + b + c) / 2
                console.log(p)
                result.text = Math.sqrt(p * (p - a) * (p - b) * (p - c))
            }
        }
    }

    function checkInput(obj) {
        if (obj.text === "" || obj.text == 0)
        {
            obj.animFail.start()
            return false
        }
        return true
    }
}
