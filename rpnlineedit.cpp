#include "rpnlineedit.h"

#include <QDebug>

RPNLineEdit::RPNLineEdit(QWidget *parent) :
    QLineEdit(parent)
{}

void RPNLineEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace && text().isEmpty())
        emit specialKey(Qt::Key_Backspace);
    else if(event->key() == Qt::Key_Return)
        emit specialKey(Qt::Key_Return);
    else
        QLineEdit::keyPressEvent(event);
}
