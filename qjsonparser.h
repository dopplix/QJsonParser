#ifndef QJSONPARSER_H
#define QJSONPARSER_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDebug>
#include "qjsontreewidget.h"

class QJsonParser : public QWidget{
    Q_OBJECT

public:
    QJsonParser(QWidget *parent = nullptr);
    ~QJsonParser();

private:
    QTextEdit* textEdit = new QTextEdit;
    QJsonTreeWidget* treeWidget = new QJsonTreeWidget;

};
#endif // QJSONPARSER_H
