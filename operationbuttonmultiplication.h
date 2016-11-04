#ifndef OPERATIONBUTTONMULTIPLICATION_H
#define OPERATIONBUTTONMULTIPLICATION_H
#include "operationbutton.h"

class OperationButtonMultiplication : public OperationButton
{
public:
    OperationButtonMultiplication(const QString &text, QWidget *parent = Q_NULLPTR);
    QString computeOperation(const QString &lvalue, const QString &rvalue);
};

#endif // OPERATIONBUTTONMULTIPLICATION_H
