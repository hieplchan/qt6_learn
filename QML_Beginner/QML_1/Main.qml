import QtQuick

Window {
    id: root
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
        z: 1 // layers: 0 means lowest layer
    }

    Image {
        id: myimage
        source: "https://www.svgrepo.com/show/306627/qt.svg"
        anchors.centerIn: parent
        width: parent.width/2
        height: parent.height/2
        opacity: 0.25
        z: 4

        // Rectangle {
        //     color: "red"
        //     width: parent.width
        //     height: parent.height/2
        //     opacity: 0.5
        // }
    }

    TextInput {
        id: myInput
        text: "Hello World"
        anchors.centerIn: parent
    }

    Text {
        id: myText
        text: myInput.text
        x: 100
        y: 10
    }

    Rectangle {
        color: inputHandler.pressed ? "red" : "blue"
        width: 50
        height: 50

        TapHandler {
            id: inputHandler
        }
    }
}
