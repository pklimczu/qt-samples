import QtQuick 2.0

Rectangle {
    id: dayItem
    property int itemWidth: 180
    property int itemHeight: 40
    property int hoursSlot: 1
    property string itemText: ""

    width: itemWidth
    height: hoursSlot * itemHeight
    color: "white"
    Text {
        id: entryTextObj
        text: qsTr(itemText)
        anchors.centerIn: parent
    }

    Text {
        id: className
        text: "Nazwa Przedmiotu Bardzo długa ojoj AB"
        elide: Text.ElideRight
        anchors {
            top: parent.top
            left: parent.left
            horizontalCenter: parent.horizontalCenter
            margins: 5
        }
    }

    Text {
        id: location
        text: "Aula Główna"
        font.pixelSize: 8
        anchors {
            top: className.bottom
            right: parent.right
            margins: 5
        }
    }

    Text {
        id: lecutrer
        text: "mgr inż. Jan Kowalski"
        font.pixelSize: 8
        anchors {
            bottom: parent.bottom
            left: parent.left
            margins: 5
        }
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

    Rectangle {
        property int maxWidth: 40
        property alias animationInRunning: animationIn.running
        property alias animationOutRunning: animationOut.running

        id: settingsRectangle
        width: 0
        height: parent.height
        color: "yellow"
        anchors {
            top: upperDivider.bottom
            right: parent.right
        }

        Text {
            text: "⚙"
            anchors.centerIn: parent
            visible: parent.width > 0
        }

        SequentialAnimation on width {
            id: animationIn
            running: false
            NumberAnimation {
                from: 0; to: settingsRectangle.maxWidth
                easing.type: Easing.OutSine;
                duration: 200
            }
        }

        SequentialAnimation on width {
            id: animationOut
            running: false
            NumberAnimation {
                from: settingsRectangle.maxWidth; to: 0
                easing.type: Easing.OutSine;
                duration: 200
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("Day:", parent.parent.parent.nameOfDay)
                console.log("Hour:", dayItem.parent.get_position(dayItem.parent, dayItem))
            }
        }
    }

    MouseArea {
        id: dayItemMouseArea
        anchors.fill: parent
        propagateComposedEvents: true
        hoverEnabled: true
        onContainsMouseChanged: {
            if (containsMouse)
                settingsRectangle.animationInRunning = true
            else
                settingsRectangle.animationOutRunning = true
        }
    }
}
