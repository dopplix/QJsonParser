#include "qjsonparser.h"

QJsonParser::QJsonParser(QWidget *parent) : QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(treeWidget);
    this->setLayout(layout);
    this->resize(1920,1200);
    connect(textEdit,&QTextEdit::textChanged,[=](){
        QString text = textEdit->toPlainText();
        QJsonObject tempObj = QJsonDocument::fromJson(text.toUtf8()).object();
        QJsonArray tempArr = QJsonDocument::fromJson(text.toUtf8()).array();
        treeWidget->clear();
        if(!tempObj.isEmpty()){
            treeWidget->appendJson(tempObj);
        }else if(!tempArr.isEmpty()){
            treeWidget->appendJson(tempArr);
        }
    });
}
QJsonParser::~QJsonParser(){

}
//Example
//QJsonObject obj;
//obj.insert("one","Hi");
//obj.insert("two","Bye");
//obj.insert("b",false);
//obj.insert("db",3.2);
//obj.insert("int",3);
//obj.insert("nul",QJsonValue::Null);
//QJsonArray arr;
//arr.append(1);
//arr.append("STR");
//QJsonArray arrarr;
//arrarr.append(3);
//arrarr.append(4);
//arrarr.append(5);
//arr.append(arrarr);
//QJsonObject arrsub;
//arrsub.insert("INARR","arr");
//arr.append(arrsub);
//obj.insert("MYARR",arr);
//QJsonObject subObj;
//subObj.insert("sub1","HH");
//subObj.insert("sub2","HHH");
//QJsonObject subsubObj;
//subsubObj.insert("subsub",3);
//subObj.insert("ss",subsubObj);
//obj.insert("three",subObj);
//obj.value("key").isObject();
//qDebug()<<obj;
//treeWidget->appendJson(obj);
