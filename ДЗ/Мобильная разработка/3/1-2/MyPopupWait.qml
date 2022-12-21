import QtQuick
import QtQuick.Controls

Popup {
    id: popupWait
    anchors.centerIn: parent
    width: parent.width
    height: parent.height
    modal: true
    closePolicy: Popup.NoAutoClose

    background: Rectangle{
        opacity: 0.7
    }

    BusyIndicator {
        id: busyInd
        anchors.centerIn: parent
        running: true
    }

    Timer {
        id: tmr
        interval: 2000
        running: false
        repeat: false

        onTriggered: {
            busyInd.running = false // если убрать, то при повторном показе индикатор не крутится
            popupWait.close()
            root.state = online
        }
    }

    onVisibleChanged: {
        if (visible)
        {
            tmr.start()
            busyInd.running = true // если убрать, то при повторном показе индикатор не крутится
        }
    }
}
