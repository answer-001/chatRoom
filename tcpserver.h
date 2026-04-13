#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>

namespace Ui
{
class TcpServer;
}

class TcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget* parent = nullptr);
    ~TcpServer();

private slots:
    void new_Client();
    void read_Data();
private:
    Ui::TcpServer* ui;
    QTcpServer* server;
    QFile file;
    qint64 fileSize;
    QString fileName;
    qint64 acceptSize;
};

#endif // TCPSERVER_H
