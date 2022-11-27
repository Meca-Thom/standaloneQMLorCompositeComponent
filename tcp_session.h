#ifndef TCP_SESSION_H
#define TCP_SESSION_H

#include <QObject>
//#include "tcp_server.h"

class TCP_Session: public QObject{
    Q_OBJECT
public:
    explicit TCP_Session(QObject *parent = nullptr);
private:
    //TCP_Server* mTCPserver;

public slots :
    void initConnection();
};
#endif // TCP_SESSION_H
