#ifndef SQLLITE_H
#define SQLLITE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

class SqlLite
{
public:
    static SqlLite& instance()
    {
        static SqlLite instance; // 只创建一次
        return instance;
    }
    ~SqlLite() = default;
    void DB_init(QString file);
    bool SQL_query(QString sql, QString msg);
    void create_table();
    bool insert_user(QString username, QString password);
    QString login(QString username, QString password);
    bool isUnique(QString sql);
    QString getAvatar(QString username);
    QSqlQuery getAll();
private:
    SqlLite();
    QSqlDatabase DB;

};

#endif // SQLLITE_H
