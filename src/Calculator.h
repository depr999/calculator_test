#pragma once

#include <QMainWindow>

namespace Ui {
class Calculator;
}

/**
 * @class Calculator
 * @brief Калькулятор с базовыми арифметическими операциями
 * 
 * Поддерживает сложение, вычитание, умножение, деление,
 * очистку и вычисление результата.
 */
class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор калькулятора
     * @param parent Родительский виджет
     */
    explicit Calculator(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор калькулятора
     */
    ~Calculator();

private slots:
    /**
     * @brief Обработчик нажатия цифровых кнопок (0-9)
     */
    void digitClicked();
    
    /**
     * @brief Обработчик нажатия кнопок операций (+, -, *, /)
     */
    void operationClicked();
    
    /**
     * @brief Обработчик нажатия кнопки равно (=)
     */
    void equalClicked();
    
    /**
     * @brief Обработчик нажатия кнопки очистки (C)
     */
    void clearClicked();
    
    /**
     * @brief Обработчик нажатия кнопки точки (.)
     */
    void pointClicked();

private:
    Ui::Calculator *ui; ///< Указатель на UI форму
    double currentValue; ///< Текущее значение на дисплее
    double storedValue; ///< Сохраненное значение для операций
    QString currentOperation; ///< Текущая операция (+, -, *, /)
    bool waitingForOperand; ///< Флаг ожидания нового операнда
    
    /**
     * @brief Обновление текста на дисплее
     */
    void updateDisplay();
    
    /**
     * @brief Сброс калькулятора в初始状态
     */
    void reset();
    
    /**
     * @brief Выполнение математической операции
     * @param operation Символ операции (+, -, *, /)
     * @return Результат операции
     */
    double calculate(double operand1, double operand2, const QString &operation);
};