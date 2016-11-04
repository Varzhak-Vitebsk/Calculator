#include "operationbuttonmultiplication.h"

OperationButtonMultiplication::OperationButtonMultiplication(const QString &text, QWidget *parent):OperationButton(text, parent)
{

}

QString OperationButtonMultiplication::computeOperation(const QString &lvalue, const QString &rvalue)
{
    QString result;
    result.setNum((lvalue.toDouble()) * (rvalue.toDouble()));
    return result;
}
