#include "sqlite.h"

SqlLite::SqlLite()
{
    DB_init("../chatRoom/Data.db");
    create_table();
}

void SqlLite::DB_init(QString filename)
{
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(filename);
    DB.open();
    if(DB.isOpen())
    {
        qDebug() << "数据库连接成功!";
        qDebug() << DB.tables();
    }
    else
    {
        qDebug() << "数据库连接失败!";
        exit(0);
    }
}

bool SqlLite::SQL_query(QString sql, QString msg)
{
    qDebug() << sql;
    QSqlQuery query;
    bool flag = query.exec(sql);
    if(flag)
    {
        qDebug() << msg + "成功";
    }
    else
    {
        qDebug() << msg + "失败";
    }
    return flag;
}


void SqlLite::create_table()
{
    QString SQL = QString("create table if not exists user(id integer primary key autoincrement,"
                          "username text unique not null,"
                          "useraccount text not null,"
                          "usernickname text not null,"
                          "useravatar text not null,"
                          "password text not null);");

    SQL_query(SQL, "创建用户表格");

}

bool SqlLite::isUnique(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT 1 FROM user WHERE username = ? LIMIT 1");
    query.addBindValue(username);

    if(query.exec() && query.next())
    {
        return true;
    }
    return false;
}

QString SqlLite::getAvatar(QString username)
{
    QString sql = QString("select * from user where username = '%1'")
                  .arg(username);
    QSqlQuery query(sql);
    if(query.next())
    {
        return query.value("useravatar").toString();
    }
}

QString SqlLite::login(QString username, QString password)
{
    QString sql = QString("select * from user where username = '%1'")
                  .arg(username);
    QSqlQuery query(sql);
    if(query.next())
    {
        QString password2 = query.value("password").toString();
        if(password == password2)
        {
            return "登录成功!";
        }
        else
        {
            return "密码错误!";
        }
    }
    else
    {
        return "不存在该用户!";
    }
}


