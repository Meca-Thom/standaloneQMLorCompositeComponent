import QtQuick 2.15
import QtQuick.Layouts 1.3
import tcpServer 1.0
import tcpClient 1.0
//import tcpSession 1.0
import fileOpener 1.0

GridLayout{
    TcpClient{
        id : leClient
    }
    TcpServer{
        id:leServ
    }
    FileOpener{
        id:utilFO
    }

    property string myFileName: "C:\\Users\\Thomas\\Documents\\GIT\\standaloneQMLorCompositeComponents\\TEST.txt"
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
                    onClicked:{//leClient.writeHolaMundo()
                        //leClient.waitFor();
                        leServ.writeHolaMundoServTest();
                        //leServ.envia(utilFO.openTheFileAndReturnString(myFileName));
                    }
                }
            }
            Rectangle{height:50;width:50;
                color: "pink"
                MouseArea{anchors.fill:parent
                    onClicked:{leClient.connect2Serv();
                        //console.log(utilFO.openTheFileAndReturnString(myFileName));
                    }
                }
            }
            Rectangle{height:50;width:50;
                property string servorState : "red";
                color: servorState

                MouseArea{anchors.fill:parent
                    onClicked:{
                        if(parent.servorState=="red"){leServ.initConnection();parent.servorState="chartreuse"}
                        else if(parent.servorState=="chartreuse"){leServ.closeConnection();parent.servorState="red"}
                    }
                }
            }
        }
    }
}
