#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QObject>

class TCP_Server : public QObject
{
    Q_OBJECT
public:
    explicit TCP_Server(QObject *parent = nullptr);

signals:

};

#endif // TCP_SERVER_H
