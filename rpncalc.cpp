#include "rpncalc.h"

#include <QString>
#include <QDebug>

#include <cmath>
using namespace std;

RPNCalc::RPNCalc()
{
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
    else {
        bool ok;
        double val = s.toDouble(&ok);
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

QString RPNCalc::printStack() const
{
    QString s;
    for(int i = 0; i < stack->size(); ++i) {
        s += QString::number(stack->at(i));
        s += "\n";
    }
    return s;
}

