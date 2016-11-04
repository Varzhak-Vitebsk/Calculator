#include "widget.h"

void Widget::compute()
{
    if(current_operation)
    {
        left_operand = current_operation->computeOperation(left_operand, right_operand);
        right_operand = "";
        current_operation = Q_NULLPTR;
        display->display(left_operand);
        if(left_operand == "Er") left_operand = "0";
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
    button_1 = new NumberButton("1", "1");
    button_1->setShortcut(Qt::Key_1);
    button_2 = new NumberButton("2", "2");
    button_2->setShortcut(Qt::Key_2);
    button_3 = new NumberButton("3", "3");
    button_3->setShortcut(Qt::Key_3);
    button_4 = new NumberButton("4", "4");
    button_4->setShortcut(Qt::Key_4);
    button_5 = new NumberButton("5", "5");
    button_5->setShortcut(Qt::Key_5);
    button_6 = new NumberButton("6", "6");
    button_6->setShortcut(Qt::Key_6);
    button_7 = new NumberButton("7", "7");
    button_7->setShortcut(Qt::Key_7);
    button_8 = new NumberButton("8", "8");
    button_8->setShortcut(Qt::Key_8);
    button_9 = new NumberButton("9", "9");
    button_9->setShortcut(Qt::Key_9);
    button_0 = new NumberButton("0", "0");
    button_0->setShortcut(Qt::Key_0);
    button_separator = new NumberButton(".", ".");
    button_separator->setShortcut(Qt::Key_Comma);
    button_separator->setShortcut(Qt::Key_Period);
    layout_operation_buttons = new QGridLayout();
    button_delete_last = new QPushButton("Delete last");
    button_delete_last->setShortcut(Qt::Key_Backspace);
    button_clear = new QPushButton("Clear");
    button_division = new OperationButtonDivision("/");
    button_division->setShortcut(Qt::Key_Slash);
    button_multiplication = new OperationButtonMultiplication("*");
    button_multiplication->setShortcut(Qt::Key_Asterisk);
    button_negate = new OperationButtonNegate("-");
    button_negate->setShortcut(Qt::Key_Minus);
    button_add = new OperationButtonAdd("+");
    button_add->setShortcut(Qt::Key_Plus);
    button_result = new QPushButton("=");
    button_result->setShortcut(Qt::Key_Equal);
    button_result->setShortcut(Qt::Key_Enter);
    //-----------    
    left_operand = right_operand = "";
    operand = Operand::LEFT;
    current_operation = Q_NULLPTR;
    current_operator = Q_NULLPTR;
    left_operand_part = right_operand_part = OperandPart::INTEGER;
    DISPLAY_MAX_SIZE = 20;
    //-----------
    display->setDigitCount(DISPLAY_MAX_SIZE);
    display->setSmallDecimalPoint(true);
    layout_main->addWidget(display);
    layout_main->addLayout(layout_buttons);
    layout_buttons->addLayout(layout_number_buttons);
    layout_buttons->addLayout(layout_operation_buttons);
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
    layout_operation_buttons->addWidget(button_delete_last, 0, 0, 1, 1);
    layout_operation_buttons->addWidget(button_clear, 0, 1, 1, 1);
    layout_operation_buttons->addWidget(button_division, 1, 0, 1, 1);
    layout_operation_buttons->addWidget(button_multiplication, 1, 1, 1, 1);
    layout_operation_buttons->addWidget(button_negate, 2, 0, 1, 1);
    layout_operation_buttons->addWidget(button_add, 2, 1, 1, 1);
    layout_operation_buttons->addWidget(button_result, 3, 0, 1, 2);
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
    connect(button_division, SIGNAL(sendThis(OperationButton*)), this, SLOT(operationButtonPush(OperationButton*)));
    connect(button_multiplication, SIGNAL(sendThis(OperationButton*)), this, SLOT(operationButtonPush(OperationButton*)));
    connect(button_negate, SIGNAL(sendThis(OperationButton*)), this, SLOT(operationButtonPush(OperationButton*)));
    connect(button_add, SIGNAL(sendThis(OperationButton*)), this, SLOT(operationButtonPush(OperationButton*)));
    connect(button_result, SIGNAL(clicked()), this, SLOT(resultButtonPush()));
    connect(button_delete_last, SIGNAL(clicked()), this, SLOT(deleteLastButtonPush()));
    connect(button_clear, SIGNAL(clicked()), this, SLOT(clearButtonPush()));
    //---------
    this->setMinimumSize(500, 400);
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

void Widget::operationButtonPush(OperationButton *button)
{
    compute();
    current_operation = button;
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
    left_operand = "";
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
