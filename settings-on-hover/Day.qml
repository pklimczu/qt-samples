import QtQuick 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    id: columnLayout
    property string nameOfDay: "weekday"

    spacing: 0
    Layout.fillHeight: true
    DayHeader { itemHeight: 20; color: "darkgray"; itemText: nameOfDay }
    DayItem { id: di1; }
    DayItem { id: di2; visible: check_should_show(columnLayout, this) }
    DayItem { id: di3; visible: check_should_show(columnLayout, this) }
    DayItem { id: di4; visible: check_should_show(columnLayout, this) }
    DayItem { id: di5; hoursSlot: 2; visible: check_should_show(columnLayout, this) }
    DayItem { id: di6; visible: check_should_show(columnLayout, this) }
    DayItem { id: di7; visible: check_should_show(columnLayout, this) }
    DayItem { id: di8; visible: check_should_show(columnLayout, this) }
    DayItem { id: di9; visible: check_should_show(columnLayout, this) }
    DayItem { id: di10; visible: check_should_show(columnLayout, this) }
    DayItem { id: di11; visible: check_should_show(columnLayout, this) }
    DayItem { id: di12; visible: check_should_show(columnLayout, this) }
    DayItem { id: di13; visible: check_should_show(columnLayout, this) }
    DayItem { id: di14; visible: check_should_show(columnLayout, this) }

    function get_position(columnLayout, dayItem) {
        var currentItem = -1;
        for (var i = 0; i < columnLayout.children.length; i++) {
            if (columnLayout.children[i] === dayItem) {
                currentItem = i;
                break;
            }
        }
        return currentItem;
    }

    function check_should_show(columnLayout, dayItem) {
        var shouldShow = true;
        var currentItem = get_position(columnLayout, dayItem);

        if (columnLayout.children[currentItem-1].hoursSlot === 2 ||
                columnLayout.children[currentItem-2].hoursSlot === 3) {
            shouldShow = false;
        }

        return shouldShow;
    }
}
