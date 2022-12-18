import QtQuick
import QtQuick.Controls

TextField {
    id: root

    property alias animFail: anim
    property string popertyPlaceholderText

    placeholderText: popertyPlaceholderText
    placeholderTextColor: "grey"
    horizontalAlignment: Text.AlignHCenter
    anchors.horizontalCenter: parent.horizontalCenter
    validator: DoubleValidator {bottom: 1}

    ParallelAnimation {
        id: anim
        SequentialAnimation {
            PropertyAnimation {
                targets: root
                property: "color"
                to: "red"
                duration: 0
            }
            PropertyAnimation {
                targets: root
                property: "color"
                to: "black"
                duration: 1000
            }
        }
        SequentialAnimation {
            NumberAnimation {
                target: root
                property: "anchors.horizontalCenterOffset"
                to: -5
                duration: 50
            }
            NumberAnimation {
                target: root
                property: "anchors.horizontalCenterOffset"
                to: 5
                duration: 100
            }
            NumberAnimation {
                target: root
                property: "anchors.horizontalCenterOffset"
                to: 0
                duration: 50
            }
        }
    }
}
