import QtQuick

Rectangle {
    color: "gray"
    width: 100
    height: 100

    Text {
        text: qsTr("test Z")
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent
        onClicked: parent.z++
    }
}
