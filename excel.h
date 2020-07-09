#ifndef EXCEL_H
#define EXCEL_H


#include <QAxBase>
#include <QAxObject>
#include <QTableWidget>


class ExcelTable
{
public:
    ExcelTable(QString path);
    ~ExcelTable();
    void writeCell(QString value, int x, int y);
    void writeRow(QStringList list, int y);
    void saveTable();

private:
    QAxObject *mExcel = new QAxObject("Excel.Application");
    QAxObject *workbooks = mExcel->querySubObject("Workbooks");
    QAxObject *workbook;
    QAxObject *mSheets;
    QAxObject *statSheet;
    QAxObject *cell;
};

#endif // EXCEL_H
