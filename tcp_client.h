#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <QHostAddress>

class TCP_Client : public QObject
{
    Q_OBJECT
public:
    explicit TCP_Client(QObject *parent = nullptr);

public slots:
    void connect2Serv()
    {
        m_mySocket->connectToHost(QHostAddress::LocalHost,5100);
        if(QTcpSocket::ConnectedState==m_mySocket->state()){
            qDebug()<<"baba";
        }
    }

    void waitFor(){m_mySocket->waitForBytesWritten(1000);}
    void writeHolaMundo(){
        m_mySocket->write("Hola Mundo");
    }
signals:

private:
    QTcpSocket *m_mySocket;
};

#endif // TCP_CLIENT_H
