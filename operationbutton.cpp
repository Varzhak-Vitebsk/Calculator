#include "operationbutton.h"

OperationButton::OperationButton(const QString &text, QWidget *parent):QPushButton(text, parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(emitSendThis()));
}
