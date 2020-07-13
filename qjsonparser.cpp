#include "qjsonparser.h"

QJsonParser::QJsonParser(QWidget *parent) : QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(treeWidget);
    this->setLayout(layout);
    this->resize(1920,1200);
    QJsonObject obj;
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
