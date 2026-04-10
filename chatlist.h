#ifndef CHATLIST_H
#define CHATLIST_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QListWidgetItem>

namespace Ui
{
class chatlist;
}

class chatlist : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatlist(QWidget* parent = nullptr);
    ~chatlist();

    void listshow();
private slots:
    void on_listWidget_itemClicked(QListWidgetItem* item);

private:
    Ui::chatlist* ui;
};

#endif // CHATLIST_H
