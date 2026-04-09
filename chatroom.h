#ifndef CHATROOM_H
#define CHATROOM_H

#include <QMainWindow>

namespace Ui {
class chatRoom;
}

class chatRoom : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatRoom(QWidget *parent = nullptr);
    ~chatRoom();

private:
    Ui::chatRoom *ui;
};

#endif // CHATROOM_H
