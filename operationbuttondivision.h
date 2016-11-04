#ifndef OPERATIONBUTTONDIVISION_H
#define OPERATIONBUTTONDIVISION_H
#include "operationbutton.h"

class OperationButtonDivision : public OperationButton
{
public:
    OperationButtonDivision(const QString &text, QWidget *parent = Q_NULLPTR);
    QString computeOperation(const QString &lvalue, const QString &rvalue);
};

#endif // OPERATIONBUTTONDIVISION_H
