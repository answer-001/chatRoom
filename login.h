#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui
{
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

private slots:
    void on_login_clicked();
    void on_show_pass_clicked(bool checked);
    void on_regis_clicked();

    void on_username_editingFinished();

private:
    Ui::Login* ui;
};

#endif // LOGIN_H
