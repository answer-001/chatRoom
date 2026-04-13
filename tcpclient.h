#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDateTime>
#include <QNetworkAddressEntry>
#include <QFileDialog>

namespace Ui
{
class tcpClient;
}

class tcpClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit tcpClient(QWidget* parent = nullptr);
    ~tcpClient();

private slots:
    void on_connect_clicked();

    void on_getIp_clicked();

    void on_pushButton_clicked();

    void send_info();
    void send_file();
private:
    Ui::tcpClient* ui;
    QTcpSocket* socket;
    QFile file;
    QString fileName;
    qint64 fileSize = 0;
    qint64 sendSize = 0;
};

#endif // TCPCLIENT_H
