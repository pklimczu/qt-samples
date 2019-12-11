import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.11

ApplicationWindow {
    visible: true
    width: 1330
    height: 650
    title: qsTr("Hello World")

    header: RowLayout {
        id: headerRowLayout
        spacing: 10
        Rectangle {
            width: 40
            height: 50
            color: "red"
        }
        Rectangle {
            width: 40
            height: 40
            color: "red"
        }
        Rectangle {
            width: 40
            height: 40
            color: "red"
        }
    }

    Rectangle {
        id: content
        anchors {
            top: headerRowLayout.bottom
            left: parent.left
        }
        width: parent.width
        height: parent.height
        color: "lightblue"

        Component.onCompleted: {
            console.log(content.height)
        }

        RowLayout {
            spacing: 0
            anchors {
                left: parent.left
                top: parent.top
            }

            Hours {
                id: hours
            }
            Day {
                id: mondayColumn
                nameOfDay: "Poniedziałek"
            }
            Day {
                id: tuesdayColumn
                nameOfDay: "Wtorek"
            }
            Day {
                id: wedensdayColumn
                nameOfDay: "Środa"
            }
            Day {
                id: thursdayColumn
                nameOfDay: "Czwartek"
            }
            Day {
                id: fridayColumn
                nameOfDay: "Piątek"
            }
            Day {
                id: saturdayColumn
                nameOfDay: "Sobota"
            }
            Day {
                id: sundayColumn
                nameOfDay: "Niedziela"
            }
        }
    }
    footer: Rectangle {
        id: footer
        color: "lightgray"
        height: 20
        width: parent.width
        Text {
            anchors.centerIn: parent
            text: qsTr("FOOTER")
        }
    }

    Component.onCompleted: {

    }

}
