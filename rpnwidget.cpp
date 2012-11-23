#include <QDebug>
#include <QScrollBar>

#include "rpnwidget.h"
#include "ui_rpnwidget.h"
#include "rpncalc.h"

RPNWidget::RPNWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RPNWidget)
{
    ui->setupUi(this);

    connect(ui->inputbox, SIGNAL(specialKey(Qt::Key)), this, SLOT(specialKey(Qt::Key)));
    connect(ui->inputbox, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));

    calc = new RPNCalc;

    history = new QStack<QString>;

    ui->inputbox->setFocus();
}

RPNWidget::~RPNWidget()
{
    delete ui;
    delete calc;
}

void RPNWidget::textChanged(QString s)
{
    if(calc->isActionable(s))
    {
        calc->doAction(s);
        history->push(s);
        updateOutput();
    }
}

void RPNWidget::specialKey(Qt::Key key)
{
    if(key == Qt::Key_Return)
    {
        calc->doAction(ui->inputbox->text());
        history->push(ui->inputbox->text());
        updateOutput();
    }
    if(key == Qt::Key_Backspace)
    {
        calc->doAction("drop");
        history->push("drop");
        updateOutput();
    }
}

void RPNWidget::updateOutput()
{
    ui->inputbox->clear();
    ui->outputview->setText(calc->printStack());
    QTextCursor c = ui->outputview->textCursor();
    c.movePosition(QTextCursor::End);
    ui->outputview->setTextCursor(c);

    QString histStr;
    for(QStack<QString>::const_iterator it = history->begin(); it != history->end(); ++it) {
        histStr += *it;
        histStr += "\n";
    }
    ui->history->setText(histStr);
}
