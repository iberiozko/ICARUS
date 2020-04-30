import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4

Window {
    id: testmodeWindow
    visible: true
    color: 'black'
    title: qsTr("ICARUS Test mode window")

    // Фон с красным бордюром, чтобы видеть границы экрана
    Rectangle {
        anchors.fill: parent
        border.width: 2
        border.color: 'red'
        color: 'darkgray'
    }
    Crosshair { anchors.fill: parent }

    // Заголовок
    Text {
        id: caption
        anchors.top: parent.top; anchors.left: parent.left; anchors.right: parent.right; height: parent.height * 0.1
        horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter
        color: 'black'
        fontSizeMode: Text.Fit; minimumPixelSize: height * 0.2; font.pixelSize: height; elide: Text.ElideMiddle
        text: qsTr('Testing and diagnostics')
    }

    Text {
        anchors.centerIn: parent
        color:  'black'
        text: "GUID = " + config.guid + ", config = " + config
    }
}
