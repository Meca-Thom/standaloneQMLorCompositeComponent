import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


RowLayout{
anchors.fill: parent
    TextArea{
        Layout.fillHeight: true
        Layout.fillWidth: true
        implicitWidth: 80
        selectByMouse: true
        clip: true //useless ?
        wrapMode : TextEdit.Wrap
        background: Rectangle{color: "turquoise"}
    }
    Button{
        Layout.fillWidth: true
        implicitWidth: 20
        onClicked:{
            console.log("MY BUTTON CLICKED")
        }
        //background: Rectangle{color: "chartreuse"}
    }
}

