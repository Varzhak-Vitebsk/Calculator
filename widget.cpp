#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout_main = new QVBoxLayout(this);
    layout_display = new QHBoxLayout();
    display = new QLCDNumber();
    layout_buttons = new QHBoxLayout();
    layout_number_buttons = new QGridLayout();
    button_1 = new QPushButton("1");
    button_2 = new QPushButton("2");
    button_3 = new QPushButton("3");
    button_4 = new QPushButton("4");
    button_5 = new QPushButton("5");
    button_6 = new QPushButton("6");
    button_7 = new QPushButton("7");
    button_8 = new QPushButton("8");
    button_9 = new QPushButton("9");
    button_0 = new QPushButton("0");
    button_separator = new QPushButton(".");
    layout_operator_buttons = new QGridLayout();
    button_division = new QPushButton("/");
    button_multiplication = new QPushButton("*");
    button_negate = new QPushButton("-");
    button_add = new QPushButton("+");
    button_result = new QPushButton("=");
    result = operator_number = 0;
    //-----------
    layout_main->addWidget(display);
    layout_main->addLayout(layout_buttons);
    layout_buttons->addLayout(layout_number_buttons);
    layout_buttons->addLayout(layout_operator_buttons);
    layout_number_buttons->addWidget(button_7, 0, 0, 1, 1);
    layout_number_buttons->addWidget(button_8, 0, 1, 1, 1);
    layout_number_buttons->addWidget(button_9, 0, 2, 1, 1);
    layout_number_buttons->addWidget(button_4, 1, 0, 1, 1);
    layout_number_buttons->addWidget(button_5, 1, 1, 1, 1);
    layout_number_buttons->addWidget(button_6, 1, 2, 1, 1);
    layout_number_buttons->addWidget(button_1, 2, 0, 1, 1);
    layout_number_buttons->addWidget(button_2, 2, 1, 1, 1);
    layout_number_buttons->addWidget(button_3, 2, 2, 1, 1);
    layout_number_buttons->addWidget(button_0, 3, 0, 1, 2);
    layout_number_buttons->addWidget(button_separator, 3, 2, 1, 1);
    layout_operator_buttons->addWidget(button_division, 0, 0, 1, 1);
    layout_operator_buttons->addWidget(button_multiplication, 0, 1, 1, 1);
    layout_operator_buttons->addWidget(button_negate, 1, 0, 1, 1);
    layout_operator_buttons->addWidget(button_add, 1, 1, 1, 1);
    layout_operator_buttons->addWidget(button_result, 2, 0, 1, 2);
}

Widget::~Widget()
{

}
