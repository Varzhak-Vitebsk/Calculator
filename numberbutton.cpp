#include "numberbutton.h"

NumberButton::NumberButton(QString number, const QString &text, QWidget *parent):QPushButton(text, parent)
{
    this->number = number;
    connect(this, SIGNAL(clicked()), this, SLOT(emitSendNumber()));
}
