#ifndef ROLLITEM_H
#define ROLLITEM_H

#include <QWidget>
#include <QPainter>//绘制类
#include <QPaintEvent>//绘制事件
#include <QTimerEvent>//定时器事件

class rollitem : public QWidget
{
    Q_OBJECT
public:
    explicit rollitem(QWidget* parent = nullptr);
    virtual void paintEvent(QPaintEvent* event);//绘画事件
    virtual void timerEvent(QTimerEvent* event);//定时器事件
    void setText(const QString& value);//设置文本
private:
    int x;//显示起点横坐标
    QString text; //显示内容

signals:

public slots:
};

#endif // ROLLITEM_H
