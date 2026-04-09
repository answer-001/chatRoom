#include "chatroom.h"
#include "ui_chatroom.h"

chatRoom::chatRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatRoom)
{
    ui->setupUi(this);
}

chatRoom::~chatRoom()
{
    delete ui;
}
