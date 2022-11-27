import QtQuick 2.15
import QtQuick.Layouts 1.3
import tcpServer 1.0
//import tcpSession 1.0

GridLayout{
    anchors.fill:parent
    Layout.fillHeight: true
    Layout.fillWidth: true
    Rectangle{
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "green"
        Rectangle{height:50;width:50;
            anchors.centerIn: parent
            color: "turquoise"
            TcpServer{
                id:leServ
            }
            MouseArea{anchors.fill:parent
                onClicked:{leServ.initConnection()  //newConnection()
                }
            }
        }
    }
}
