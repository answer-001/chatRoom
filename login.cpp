#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "chatlist.h"
#include "sqlite.h"

Login::Login(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->widget->setText("聊天室登录界面");
    ui->centralwidget->setBackGroundDir(":/res/bgimg");
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    QString username = ui->username->text(),
            password = ui->password->text();
    QString message = SqlLite::instance().login(username, password);
    if(message == "登录成功!")
    {
        QMessageBox::information(this, "登录提示", message);
        //        this->close();
        chatlist* c = new chatlist(this);
        c->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this, "登录提示",  message);
    }
}

void Login::on_show_pass_clicked(bool checked)
{
    if(checked)
    {
        ui->password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->password->setEchoMode(QLineEdit::Password);
    }
}

void Login::on_regis_clicked()
{
    Register* r = new Register(this);
    r->show();
    this->hide();
}
//获取用户头像
void Login::on_username_editingFinished()
{
    QString username = ui->username->text();
    if(username != "")
    {
        QString message = SqlLite::instance().getAvatar(username);
        QString style = QString("border-image:url(:/res/infoico/%1);border-radius:25px").arg(message);
        ui->icon->setStyleSheet(style);
    }
}
