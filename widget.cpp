#include "widget.h"

void Widget::compute()
{
    if(current_operator)
    {
        left_operand.setNum(current_operator(left_operand, right_operand));
        right_operand = "";
        current_operator = Q_NULLPTR;
        display->display(left_operand);
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    layout_main = new QVBoxLayout(this);
    layout_display = new QHBoxLayout();
    display = new QLCDNumber();
    layout_buttons = new QHBoxLayout();
    layout_number_buttons = new QGridLayout();
    button_1 = new NumberButton("1", "&1");
    button_2 = new NumberButton("2", "&2");
    button_3 = new NumberButton("3", "&3");
    button_4 = new NumberButton("4", "&4");
    button_5 = new NumberButton("5", "&5");
    button_6 = new NumberButton("6", "&6");
    button_7 = new NumberButton("7", "&7");
    button_8 = new NumberButton("8", "&8");
    button_9 = new NumberButton("9", "&9");
    button_0 = new NumberButton("0", "&0");
    button_separator = new NumberButton(".", "&.");
    layout_operator_buttons = new QGridLayout();
    button_delete_last = new QPushButton("Delete last");
    button_clear = new QPushButton("Clear");
    button_division = new QPushButton("/");
    button_multiplication = new QPushButton("*");
    button_negate = new QPushButton("-");
    button_add = new QPushButton("+");
    button_result = new QPushButton("=");
    //-----------
    left_operand = right_operand = "";
    operand = Operand::LEFT;
    current_operator = Q_NULLPTR;
    left_operand_part = right_operand_part = OperandPart::INTEGER;
    DISPLAY_MAX_SIZE = 20;
    //-----------
    display->setDigitCount(DISPLAY_MAX_SIZE);
    display->setSmallDecimalPoint(true);
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
    layout_operator_buttons->addWidget(button_delete_last, 0, 0, 1, 1);
    layout_operator_buttons->addWidget(button_clear, 0, 1, 1, 1);
    layout_operator_buttons->addWidget(button_division, 1, 0, 1, 1);
    layout_operator_buttons->addWidget(button_multiplication, 1, 1, 1, 1);
    layout_operator_buttons->addWidget(button_negate, 2, 0, 1, 1);
    layout_operator_buttons->addWidget(button_add, 2, 1, 1, 1);
    layout_operator_buttons->addWidget(button_result, 3, 0, 1, 2);
    //---------
    connect(button_1, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_2, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_3, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_4, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_5, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_6, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_7, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_8, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_9, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_0, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_separator, SIGNAL(sendNumber(QString)), this, SLOT(numberButtonPush(QString)));
    connect(button_division, SIGNAL(clicked()), this, SLOT(operatorDivisionButtonPush()));
    connect(button_multiplication, SIGNAL(clicked()), this, SLOT(operatorMultiplicationButtonPush()));
    connect(button_negate, SIGNAL(clicked()), this, SLOT(operatorNegateButtonPush()));
    connect(button_add, SIGNAL(clicked()), this, SLOT(operatorAddButtonPush()));
    connect(button_result, SIGNAL(clicked()), this, SLOT(resultButtonPush()));
    connect(button_delete_last, SIGNAL(clicked()), this, SLOT(deleteLastButtonPush()));
    connect(button_clear, SIGNAL(clicked()), this, SLOT(clearButtonPush()));

}

Widget::~Widget()
{

}

void Widget::numberButtonPush(QString number)
{
    if(operand == Operand::LEFT)
    {
        if(number != ".")
        {
            left_operand += number;
            display->display(left_operand);
        }else if(left_operand_part == OperandPart::INTEGER)
        {
            if(left_operand.isEmpty()) left_operand += "0";
            left_operand += number;
            left_operand_part = OperandPart::FRACTION;
            display->display(left_operand);
        }
    }else
    {
        if(number != ".")
        {
            right_operand += number;
            display->display(right_operand);
        }else if(right_operand_part == OperandPart::INTEGER)
        {
            if(right_operand.isEmpty()) right_operand += "0";
            right_operand += number;
            right_operand_part = OperandPart::FRACTION;
            display->display(right_operand);
        }
    }
}

void Widget::operatorAddButtonPush()
{
    compute();
    current_operator = &OperatorAdd;
    operand = Operand::RIGHT;
    left_operand_part = OperandPart::INTEGER;
    right_operand_part = OperandPart::INTEGER;
}

void Widget::operatorNegateButtonPush()
{
    compute();
    current_operator = &OperatorNegate;
    operand = Operand::RIGHT;
    left_operand_part = OperandPart::INTEGER;
    right_operand_part = OperandPart::INTEGER;
}

void Widget::operatorDivisionButtonPush()
{
    compute();
    current_operator = &OperatorDivision;
    operand = Operand::RIGHT;
    left_operand_part = OperandPart::INTEGER;
    right_operand_part = OperandPart::INTEGER;
}

void Widget::operatorMultiplicationButtonPush()
{
    compute();
    current_operator = &OperatorMultiplication;
    operand = Operand::RIGHT;
    left_operand_part = OperandPart::INTEGER;
    right_operand_part = OperandPart::INTEGER;
}

void Widget::resultButtonPush()
{
    compute();
    operand = Operand::LEFT;
    left_operand_part = OperandPart::INTEGER;
    right_operand_part = OperandPart::INTEGER;
}

void Widget::deleteLastButtonPush()
{
    if(operand == Operand::LEFT)
    {
        left_operand.chop(1);
        left_operand.isEmpty() ? display->display("0") : display->display(left_operand);
    }else
    {
        right_operand.chop(1);
        right_operand.isEmpty() ? display->display("0") : display->display(right_operand);
    }
}

void Widget::clearButtonPush()
{
    left_operand = right_operand = "";
    operand = Operand::LEFT;
    current_operator = Q_NULLPTR;
    left_operand_part = right_operand_part = OperandPart::INTEGER;
    display->display("0");
}

double OperatorAdd(const QString &lvalue, const QString &rvalue)
{
    return (lvalue.toDouble())+(rvalue.toDouble());
}

double OperatorNegate(const QString &lvalue, const QString &rvalue)
{
    return (lvalue.toDouble())-(rvalue.toDouble());
}

double OperatorDivision(const QString &lvalue, const QString &rvalue)
{
    return (lvalue.toDouble())/(rvalue.toDouble());
}

double OperatorMultiplication(const QString &lvalue, const QString &rvalue)
{
    return (lvalue.toDouble())*(rvalue.toDouble());
}
