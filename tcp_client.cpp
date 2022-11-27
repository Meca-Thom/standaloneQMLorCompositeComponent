#include "tcp_client.h"


TCP_Client::TCP_Client(QObject *parent)
    : QObject{parent}
{
    m_mySocket = new QTcpSocket(this);

}
