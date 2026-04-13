#include "tcpclient.h"
#include "ui_tcpclient.h"

tcpClient::tcpClient(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::tcpClient)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
    ui->ip->setText("192.168.0.105");
    ui->port->setText("8080");
    connect(socket, &QTcpSocket::connected, this, &tcpClient::send_info);
    connect(socket, &QTcpSocket::bytesWritten, this, &tcpClient::send_file);
}

tcpClient::~tcpClient()
{
    delete ui;
    delete socket;
}

void tcpClient::on_connect_clicked()
{
    QString ip = ui->ip->text();
    QString port = ui->port->text();
    socket->connectToHost(ip, port.toUShort());
    connect(socket, &QTcpSocket::connected, [this]
    {
        qDebug() << QTime::currentTime().toString("hh:mm:ss");
        QMessageBox::information(this, "服务端连接提示", "连接成功, 准备通信");
    });
}

void tcpClient::send_info()
{
    QFileInfo info(ui->lineEdit->text());
    fileName = info.fileName();
    fileSize = info.size();
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream << fileSize << fileName;
    ui->progressBar->setMaximum(fileSize);
    file.setFileName(ui->lineEdit->text());
    file.open(QIODevice::ReadOnly);
    socket->write(array);
}

void tcpClient::send_file()
{
    qDebug() << sendSize;
    if(sendSize < fileSize)
    {
        QByteArray array = file.read(1024 * 10);
        socket->write(array);
        sendSize += array.size();
        ui->progressBar->setValue(sendSize);
    }
    else
    {
        QMessageBox::information(this, "提示", "文件传输完成!");
        //        socket->disconnectFromHost();
        file.close();
    }

}

void tcpClient::on_getIp_clicked()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface interface, interfaces)
    {
        if(interface.flags().testFlag(QNetworkInterface::IsUp)
                && interface.flags().testFlag(QNetworkInterface::IsRunning)
                && !interface.flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            QList<QNetworkAddressEntry> entrys = interface.addressEntries();
            foreach(QNetworkAddressEntry entry, entrys)
            {
                if(entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
                {
                    if(interface.humanReadableName() == "以太网")
                    {
                        ui->ip->setText(entry.ip().toString());
                    }
                }
            }
        }
    }
}

void tcpClient::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择文件上传");
    if(!filePath.isEmpty())
    {
        ui->lineEdit->setText(filePath);
        ui->lineEdit->setCursorPosition(0);
    }
}
