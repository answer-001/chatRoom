#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>
#include <QDate>

namespace Ui
{
class userForm;
}

class userForm : public QWidget
{
    Q_OBJECT

public:
    explicit userForm(QWidget* parent = nullptr);
    ~userForm();

    void setUser(QString avatar, QString nickname, QString accout);
    QString getNickname() const;

    QString getAccount() const;

private:
    Ui::userForm* ui;
    QString nickname, account;
};

#endif // USERFORM_H
