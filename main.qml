import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import testObj 1.0

Window {
    //width: 640
    //height: 480
    width:1000
    height:1000
    visible: true
    //Layout.fillHeight: true
    //Layout.fillWidth: true
    title: qsTr("Hello World")


    LayoutsTest{}




    //EMBEDDED PROJECT
    // TestEmbbededDriver{
    //     id :objEmb

    // }

    // GridLayout{
    //     id : layOut1


    //     property int sizeOfAreas:150

    //     anchors.fill:parent
    //     Layout.fillHeight: true
    //     Layout.fillWidth: true



    //     //COMP : SENDER ZIGBEE
    //     Rectangle{
    //         height:150;//sizeOfAreas;
    //         width:150;
    //         color: "orange"

    //         Text{
    //             text: "SENDER ZIGBEE"
    //             anchors.centerIn: parent
    //         }

    //         MouseArea{

    //             anchors.fill:parent
    //             onClicked:{


    //                 objEmb.testGeneratorIQSignals();
    //                 //leClient.askForHolaOrMundo();


    //             }
    //         }
    //     }
    // }

    //NumericInterface{}

}
