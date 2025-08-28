import QtQuick 2.15
import QtQuick.Layouts 1.3

//Item {
RowLayout{
    anchors.fill: parent

    width:1000
    height:1000


    //ZONE DE DND
    ColumnLayout{
        //Layout.fillHeight: true
        //Layout.fillWidth: true

        width: 900//parent.width*0.9
        height: parent.height



        //https://stackoverflow.com/questions/47082524/are-dimensions-device-independent-pixels-in-qml


        Item {
            id: root

            //required property string colorKey
            //required property int modelData
            Layout.fillHeight: true
            Layout.fillWidth: true
            // width: parent.width/2
            // height: parent.height/2


            MouseArea {
                id: mouseArea
                /*
                Layout.fillHeight: true
                Layout.fillWidth: true*/
                width: 64
                height: 64

                anchors.centerIn: parent

                drag.target: tile

                onReleased: parent = tile.Drag.target !== null ? tile.Drag.target : root

                Rectangle {
                    id: tile

                    width: 64
                    height: 64
                    anchors {
                        verticalCenter: parent.verticalCenter
                        horizontalCenter: parent.horizontalCenter
                    }

                    color: "blue"//root.colorKey

                    Drag.keys: [ root.colorKey ]
                    Drag.active: mouseArea.drag.active
                    Drag.hotSpot.x: 32
                    Drag.hotSpot.y: 32
                    states: State {
                        when: mouseArea.drag.active
                        AnchorChanges {
                            target: tile
                            anchors {
                                verticalCenter: undefined
                                horizontalCenter: undefined
                            }
                        }
                    }
                }
            }
        }

        // Rectangle{
        //     Layout.fillHeight: true
        //     Layout.fillWidth: true
        //     color: "blue"
        // }


    }
    //GridLayout{


    //TOOLBOX
    ColumnLayout{
        width: 100/*parent.width/10*/
        height: parent.height
        // Layout.fillHeight: true
        //fillHeight: true
        // Layout.fillWidth: true


        //Layout.fillWidth: true
         //width: parent.width/2
         //height: parent.height/2
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "green"
        }

        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "yellow"
        }
    }

    // RowLayout{
    //     Rectangle{
    //         Layout.fillHeight: true
    //         Layout.fillWidth: true
    //         color: "red"
    //     }
    // }
}
//}
