#include "qjsonparser.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QJsonParser w;
    w.show();
    return a.exec();
}
