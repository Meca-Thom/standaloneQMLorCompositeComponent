#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

//class QTcpSocket;

class TCP_Server :public QTcpServer//, public QObject => unnecessary because QTcpServer already inherits it
{
    Q_OBJECT
public:
    explicit TCP_Server(QObject *parent = nullptr);



private:
    QTcpSocket* mSocket;

signals:

public slots:
    void envia(const QString &msj);
    void initConnection();
    void closeConnection();

};



#endif // TCP_SERVER_H
