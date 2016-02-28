#include "widget.h"
#include "ui_widget.h"
#include "parser.h"
#include <sstream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->inputLineEdit, SIGNAL(textEdited(QString)), this, SLOT(on_lineEdit_textEdited(QString)));
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::on_lineEdit_textEdited(const QString &arg1)
//{

//}

void Widget::on_inputLineEdit_returnPressed()
{
    try {
        QString output;

        std::stringstream ss(ui->inputLineEdit->text().toLatin1().data());
        Expr expr(ss);
        double ret = expr.getValue();
        if (ret == -999.999) {
            output = QString("NaN");
        }
        else
            output = QString::number(ret);
        ui->outputLineEdit->setText(output);
    }
    catch (std::exception & e) {
        ui->outputLineEdit->setText(QString(e.what()));
    }
}
