#ifndef OPERATIONBUTTONNEGATE_H
#define OPERATIONBUTTONNEGATE_H
#include "operationbutton.h"

class OperationButtonNegate : public OperationButton
{
public:
    OperationButtonNegate(const QString &text, QWidget *parent = Q_NULLPTR);
    QString computeOperation(const QString &lvalue, const QString &rvalue);
};

#endif // OPERATIONBUTTONNEGATE_H
