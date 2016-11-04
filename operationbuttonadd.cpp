#include "operationbuttonadd.h"

OperationButtonAdd::OperationButtonAdd(const QString &text, QWidget *parent):OperationButton(text, parent)
{

}

QString OperationButtonAdd::computeOperation(const QString &lvalue, const QString &rvalue)
{
    QString result;
    result.setNum((lvalue.toDouble()) + (rvalue.toDouble()));
    return result;
}
