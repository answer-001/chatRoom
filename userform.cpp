#include "userform.h"
#include "ui_userform.h"

userForm::userForm(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::userForm)
{
    ui->setupUi(this);
}

userForm::~userForm()
{
    delete ui;
}

//设置共有接口, 配置界面显示数据
void userForm::setUser(QString avatar, QString nickname, QString accout)
{
    //保存用户名和用户账号
    this->nickname = nickname;
    this->account = accout;
    //显示头像
    ui->useravatar->setStyleSheet(QString("border-image:url(:/res/infoico/%1)").arg(avatar));
    //显示昵称
    ui->usernickname->setText(nickname);
    //显示账号
    ui->useraccount->setText(accout);
    //显示时间
    ui->time->setText(QDate::currentDate().toString("yyyy-MM-dd"));
}

QString userForm::getNickname() const
{
    return nickname;
}

QString userForm::getAccount() const
{
    return account;
}
