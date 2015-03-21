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
    void calcDivide();
    void calcMultiply();
    void calcFactorial();
    void calcPower();
    void calcLog();
    void calcLn();
    void calcLog10();
    void calcSin();
    void calcCos();
    void calcTan();
    QString printStack() const;

private:
    enum Format { FORMAT_FLOAT, FORMAT_HEX, FORMAT_OCTAL,
                  FORMAT_BINARY, FORMAT_INT };
    Format curFormat;
    QStack<double> *stack;
};

#endif // RPNCALC_H
