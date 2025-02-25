import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property int middleHeight: (height / 2)
    property int middleWidth: (width / 2)


    CustomButton {
        id: btn1

        anchors.right: btn2.left
        y: middleHeight - height/2

        color: "red"
        colorClicked: "orange"
        title: "btn1"
    }

    CustomButton {
        id: btn2

        x: middleWidth - width/2
        y: middleHeight - height/2

        color: "red"
        colorClicked: "orange"
        title: "btn2"
    }

    CustomButton {
        id: btn3

        anchors.left: btn2.right
        y: middleHeight - height/2

        color: "red"
        colorClicked: "orange"
        title: "btn3"
    }
}
