import QtQuick
import QtQuick.Controls
import "qrc:/JavaScriptLib.js" as JSLib

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var func: JSLib.star()

    Component.onCompleted: {
        loader.sourceComponent = comp
    }

    ComboBox {
        anchors {
            top: parent.top
            right: parent.right
        }
        editable: false
        model: ListModel {
            id: model
            ListElement { text: "Star" }
            ListElement { text: "Home" }
            ListElement { text: "Hourglass" }
        }
        onActivated: {
            switch (currentText) {
            case "Star":
                func = JSLib.star()
                break;
            case "Home":
                func = JSLib.home()
                break;
            case "Hourglass":
                func = JSLib.hourglass()
                break;
            default:
                console.log("Sorry, we are out of " + expr + ".");
            }
            loader.sourceComponent = empty
            loader.sourceComponent = comp
        }
    }

    Loader {
        id: loader
    }
    Component {
        id: empty
        Item {}
    }

    Item {
        Component {
            id: comp
            Rectangle {
                border.width: 1
                border.color: "red"
                width: root.width * 0.8
                height: root.height
                Canvas {
                    id: mycanvas
                    anchors.fill: parent
                    property int xStep: parent.width / 6
                    property int yStep: parent.height / 5
                    onPaint: {
                        console.log("paint")
                        var ctx = getContext("2d");
                        ctx.clearRect(0, 0, width, height);
                        ctx.fillStyle = Qt.rgba(1, 0, 0, 1); // Красный
                        ctx.beginPath()

                        ctx.moveTo(func[0][0] * xStep, func[0][1] * yStep);
                        func.forEach((item, currentIndex) => {
                                         ctx.lineTo(item[0] * xStep, item[1] * yStep);
                                     })
                        ctx.closePath()
                        ctx.lineWidth = 15;
                        ctx.stroke();
                        ctx.fill()
                    }
                }
            }
        }
    }
}
