import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


RowLayout{
    height:20
    width:parent.width
    //anchors.BottomAnchor
    TextArea{
        id:textZone1
        Layout.fillHeight: true
        Layout.fillWidth: true
        implicitWidth: 80
        selectByMouse: true
        clip: true //useless ?
        wrapMode : TextEdit.Wrap
        verticalAlignment:TextEdit.AlignBottom      //avec ça le text s'affiche en défilant au fur et à mesure qu'on écrit
        background: Rectangle{color: "turquoise"}
    }
    Button{
        id:bouton1
        Layout.fillWidth: true
        implicitWidth: 20
        text: "Legend"
        onClicked:{
            console.log("MY BUTTON CLICKED")
        }
        //background: Rectangle{color: "chartreuse"}
    }
}

