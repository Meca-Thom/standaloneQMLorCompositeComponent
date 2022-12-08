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

    //QIODevice::bytesAvailable() ;
public slots:

    void initConnection();
    void closeConnection();
    //fonction qui teste d'écrire hola mundo dans le socket pour voir si le client recoit
    //quand le serveur envoie ça fait crash => sol voir obsidian & voir constructeur
    void writeHolaMundoServTest();

    //Fonction qui prends en entrée un byte array et le mets dans le socket
    void envia(const QByteArray &msj);



};



#endif // TCP_SERVER_H
