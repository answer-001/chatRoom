#include "chatroom.h"
#include "flash.h"
#include <QApplication>
#include <QSplashScreen>//开机动画类
#include <QThread>//线程类 延迟

void ShowFlash(QString filename)
{
    //实现开机动画
    QPixmap pix(filename);//通过路径构建图像对象
    QSplashScreen splash(pix);//利用图像帧对象构建动画
    QFont font = splash.font();//获取动画窗口字体
    font.setPixelSize(30);//设置字体大小
    splash.setFont(font);//设置字体
    splash.showMessage("欢迎来到聊天室!!!", Qt::AlignHCenter | Qt::AlignBottom,
                       Qt::red);//开机动画的文本显示
    splash.show();//设置动画显示
    QThread::sleep(2);//延迟2秒
    //窗口显示
    Flash* w = new Flash;
    w->show();
    splash.finish(w);

}
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    ShowFlash(":/res/flash/flash.jpg");

    return a.exec();
}
