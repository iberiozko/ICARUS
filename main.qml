import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        color: 'red'
        text: 'Hello my world'
    }

    MouseArea {
        anchors.fill: parent
        onClicked: logger.warning("QML HELO %s = %d", "dsgfsdgdsgs", 111)
    }
}
