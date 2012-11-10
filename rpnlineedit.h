#ifndef RPNLINEEDIT_H
#define RPNLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

class RPNLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit RPNLineEdit(QWidget *parent = 0);
    
signals:
    void specialKey(Qt::Key);
    
public slots:

protected:
    void keyPressEvent(QKeyEvent *);

    
};

#endif // RPNLINEEDIT_H
