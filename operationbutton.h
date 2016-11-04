#ifndef OPERATIONBUTTON_H
#define OPERATIONBUTTON_H

#include <QPushButton>

class OperationButton : public QPushButton
{
    Q_OBJECT
public:    
    OperationButton(const QString &text, QWidget *parent = Q_NULLPTR);
    virtual QString computeOperation(const QString &lvalue, const QString &rvalue) = 0;

signals:
    void sendThis(OperationButton *);

private slots:
    void emitSendThis(){ emit sendThis(this); }
};

#endif // OPERATIONBUTTON_H
