#include "mysqltoexcel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySqlToExcel w;
    w.dump();
    w.show();
    return a.exec();
}
