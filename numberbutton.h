#ifndef NUMBERBUTTON_H
#define NUMBERBUTTON_H
#include <QPushButton>

class NumberButton : public QPushButton
{
    Q_OBJECT
    QString number;

public:
    NumberButton(QString number, const QString &text, QWidget *parent = Q_NULLPTR);

signals:
    void sendNumber(QString number);
private slots:
    void emitSendNumber(){emit sendNumber(number);}
};

#endif // NUMBERBUTTON_H
