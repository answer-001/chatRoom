#ifndef CHATROOM_H
#define CHATROOM_H

#include <QMainWindow>

namespace Ui
{
class chatRoom;
}

class chatRoom : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatRoom(QWidget* parent = nullptr);
    ~chatRoom();

    void setChatInfo(QString nickname, QString account);
    void showTable();
private:
    Ui::chatRoom* ui;
    //定于容器存储数据
    QVector<QString> Vectoraccount;
    QVector<QString> Vectornickname;
    //判断是否打开
    bool isShow[10];//判断是否为打开;
};

#endif // CHATROOM_H
