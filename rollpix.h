#ifndef ROLLPIX_H
#define ROLLPIX_H

#include <QWidget>
#include <QPainter>//绘制类
#include <QPaintEvent>//绘制事件
#include <QTimerEvent>//定时器事件
#include <QDirIterator>//路径

class rollpix : public QWidget
{
    Q_OBJECT
public:
    explicit rollpix(QWidget* parent = nullptr);
    virtual void paintEvent(QPaintEvent* event);//绘画事件
    virtual void timerEvent(QTimerEvent* event);//定时器事件
    void setBackGroundDir(const QString& dir);//获取背景图的位置
private:
    QPixmap pix;//图像类
    QStringList imagePaths;//文件路径

signals:

public slots:
};

#endif // ROLLPIX_H
