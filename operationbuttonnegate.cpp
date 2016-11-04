#include "operationbuttonnegate.h"

OperationButtonNegate::OperationButtonNegate(const QString &text, QWidget *parent):OperationButton(text, parent)
{

}

QString OperationButtonNegate::computeOperation(const QString &lvalue, const QString &rvalue)
{
    QString result;
    result.setNum((lvalue.toDouble()) - (rvalue.toDouble()));
    return result;
}
