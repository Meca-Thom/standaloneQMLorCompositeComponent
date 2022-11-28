import QtQuick 2.15
import QtQuick.Layouts 1.3
import tcpServer 1.0
import tcpClient 1.0
//import tcpSession 1.0

GridLayout{
    anchors.fill:parent
    Layout.fillHeight: true
    Layout.fillWidth: true
    Rectangle{
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "green"
        RowLayout{
            anchors.centerIn: parent
            Rectangle{height:50;width:50;
                color: "orange"
                MouseArea{anchors.fill:parent
                    onClicked:{leClient.writeHolaMundo()
                    }
                }
            }
            Rectangle{height:50;width:50;
                color: "pink"
                TcpClient{
                    id : leClient
                }
                MouseArea{anchors.fill:parent
                    onClicked:{leClient.connect2Serv()

                    }
                }
            }
            Rectangle{height:50;width:50;
                color: "turquoise"
                TcpServer{
                    id:leServ
                }
                MouseArea{anchors.fill:parent
                    onClicked:{leServ.initConnection()
                    }
                }
            }
        }
    }
}
