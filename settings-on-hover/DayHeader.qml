import QtQuick 2.0

Rectangle {
    id: dayItem
    property int itemWidth: 180
    property int itemHeight: 40
    property string itemText: ""

    width: itemWidth
    height: itemHeight
    color: "white"
    Text {
        id: entryTextObj
        text: qsTr(itemText)
        anchors.centerIn: parent
    }

    Rectangle {
        id: upperDivider
        width: parent.width
        height: 1
        color: "black"
        anchors.top: parent.top
    }

    Rectangle {
        id: leftDivider
        width: 1
        height: parent.height
        color: "black"
        anchors.top: parent.top
        anchors.left: parent.left
    }

}
