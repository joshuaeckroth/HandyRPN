#ifndef RPNWIDGET_H
#define RPNWIDGET_H

#include <QWidget>
#include <QString>

#include "rpncalc.h"

namespace Ui {
class RPNWidget;
}

class RPNWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit RPNWidget(QWidget *parent = 0);
    ~RPNWidget();

private slots:
    void textChanged(QString);
    void specialKey(Qt::Key);
    
private:
    Ui::RPNWidget *ui;
    RPNCalc *calc;

    void updateOutput();
};

#endif // RPNWIDGET_H
