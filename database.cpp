#include "database.h"

Database::Database(QString type, QString host, int port, QString user, QString pass, QString database) {
    db = QSqlDatabase::addDatabase(type);
    db.setHostName(host);
    db.setPort(port);
    db.setDatabaseName(database);
    db.setUserName(user);
    db.setPassword(pass);
    db.open();
};

QStringList Database::getTables()
{
    return db.tables();
}

QStringList Database::getFields(QString table)
{
    QSqlRecord record = db.record(table);
    QStringList list;
    int count = record.count();
    for (int i = 0; i < count; i++) {
        list.push_back(record.fieldName(i));
    }
    return list;
}

QSqlQuery Database::getQuery(QString table)
{
    QSqlQuery query(db);
    query.exec("SELECT * FROM " + table + " LIMIT 100");
    return query;
}
