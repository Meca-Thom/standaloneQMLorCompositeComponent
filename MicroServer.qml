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
    property int sizeOfAreas:150
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

            //COMP : DOWNLOAD FILE
            Rectangle{height:sizeOfAreas;width:sizeOfAreas;
                color: "orange"
                Text{
                    text: "download file"
                    anchors.centerIn: parent
                }

                MouseArea{anchors.fill:parent
                    onClicked:{//leClient.writeHolaMundo()
                        //leClient.waitFor();
                        //leServ.writeHolaMundoServTest();
                        leServ.envia(utilFO.openTheFileAndReturnString(myFileName));    //openFileIntoByteArray
                    }
                }
            }

            //COMP : CONNECT CLIENT
            Rectangle{height:sizeOfAreas;width:sizeOfAreas;
                color: "pink"
                Text{
                    text: "connect client"
                    anchors.centerIn: parent
                }
                MouseArea{anchors.fill:parent
                    onClicked:{leClient.connect2Serv();
                        //console.log(utilFO.openTheFileAndReturnString(myFileName));
                    }
                }
            }

            //COMP : OPEN SERVER
            Rectangle{height:sizeOfAreas;width:sizeOfAreas;
                property string servorState : "red";
                color: servorState
                Text{
                    text: "open server"
                    anchors.centerIn: parent
                }
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
