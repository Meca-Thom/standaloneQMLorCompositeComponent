import QtQuick 2.15
import QtQuick.Layouts 1.3

//Item {
RowLayout{
    anchors.fill: parent
    ColumnLayout{
        Layout.fillHeight: true
        Layout.fillWidth: true
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "blue"
        }}
    GridLayout{            Layout.fillHeight: true
        Layout.fillWidth: true
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "green"
        }}
    RowLayout{
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "red"
        }}
}
//}
