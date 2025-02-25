import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: myShape

        width: 100
        height: 100
        color: "orange"


        function update() {
            console.log(x + "x" + y)
            label.text = Math.round(x) + "x" + Math.round(y)
        }

        x: 0
        y: 0
        // anchors.centerIn: parent // anchors always win

        Component.onCompleted: update()
        onXChanged: update()
        onYChanged: update()

        Text {
            id: label
            text: qsTr("text")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }

    MyShape {
        color: "red"
        x: 100
    }

    MyShape {
        color: "green"
        x: 150
    }

    MyShape {
        color: "blue"
        x: 200
    }
}
