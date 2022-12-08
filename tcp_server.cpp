#include "tcp_server.h"

TCP_Server::TCP_Server(QObject *parent)
    : QTcpServer{parent}
{
    mSocket = nullptr;
    //You can also connect to functors or C++11 lambdas:
    connect(this, &TCP_Server::newConnection, [&](){
        mSocket=nextPendingConnection();
        if(mSocket){
            connect(mSocket, SIGNAL(readyRead()),this, SLOT(writeHolaMundoServTest()));
        }
    }
    );
    //connect (object, signal, slot)
    //ce que j'essaie de dire : quand un byte est à lire j'appelle telle fct


}

void TCP_Server::envia(const QByteArray &test)
{
    //qDebug()<<"T : ";
    if(mSocket){ //pbm n'est pas le socket
        //QTextStream T(mSocket);

        QByteArray block;   //je crée un bloc
        QDataStream out(&block, QIODevice::WriteOnly); //je crée un stream qui pointe sur le début du bloc
//https://forum.qt.io/topic/24264/solved-using-qtcpsocket-write-qbytearray-several-times-only-sends-the-first-time
        out<<test; //je mets mon message dans le stream et donc dans le bloc

        mSocket->write(block); //j'envoie le bloc


        //T<<msj;
//        //qDebug()<<"T : "<<T.readAll();
        //mSocket->flush();
    }

}

void TCP_Server::initConnection()
{
    //J'accepte les connexions de tout type
    //EN faisant cette ligne j'appelle "j'écoute à l'adresse loopback
    //sur le port 5100"
    if(!this->listen(QHostAddress::LocalHost,5100)){
        qDebug()<<"Error"<<this->errorString();
    }
    else{
        qDebug()<<"Servidor Iniciado";
    }
    mSocket=nextPendingConnection();
}

void TCP_Server::writeHolaMundoServTest(){
    qDebug()<<"yo";
    //mSocket->flush();
    QString choice = mSocket->readAll();
    if(choice=="1"){
        mSocket->write("Hola");
    }
    else if(choice=="2"){
        mSocket->write("Mundo");
    }
    else {
        mSocket->write("Otras Cosas");
    }
    //mSocket->flush();
}

void TCP_Server::closeConnection()
{
   this->close();
   qDebug()<<"Servidor Desconectado";
}
