import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Particles
import QtQuick.Shapes 1.9

//Item {
RowLayout{
    anchors.fill: parent

    width:1000
    height:1000


    //ZONE DE DND
    ColumnLayout{
        width: 900//parent.width*0.9
        height: parent.height
        //https://stackoverflow.com/questions/47082524/are-dimensions-device-independent-pixels-in-qml

        DropArea {
            id: root
            Layout.fillHeight: true
            Layout.fillWidth: true



            //OBJ DND
            MouseArea {
                id: mouseArea
                width: 64
                height: 64
                anchors.centerIn: parent
                drag.target: tile
                //onReleased: tile.x = 100

                //onReleased: parent = tile.Drag.target !== null ? tile.Drag.target : root

                Rectangle {
                    id: tile
                    width: 64
                    height: 64
                    // anchors {
                    //     verticalCenter: parent.verticalCenter
                    //     horizontalCenter: parent.horizontalCenter
                    // }

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
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "green"

            Rectangle{
                anchors.centerIn: parent
                width: 64
                height: 64
                color: "green"
            }
        }
        Rectangle {
            id: tileBIS
            width: 64
            height: 64
            color: "blue"
        }
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "yellow"
            Rectangle{
                anchors.centerIn: parent
                width: 64
                height: 64
                Canvas {
                        anchors.fill: parent
                        onPaint: {
                            var ctx = getContext("2d");
                            ctx.reset();

                            var centreX = width / 2;
                            var centreY = height / 2;

                            ctx.beginPath();
                            ctx.fillStyle = "red";
                            ctx.moveTo(centreX, centreY);
                            ctx.arc(centreX, centreY, width / 4, 0, Math.PI * 0.5, false);
                            ctx.lineTo(centreX, centreY);
                            ctx.fill();

                            ctx.beginPath();
                            ctx.fillStyle = "red";
                            ctx.moveTo(centreX, centreY);
                            ctx.arc(centreX, centreY, width / 4, Math.PI * 0.5, Math.PI * 2, false);
                            ctx.lineTo(centreX, centreY);
                            ctx.fill();
                        }
                    }

            }
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
