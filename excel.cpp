#include "excel.h"

ExcelTable::ExcelTable(QString path)
{
    workbook = workbooks->querySubObject("Open(const QString&)", path);
    mSheets = workbook->querySubObject("Sheets");
    QAxObject* sheet = mSheets->querySubObject("Item(int)", 1);
    QString name = sheet->dynamicCall("Name()").toString();
    statSheet = mSheets->querySubObject("Item(const QVariant&)", QVariant(name));
}

void ExcelTable::writeCell(QString value, int y, int x)
{
    cell = statSheet->querySubObject("Cells(QVariant,QVariant)", y, x);
    cell->setProperty("Value", QVariant(value));
}

void ExcelTable::writeRow(QStringList list, int y)
{
    int i = 1;
    for (QString cell : list) {
        writeCell(cell, y, i);
        i++;
    }
}

void ExcelTable::saveTable()
{
    workbook->dynamicCall("Save()");
}

ExcelTable::~ExcelTable()
{
    delete cell;
    delete statSheet;
    delete mSheets;
    delete workbook;
    delete workbooks;
    mExcel->dynamicCall("Quit()");
    delete mExcel;
}
