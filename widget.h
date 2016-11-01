#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT
    QVBoxLayout * layout_main;
    QHBoxLayout * layout_display;
    QLCDNumber * display;
    QHBoxLayout * layout_buttons;
    QGridLayout * layout_number_buttons;
    QPushButton * button_1;
    QPushButton * button_2;
    QPushButton * button_3;
    QPushButton * button_4;
    QPushButton * button_5;
    QPushButton * button_6;
    QPushButton * button_7;
    QPushButton * button_8;
    QPushButton * button_9;
    QPushButton * button_0;
    QPushButton * button_separator;
    QGridLayout * layout_operator_buttons;
    QPushButton * button_division;
    QPushButton * button_multiplication;
    QPushButton * button_negate;
    QPushButton * button_add;
    QPushButton * button_result;
    double result;
    double operator_number;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
