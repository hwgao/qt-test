import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: messageProvider.message
    Text {
        id: testText
        visible: true
        anchors.centerIn: parent
        text: qsTrId("welcome-message-2").arg("33").arg("44")
        scale: 3
    }
}
