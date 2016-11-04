#ifndef OPERATIONBUTTONADD_H
#define OPERATIONBUTTONADD_H
#include "operationbutton.h"

class OperationButtonAdd : public OperationButton
{
public:
    OperationButtonAdd(const QString &text, QWidget *parent = Q_NULLPTR);
    QString computeOperation(const QString &lvalue, const QString &rvalue);
};

#endif // OPERATIONBUTTONADD_H
