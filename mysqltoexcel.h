#ifndef MYSQLTOEXCEL_H
#define MYSQLTOEXCEL_H

#include <QMainWindow>
#include "database.h"
#include "excel.h"

class MySqlToExcel : public QMainWindow
{
    Q_OBJECT
public:
    explicit MySqlToExcel(QWidget *parent = nullptr);
    ~MySqlToExcel();
    void dump();
private:
    Database *db;
    ExcelTable *excel;

signals:

};

#endif // MYSQLTOEXCEL_H
