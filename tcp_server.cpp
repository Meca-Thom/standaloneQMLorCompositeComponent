#include "tcp_server.h"

TCP_Server::TCP_Server(QObject *parent)
    : QTcpServer{parent}
{

}

void TCP_Server::envia(const QString &msj)
{
    qDebug()<<"T : ";
    if(mSocket){ //pbm n'est pas le socket
        //QTextStream T(mSocket);
//        T<<msj;
//        //qDebug()<<"T : "<<T.readAll();
//        mSocket->flush();
    }

}

void TCP_Server::initConnection()
{
    //J'accepte les connexions de tout type
    if(!this->listen(QHostAddress::LocalHost,5100)){
        qDebug()<<"Error"<<this->errorString();
    }
    else{
        qDebug()<<"Servidor Iniciado";
    }

}

void TCP_Server::closeConnection()
{
   this->close();
   qDebug()<<"Servidor Desconectado";
}
