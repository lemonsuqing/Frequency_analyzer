#include "Frequency_analyzer.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frequency_analyzer w;
    w.show();
    return a.exec();
}