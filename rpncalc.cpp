#include "rpncalc.h"

#include <QString>
#include <QDebug>

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
    else { return false; }
}

void RPNCalc::doAction(QString s)
{
    if(s == "+") { calcAdd(); }
    else if(s == "-") { calcSubtract(); }
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
        stack->push(val1 + val2);
    }
}

void RPNCalc::calcSubtract()
{
    if(stack->size() >= 2)
    {
        double val1 = stack->pop();
        double val2 = stack->pop();
        stack->push(val1 - val2);
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

