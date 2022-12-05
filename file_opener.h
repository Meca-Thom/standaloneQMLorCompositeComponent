#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <QObject>
#include <QFile>
#include <QByteArray>
#include <QDebug>

class file_opener : public QObject
{
    Q_OBJECT
public:
    explicit file_opener(QObject *parent = nullptr);

public slots:
    void openTheFile(QString filepath){
        QFile file(filepath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

            while (!file.atEnd()) {
                QByteArray line = file.readLine();
                qDebug()<<line;//process_line(line);
            }
    }

    QString openTheFileAndReturnString(QString filepath){
        QFile file(filepath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return "";

            while (!file.atEnd()) {
                QString line = file.readLine();
                return line;
                qDebug()<<line;//process_line(line);
            }
            return "";
    }
signals:

};

#endif // FILE_OPENER_H
