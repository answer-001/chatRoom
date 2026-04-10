#include "chatroom.h"
#include "ui_chatroom.h"

chatRoom::chatRoom(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::chatRoom)
{
    ui->setupUi(this);
}

chatRoom::~chatRoom()
{
    delete ui;
}
//设置显示内容
void chatRoom::showTable()
{
    //清空
    ui->message->clear();
    //设置对应标题
    ui->message->setHorizontalHeaderItem(0, new QTableWidgetItem("账号"));
    ui->message->setHorizontalHeaderItem(1, new QTableWidgetItem("昵称"));
    //显示内容
    for(int i = 0; i < Vectoraccount.size(); i++)
    {
        ui->message->setItem(i, 0, new QTableWidgetItem(Vectoraccount[i]));
        ui->message->setItem(i, 1, new QTableWidgetItem(Vectornickname[i]));
    }
}

//保存数据
void chatRoom::setChatInfo(QString account, QString nickname)
{
    Vectoraccount.push_back(account);
    Vectornickname.push_back(nickname);
    showTable();
}
