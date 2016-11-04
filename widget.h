#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <limits>
#include "numberbutton.h"
#include "operationbuttonadd.h"
#include "operationbuttonnegate.h"
#include "operationbuttonmultiplication.h"
#include "operationbuttondivision.h"

enum class Operand { LEFT, RIGHT };
enum class OperandPart { INTEGER, FRACTION };

class Widget : public QWidget
{
    Q_OBJECT
    //typedef std::function <double (const QString&, const QString&)> T;

    QVBoxLayout * layout_main;
    QHBoxLayout * layout_display;
    QLCDNumber * display;
    QHBoxLayout * layout_buttons;
    QGridLayout * layout_number_buttons;
    NumberButton * button_1;
    NumberButton * button_2;
    NumberButton * button_3;
    NumberButton * button_4;
    NumberButton * button_5;
    NumberButton * button_6;
    NumberButton * button_7;
    NumberButton * button_8;
    NumberButton * button_9;
    NumberButton * button_0;
    NumberButton * button_separator;
    QGridLayout * layout_operation_buttons;
    QPushButton * button_delete_last;
    QPushButton * button_clear;
    OperationButtonDivision * button_division;
    OperationButtonMultiplication * button_multiplication;
    OperationButtonNegate * button_negate;
    OperationButtonAdd * button_add;
    QPushButton * button_result;
    //-------
    QString left_operand;
    QString right_operand;
    Operand operand;
    OperationButton * current_operation;
    QString (* current_operator)(const QString&, const QString&);
    OperandPart left_operand_part;
    OperandPart right_operand_part;
    unsigned int DISPLAY_MAX_SIZE;
    //-------
    void compute();

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void numberButtonPush(QString number);        
    void operationButtonPush(OperationButton * button);
    void resultButtonPush();
    void deleteLastButtonPush();
    void clearButtonPush();
};
#endif // WIDGET_H
