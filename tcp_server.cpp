#include "tcp_server.h"

TCP_Server::TCP_Server(QObject *parent)
    : QTcpServer{parent}
{

}

void TCP_Server::envia(const QString &msj)
{

    if(mSocket){
        QTextStream T(mSocket);
        T<<msj;
        mSocket->flush();
    }

}

void TCP_Server::initConnection()
{
    //J'accepte les connexions de tout type
    if(!this->listen(QHostAddress::Any)){
        qDebug()<<"Error"<<this->errorString();
    }
    else{
        qDebug()<<"Servidor Iniciado";
    }

}
