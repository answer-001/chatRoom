#include "tcpserver.h"
#include "ui_tcpserver.h"

TcpServer::TcpServer(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    server = new QTcpServer;
    server->listen(QHostAddress::Any, 8080);
    if(server->isListening())
    {
        QMessageBox::information(this, "监听提示", "监听服务已启动");
    }
    connect(server, &QTcpServer::newConnection, this, &TcpServer::new_Client);
}

TcpServer::~TcpServer()
{
    delete ui;
    delete server;
}

void TcpServer::new_Client()
{
    QTcpSocket* socket = server->nextPendingConnection();
    fileName.clear();
    fileSize = 0;
    acceptSize = 0;
    connect(socket, &QTcpSocket::readyRead, this, &TcpServer::read_Data);
}

void TcpServer::read_Data()
{
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    if(fileSize == 0)
    {
        QByteArray info = socket->readAll();
        QDataStream stream(&info, QIODevice::ReadOnly);
        stream >> fileSize >> fileName;
        ui->label->setText(fileName);
        ui->progressBar->setMaximum(fileSize);
        file.setFileName("../Qt06_02/file/" + fileName);
        file.open(QIODevice::WriteOnly);
    }

    if(fileSize > 0 && acceptSize != fileSize)
    {
        QByteArray array = socket->readAll();
        file.write(array);
        acceptSize += array.size();
        ui->progressBar->setValue(acceptSize);
    }
    if(acceptSize == fileSize)
    {
        file.close();
        QMessageBox::information(this, "提示", "文件接收完成!");
        socket->disconnectFromHost();
    }
}
