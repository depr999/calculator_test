#include "Calculator.h"
#include "ui_Calculator.h" // Этот файл создаст Qt автоматически

/**
 * @brief Конструктор инициализирует интерфейс и переменные
 */
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , currentValue(0)
    , storedValue(0)
    , currentOperation("")
{
    ui->setupUi(this);
    
    // Пока просто заглушки - реализуете позже
    // connect(ui->pushButton_0, &QPushButton::clicked, this, &Calculator::digitClicked);
    
    updateDisplay();
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::digitClicked()
{
    // Заглушка - реализуете позже
    // QPushButton *button = qobject_cast<QPushButton*>(sender());
    currentValue = currentValue * 10 + 1; // временно для теста
    updateDisplay();
}

void Calculator::operationClicked()
{
    // Заглушка
    currentOperation = "+";
    storedValue = currentValue;
    currentValue = 0;
}

void Calculator::equalClicked()
{
    // Заглушка - простейшее сложение
    if (currentOperation == "+") {
        currentValue = storedValue + currentValue;
    }
    updateDisplay();
}

void Calculator::clearClicked()
{
    currentValue = 0;
    storedValue = 0;
    currentOperation = "";
    updateDisplay();
}

void Calculator::updateDisplay()
{
    ui->display->setText(QString::number(currentValue));
}