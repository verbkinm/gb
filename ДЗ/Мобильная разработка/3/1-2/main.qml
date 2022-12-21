import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    readonly property string offline: "offline"
    readonly property string online: "online"
    readonly property string searching: "searching"
    property string lastState: ""

    Item {
        id:root
        anchors.fill: parent

        state: offline

        states: [
            State {
                name: offline
                PropertyChanges {
                    target: authForm
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: searchForm
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: popupWait
                    visible: false
                }
            },
            State {
                name: online
                PropertyChanges {
                    target: authForm
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: searchForm
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: popupWait
                    visible: false
                }
            },
            State {
                name: searching
                PropertyChanges {
                    target: popupWait
                    visible: true
                }
                PropertyChanges {
                    target: authForm
                    visible: false
                }
            }
        ]

        transitions: [
            Transition {
                from: offline
                to: online
                ParallelAnimation {
                    PropertyAnimation {
                        target: authForm
                        properties: "visible, opacity"
                        duration: 1000
                    }
                    PropertyAnimation {
                        target: searchForm
                        properties: "opacity"
                        duration: 1000
                    }
                    PropertyAnimation {
                        target: searchForm
                        properties: "visible"
                        duration: 0
                    }
                }
            },
            Transition {
                from: online
                to: offline
                ParallelAnimation {
                    PropertyAnimation {
                        target: searchForm
                        properties: "visible, opacity"
                        duration: 1000
                    }
                    PropertyAnimation {
                        target: authForm
                        properties: "opacity"
                        duration: 1000
                    }
                    PropertyAnimation {
                        target: authForm
                        properties: "visible"
                        duration: 0
                    }
                }
            }
        ]

        MyAuthForm {
            id: authForm
        }

        MySearchForm {
            id: searchForm
        }

        MyPopupWait {
            id: popupWait
        }

    }
}
