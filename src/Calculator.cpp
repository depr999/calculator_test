#include "Calculator.h"
#include "ui_Calculator.h"
#include <QPushButton>
#include <QDebug>

/**
 * @brief Конструктор инициализирует интерфейс и переменные
 */
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , currentValue(0)
    , storedValue(0)
    , currentOperation("")
    , waitingForOperand(true)
{
    ui->setupUi(this);
    
    // Устанавливаем начальное значение
    updateDisplay();
    
    // Подключаем цифровые кнопки (0-9)
    for (int i = 0; i <= 9; ++i) {
        QString buttonName = QString("pushButton_%1").arg(i);
        QPushButton *button = findChild<QPushButton*>(buttonName);
        if (button) {
            connect(button, &QPushButton::clicked, this, &Calculator::digitClicked);
        }
    }
    
    // Подключаем кнопки операций - используем правильные имена
    connect(ui->pushButton_plus, &QPushButton::clicked, this, &Calculator::operationClicked);
    connect(ui->pushButton_minus, &QPushButton::clicked, this, &Calculator::operationClicked);
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, &Calculator::operationClicked);
    connect(ui->pushButton_divide, &QPushButton::clicked, this, &Calculator::operationClicked);
    
    // Подключаем остальные кнопки
    connect(ui->pushButton_equals, &QPushButton::clicked, this, &Calculator::equalClicked);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &Calculator::clearClicked);
    connect(ui->pushButton_point, &QPushButton::clicked, this, &Calculator::pointClicked);
}

Calculator::~Calculator()
{
    delete ui;
}

/**
 * @brief Обработчик нажатия цифровых кнопок
 */
void Calculator::digitClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString buttonText = button->text();
    int digit = buttonText.toInt();
    
    qDebug() << "Digit clicked:" << buttonText;
    
    if (waitingForOperand) {
        currentValue = digit;
        waitingForOperand = false;
    } else {
        currentValue = currentValue * 10 + digit;
    }
    
    updateDisplay();
}

/**
 * @brief Обработчик нажатия кнопок операций
 */
void Calculator::operationClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString operation = button->text(); // Берем текст с кнопки
    
    if (!currentOperation.isEmpty() && !waitingForOperand) {
        equalClicked();
    }
    
    storedValue = currentValue;
    currentOperation = operation;
    waitingForOperand = true;
    
    qDebug() << "Operation selected:" << operation;
}

/**
 * @brief Обработчик нажатия кнопки равно
 */
void Calculator::equalClicked()
{
    if (currentOperation.isEmpty() || waitingForOperand) return;
    
    currentValue = calculate(storedValue, currentValue, currentOperation);
    currentOperation = "";
    waitingForOperand = true;
    updateDisplay();
}

/**
 * @brief Обработчик нажатия кнопки очистки
 */
void Calculator::clearClicked()
{
    reset();
    updateDisplay();
}

/**
 * @brief Обработчик нажатия кнопки точки
 */
void Calculator::pointClicked()
{
    // Простая реализация - можно улучшить
    if (waitingForOperand) {
        currentValue = 0;
        waitingForOperand = false;
    }
    // Для простоты пока не реализуем десятичные дроби
    updateDisplay();
}

/**
 * @brief Обновление дисплея
 */
void Calculator::updateDisplay()
{
    ui->display->setText(QString::number(currentValue));
}

/**
 * @brief Сброс калькулятора
 */
void Calculator::reset()
{
    currentValue = 0;
    storedValue = 0;
    currentOperation = "";
    waitingForOperand = true;
}

/**
 * @brief Выполнение математической операции
 */
double Calculator::calculate(double operand1, double operand2, const QString &operation)
{
    if (operation == "+") return operand1 + operand2;
    if (operation == "-") return operand1 - operand2;
    if (operation == "*") return operand1 * operand2;
    if (operation == "/") return operand2 != 0 ? operand1 / operand2 : 0;
    return operand2;
}

// МЕТОДЫ ДЛЯ ТЕСТИРОВАНИЯ - ДОБАВЬТЕ ЭТО В КОНЕЦ ФАЙЛА:

/**
 * @brief Симуляция нажатия цифры для тестов
 * @param digit Цифра от 0 до 9
 */
void Calculator::digitPressed(int digit)
{
    if (waitingForOperand) {
        currentValue = digit;
        waitingForOperand = false;
    } else {
        currentValue = currentValue * 10 + digit;
    }
    updateDisplay();
}

/**
 * @brief Установка операции для тестов
 * @param operation Символ операции (+, -, *, /)
 */
void Calculator::setOperation(const QString& operation)
{
    if (!currentOperation.isEmpty() && !waitingForOperand) {
        calculateResult();
    }
    storedValue = currentValue;
    currentOperation = operation;
    waitingForOperand = true;
}

/**
 * @brief Вычисление результата для тестов
 */
void Calculator::calculateResult()
{
    if (currentOperation.isEmpty() || waitingForOperand) return;
    
    currentValue = calculate(storedValue, currentValue, currentOperation);
    currentOperation = "";
    waitingForOperand = true;
    updateDisplay();
}

/**
 * @brief Очистка калькулятора для тестов
 */
void Calculator::clear()
{
    currentValue = 0;
    storedValue = 0;
    currentOperation = "";
    waitingForOperand = true;
    updateDisplay();
}