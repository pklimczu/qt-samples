import QtQuick 2.0


Rectangle {
    property int entryWidth: 70
    property int entryHeight: 40
    property string entryText: ""

    width: entryWidth
    height: entryHeight
    color: "darkgray"
    Text {
        id: entryTextObj
        text: qsTr(entryText)
        anchors.centerIn: parent
    }

    Rectangle {
        width: parent.width
        height: 1
        id: upperDivider
        color: "black"
        anchors.top: parent.top
    }
}
