import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: element
        text: qsTr("Hello World")
        anchors.centerIn: parent
        font.bold: true
        font.pixelSize: 25
    }
}
