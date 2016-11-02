#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <limits>
#include "numberbutton.h"

enum class Operand { LEFT, RIGHT };
enum class OperandPart { INTEGER, FRACTION };

QString OperatorAdd(QString const &lvalue, QString const &rvalue);
QString OperatorNegate(QString const &lvalue, QString const &rvalue);
QString OperatorDivision(QString const &lvalue, QString const &rvalue);
QString OperatorMultiplication(QString const &lvalue, QString const &rvalue);

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
    QGridLayout * layout_operator_buttons;
    QPushButton * button_delete_last;
    QPushButton * button_clear;
    QPushButton * button_division;
    QPushButton * button_multiplication;
    QPushButton * button_negate;
    QPushButton * button_add;
    QPushButton * button_result;
    //-------
    QString left_operand;
    QString right_operand;
    Operand operand;
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
    void operatorAddButtonPush();
    void operatorNegateButtonPush();
    void operatorDivisionButtonPush();
    void operatorMultiplicationButtonPush();    
    void resultButtonPush();
    void deleteLastButtonPush();
    void clearButtonPush();
};
#endif // WIDGET_H
