#include "flash.h"
#include "login.h"
#include "chatroom.h"
#include "ui_flash.h"

Flash::Flash(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Flash)
{
    ui->setupUi(this);
    //实例化动态对象
    movie = new QMovie;
    speech = new QTextToSpeech;
    speech->setVolume(100);//设置音量
    this->setWindowFlag(Qt::FramelessWindowHint);//去掉标题栏
    Showgif(":/res/flash/flash.gif");
}

Flash::~Flash()
{
    delete ui;
    delete movie;
    delete speech;
}
//启动开机动画
void Flash::Showgif(QString filename)
{
    //通过动态图路径构建资源对象
    movie->setFileName(filename);
    //设置动画显示内容大小
    movie->setScaledSize(ui->label->size());
    //设置动画显示位置
    ui->label->setMovie(movie);
    //启动动画
    movie->start();
}

void Flash::on_pushButton_clicked()
{
    //停止动画
    movie->stop();
    speech->say("启动聊天室");
    //登录界面
    Login* l = new Login;
    l->show();
    this->close();
}
