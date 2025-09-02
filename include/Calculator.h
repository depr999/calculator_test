#pragma once

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

/**
 * @class Calculator
 * @brief Основной класс калькулятора
 * 
 * Простой калькулятор с базовыми арифметическими операциями
 */
class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void digitClicked();
    void operationClicked();
    void equalClicked();
    void clearClicked();

private:
    Ui::Calculator *ui;
    double currentValue;
    double storedValue;
    QString currentOperation;
    
    void updateDisplay();
};