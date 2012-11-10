#ifndef RPNCALC_H
#define RPNCALC_H

#include <QString>
#include <QStack>

class RPNCalc
{
public:
    RPNCalc();
    ~RPNCalc();
    bool isActionable(QString) const;
    void doAction(QString);
    void calcAdd();
    void calcSubtract();
    QString printStack() const;

private:
    QStack<double> *stack;
};

#endif // RPNCALC_H
