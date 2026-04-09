#include "rollitem.h"

rollitem::rollitem(QWidget* parent) : QWidget(parent)
{
    //初始化显示起点和启动定时器
    this->x = this->width();//获取屏幕宽度, 从右向左显示
    startTimer(50); //启动定时器 50ms
}
//绘制事件,在窗口上重绘文本内容
void rollitem::paintEvent(QPaintEvent* event)
{
    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(this->text);
    //实例化画板对象
    QPainter painter(this);
    painter.drawText(this->x, this->height() / 2.0, this->text); //重绘文本
    painter.drawText(this->x + textWidth + 50, this->height() / 2.0, this->text); // 绘制两次
}
//定时器事件负责更新显示位置
void rollitem::timerEvent(QTimerEvent* event)
{
    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(this->text);
    this->x--;//从右向左移动
    if(this->x < -textWidth - 50) //越界判断
    {
        this->x += textWidth + 50;// 获取屏幕宽度
    }
    update();//更新定时器
}

void rollitem::setText(const QString& value)
{
    this->text = value;
}
