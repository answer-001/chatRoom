#include "rollpix.h"

rollpix::rollpix(QWidget* parent) : QWidget(parent)
{
    startTimer(3000);//3秒启动一次
}
//绘制事件 负责更新图像内容
void rollpix::paintEvent(QPaintEvent* event)
{
    //将当前窗口设置画板
    QPainter painter(this);
    //重绘背景图像
    painter.drawPixmap(0, 0, this->pix);
}
//定时事件 负责更新图像对象
void rollpix::timerEvent(QTimerEvent* event)
{
    static int uid = 0;//设置图像的下标
    if(uid == imagePaths.count()) //下标越界
    {
        uid = 0;
    }
    //对图像路径进行遍历, 配置pix类对象
    this->pix.load(imagePaths.at(uid++));//设置显示的内容
    this->pix = pix.scaled(this->size());//设置显示大小
    update();
}
//图像路径获取内部所有的图像文件
void rollpix::setBackGroundDir(const QString& dir)
{
    //图像扫描格式
    QStringList imageFilters = {"*.png", "*.jpg", "*.bmp"};
    //从给定路径dir进行获取
    QDirIterator it(dir, imageFilters, QDir::Files, QDirIterator::Subdirectories);
    //定义图像列表
    while(it.hasNext())
    {
        it.next();//下一个
        imagePaths.append(it.filePath());//文件路径
    }
    QPainter painter(this);
    this->pix.load(":/res/bgimg/UI9.png");
    painter.drawPixmap(rect(), pix);
}

