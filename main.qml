import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //Console_Component{}
    //TCP_Component{}
    //LayoutsTest{}
    MicroServer{} //see if cleanable by using "TCP_Component" instance and customizing it "on the go"
}
