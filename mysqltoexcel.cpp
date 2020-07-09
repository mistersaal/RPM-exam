#include "mysqltoexcel.h"
#include <QDebug>

using namespace std;

MySqlToExcel::MySqlToExcel(QWidget *parent) : QMainWindow(parent)
{
    db = new Database("QMYSQL", "genetus.ru", 51820, "exam_user", "exam_pass", "exam");
    excel = new ExcelTable("C:\\Users\\miste\\Desktop\\dump.xlsx");
}

MySqlToExcel::~MySqlToExcel()
{
    delete db;
    delete excel;
}

void MySqlToExcel::dump()
{
    QStringList row;
    QString table = db->getTables()[0];
    row = db->getFields(table);
    int y = 1;
    excel->writeRow(row, y++);
    QSqlQuery query = db->getQuery(table);
    while (query.next()) {
        for (int i = 1; i <= query.record().count(); i++) {
            excel->writeCell(query.value(i-1).toString(), y, i);
        }
        y++;
    }
    excel->saveTable();
}
