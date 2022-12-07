#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

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
    //fonction qui teste d'écrire hola mundo dans le socket pour voir si le client recoit
    //quand le serveur envoie ça fait crash
    void writeHolaMundoServTest(){
        //mSocket->flush();
        mSocket->write("Hola Mundo");
        //mSocket->flush();
    }

};



#endif // TCP_SERVER_H
