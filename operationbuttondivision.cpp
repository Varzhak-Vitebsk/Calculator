#include "operationbuttondivision.h"

OperationButtonDivision::OperationButtonDivision(const QString &text, QWidget *parent):OperationButton(text, parent)
{

}

QString OperationButtonDivision::computeOperation(const QString &lvalue, const QString &rvalue)
{
    QString result;
    (rvalue == "0" || rvalue.isEmpty()) ? result = "Er" : result.setNum((lvalue.toDouble()) / (rvalue.toDouble()));
    return result;
}
