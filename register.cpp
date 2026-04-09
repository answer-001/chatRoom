#include "register.h"
#include "sqlite.h"
#include "ui_register.h"

Register::Register(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    //设置输入框的正则 只允许输入字母和数字
    QRegularExpression regExp("^[a-zA-Z0-9[:punct:]]*$");
    //创建验证器
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(regExp);
    //设置输入框属性
    ui->useraccount->setValidator(validator);
    ui->password->setValidator(validator);
    ui->password_2->setValidator(validator);
    ui->username->setValidator(validator);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    //判断密码是否一致
    if(ui->password->text() == ui->password_2->text())
    {
        //验证用户名是否唯一
        if(SqlLite::instance().isUnique(ui->username->text()))
        {
            QMessageBox::information(this, "注册提示", "用户名已存在!");
            return;
        }
        //准备sql语句
        QString SQL = QString("insert into user(username, useraccount, usernickname, useravatar, password) values("
                              "'%1','%2','%3','%4','%5');")
                      .arg(ui->username->text())
                      .arg(ui->useraccount->text()).arg(ui->usernickname->text())
                      .arg(QString::number(ui->useravatar->currentIndex()) + ".png")
                      .arg(ui->password->text());
        //执行sql
        bool flag = SqlLite::instance().SQL_query(SQL, "注册用户");
        if(flag)
        {
            QMessageBox::information(this, "注册提示", "注册成功");
            this->parentWidget()->show();
            this->close();
        }
        else
        {
            QMessageBox::information(this, "注册提示", "注册失败");
            QList<QLineEdit*> edits = this->findChildren<QLineEdit*>();
            for(QLineEdit* edit : edits)
            {
                edit->clear();
            }
        }
    }
    else
    {
        QMessageBox::information(this, "注册提示", "两次输入密码不一致，请重新输入");
        ui->password->clear();
        ui->password_2->clear();
    }
}

void Register::on_pushButton_2_clicked()
{
    this->parentWidget()->show();
    this->close();
}
