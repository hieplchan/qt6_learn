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

    Image {
        id: myLocalImage

        source: "qrc:/images/qt_icon.png"
        // source: "https://www.shareicon.net/data/2015/09/16/101908_qt_512x512.png"
        fillMode: Image.PreserveAspectFit

        width: 100
        height: 100
        anchors.top: myimage.bottom
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
        id: rectTapHandler
        color: inputHandler.pressed ? "red" : "blue"
        width: 50
        height: 50

        TapHandler {
            id: inputHandler
        }
    }


    Rectangle {
        id: rectMouseArea
        color: "green"
        width: 50
        height: 50

        anchors.top: rectTapHandler.bottom

        MouseArea {
            id: myMouseAre

            anchors.fill: parent

            acceptedButtons: Qt.LeftButton | Qt.RightButton
            hoverEnabled: true

            onClicked: {
                console.log("Clicked: " + mouse.button)
                if (mouse.button === Qt.LeftButton) parent.color = "blue"
                if (mouse.button === Qt.RightButton) parent.color = "green"
            }

            onDoubleClicked: console.log("Double click: " + mouse.button)
            onPositionChanged: console.log("Position X: " + mouseX + " Y: " + mouseY)

            onEntered: parent.color = "orange"
            onExited: parent.color = "black"
        }
    }
}
