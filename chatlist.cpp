#include "chatlist.h"
#include "sqlite.h"
#include "userform.h"
#include "chatroom.h"
#include "ui_chatlist.h"

chatlist::chatlist(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::chatlist)
{
    ui->setupUi(this);
    listshow();
}

chatlist::~chatlist()
{
    delete ui;
}

//界面显示好友列表
void chatlist::listshow()
{
    QSqlQuery query = SqlLite::instance().getAll();
    if(query.isSelect())
    {
        while(query.next())
        {
            //实例化空白条目
            QListWidgetItem* item = new QListWidgetItem;
            //将空白条目加入到listwidget
            ui->listWidget->addItem(item);
            //实例化窗口对象
            userForm* form = new userForm;
            //设置窗口内容
            form->setUser(query.value("useravatar").toString(),
                          query.value("usernickname").toString(),
                          query.value("useraccount").toString());
            //设置item的显示高度
            item->setSizeHint(form->size());
            //将item替换自定义窗口对象
            ui->listWidget->setItemWidget(item, form);

        }
    }

}
//单击事件
void chatlist::on_listWidget_itemClicked(QListWidgetItem* item)
{
    //将点击选项item转化为userForm对象
    userForm* form = qobject_cast<userForm*>(ui->listWidget->itemWidget(item));
    if(!form) //判空防止空指针
    {
        return;
    }
    //从userform中获取用户昵称和账号
    QString nickname = form->getNickname();
    QString account = form->getAccount();
    qDebug() << nickname << " " << account;
    //实例化新界面
    chatRoom* w = new chatRoom;
    //传递数据到新界面
    w->setChatInfo(account, nickname);
    //显示界面
    w->show();

}
