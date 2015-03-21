#include "rpncalc.h"

#include <QString>
#include <QDebug>

#include <cmath>
using namespace std;

RPNCalc::RPNCalc()
{
    curFormat = FORMAT_FLOAT;
    stack = new QStack<double>;
}

RPNCalc::~RPNCalc()
{
    delete stack;
}

bool RPNCalc::isActionable(QString s) const
{
    if(s == "+") { return true; }
    if(s == "-") { return true; }
    if(s == "/") { return true; }
    if(s == "*") { return true; }
    if(s == "!") { return true; }
    if(s == "^") { return true; }
    else { return false; }
}

void RPNCalc::doAction(QString s)
{
    if(s == "+") { calcAdd(); }
    else if(s == "-") { calcSubtract(); }
    else if(s == "/") { calcDivide(); }
    else if(s == "*") { calcMultiply(); }
    else if(s == "!") { calcFactorial(); }
    else if(s == "^") { calcPower(); }
    else if(s == "log") { calcLog(); }
    else if(s == "ln") { calcLn(); }
    else if(s == "log10") { calcLog10(); }
    else if(s == "sin") { calcSin(); }
    else if(s == "cos") { calcCos(); }
    else if(s == "tan") { calcTan(); }
    else if(s == "dup")
    {
        if(!stack->isEmpty())
            stack->push(stack->top());
    }
    else if(s == "drop")
    {
        if(!stack->isEmpty())
            stack->pop();
    }
    else if(s == "swap")
    {
        if(stack->size() >= 2)
        {
            double v1 = stack->pop();
            double v2 = stack->pop();
            stack->push(v1);
            stack->push(v2);
        }
    }
    else if(s == "hex")
    {
        curFormat = FORMAT_HEX;
    }
    else if(s == "octal")
    {
        curFormat = FORMAT_OCTAL;
    }
    else if(s == "float")
    {
        curFormat = FORMAT_FLOAT;
    }
    else if(s == "int")
    {
        curFormat = FORMAT_INT;
    }
    else if(s == "binary")
    {
        curFormat = FORMAT_BINARY;
    }
    else {
        bool ok = false;
        double val;
        switch(curFormat)
        {
        case FORMAT_FLOAT:
            val = s.toDouble(&ok);
            break;
        case FORMAT_INT:
            val = (double)s.toInt(&ok);
            break;
        case FORMAT_BINARY:
            val = (double)s.toInt(&ok, 2);
            break;
        case FORMAT_HEX:
            val = (double)s.toInt(&ok, 16);
            break;
        case FORMAT_OCTAL:
            val = (double)s.toInt(&ok, 8);
            break;
        }
        if(ok) {
            stack->push(val);
        } else {
            qDebug() << "Error: " << s;
        }
    }
}

void RPNCalc::calcAdd()
{
    if(stack->size() >= 2)
    {
        double val1 = stack->pop();
        double val2 = stack->pop();
        stack->push(val2 + val1);
    }
}

void RPNCalc::calcSubtract()
{
    if(stack->size() >= 2)
    {
        double val1 = stack->pop();
        double val2 = stack->pop();
        stack->push(val2 - val1);
    }
}

void RPNCalc::calcDivide()
{
    if(stack->size() >= 2)
    {
        double val1 = stack->pop();
        double val2 = stack->pop();
        stack->push(val2 / val1);
    }
}

void RPNCalc::calcMultiply()
{
    if(stack->size() >= 2)
    {
        double val1 = stack->pop();
        double val2 = stack->pop();
        stack->push(val2 * val1);
    }
}

void RPNCalc::calcFactorial()
{
    if(stack->size() >= 1)
    {
        double result = 1.0;
        double val = stack->pop();
        while(val >= 1.0)
        {
            result *= val;
            val -= 1.0;
        }
        stack->push(result);
    }
}

void RPNCalc::calcPower()
{
    if(stack->size() >= 2)
    {
        double val1 = stack->pop();
        double val2 = stack->pop();
        stack->push(pow(val2, val1));
    }
}

void RPNCalc::calcLog()
{
    if(stack->size() >= 1)
    {
        double val = stack->pop();
        stack->push(log2(val));
    }
}

void RPNCalc::calcLn()
{
    if(stack->size() >= 1)
    {
        double val = stack->pop();
        stack->push(log(val));
    }
}

void RPNCalc::calcLog10()
{
    if(stack->size() >= 1)
    {
        double val = stack->pop();
        stack->push(log10(val));
    }
}

void RPNCalc::calcSin()
{
    if(stack->size() >= 1)
    {
        double val = stack->pop();
        stack->push(sin(val));
    }
}

void RPNCalc::calcCos()
{
    if(stack->size() >= 1)
    {
        double val = stack->pop();
        stack->push(cos(val));
    }
}

void RPNCalc::calcTan()
{
    if(stack->size() >= 1)
    {
        double val = stack->pop();
        stack->push(tan(val));
    }
}

QString RPNCalc::printStack() const
{
    QString s;
    QTextStream ts(&s);
    for(int i = 0; i < stack->size(); ++i) {
        switch(curFormat)
        {
        case FORMAT_HEX:
            ts.setIntegerBase(16);
            ts << (int)(stack->at(i));
            break;
        case FORMAT_OCTAL:
            ts.setIntegerBase(8);
            ts << (int)(stack->at(i));
            break;
        case FORMAT_BINARY:
            ts.setIntegerBase(2);
            ts << (int)(stack->at(i));
            break;
        case FORMAT_INT:
            ts.setIntegerBase(10);
            ts << (int)(stack->at(i));
            break;
        case FORMAT_FLOAT:
            ts.setIntegerBase(0);
            ts << stack->at(i);
            break;
        }
        ts << "\n";
    }
    return s;
}

