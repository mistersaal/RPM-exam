#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>


class Database
{
public:
    Database(QString type, QString host, int port, QString user, QString pass, QString database);
    QStringList getTables();
    QStringList getFields(QString table);
    QSqlQuery getQuery(QString table);

private:

    QSqlDatabase db;
};

#endif // DATABASE_H
