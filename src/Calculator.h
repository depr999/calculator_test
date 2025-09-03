#pragma once

#include <QMainWindow>

namespace Ui {
class Calculator;
}

/**
 * @class Calculator
 * @brief Основной класс калькулятора с графическим интерфейсом
 * 
 * Класс реализует полнофункциональный калькулятор с поддержкой
 * базовых арифметических операций: сложение, вычитание, умножение и деление.
 * Поддерживает ввод многозначных чисел и последовательные вычисления.
 */
class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор калькулятора
     * @param parent Родительский виджет (по умолчанию nullptr)
     */
    explicit Calculator(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор калькулятора
     */
    ~Calculator();

    // Методы для тестирования
    /**
     * @brief Получить текущее значение на дисплее
     * @return Текущее числовое значение
     */
    double getCurrentValue() const { return currentValue; }
    
    /**
     * @brief Получить сохраненное значение для операций
     * @return Сохраненное числовое значение
     */
    double getStoredValue() const { return storedValue; }
    
    /**
     * @brief Получить текущую операцию
     * @return Строка с символом операции (+, -, *, /)
     */
    QString getCurrentOperation() const { return currentOperation; }
    
    /**
     * @brief Симуляция нажатия цифровой кнопки
     * @param digit Цифра от 0 до 9 для ввода
     */
    void digitPressed(int digit);
    
    /**
     * @brief Установка арифметической операции
     * @param operation Символ операции (+, -, *, /)
     */
    void setOperation(const QString& operation);
    
    /**
     * @brief Вычисление результата текущей операции
     */
    void calculateResult();
    
    /**
     * @brief Очистка калькулятора (сброс к начальному состоянию)
     */
    void clear();

private slots:
    /**
     * @brief Обработчик нажатия цифровых кнопок
     */
    void digitClicked();
    
    /**
     * @brief Обработчик нажатия кнопок операций
     */
    void operationClicked();
    
    /**
     * @brief Обработчик нажатия кнопки равно
     */
    void equalClicked();
    
    /**
     * @brief Обработчик нажатия кнопки очистки
     */
    void clearClicked();
    
    /**
     * @brief Обработчик нажатия кнопки точки
     */
    void pointClicked();

private:
    Ui::Calculator *ui;                ///< Указатель на UI форму
    double currentValue;               ///< Текущее значение на дисплее
    double storedValue;                ///< Сохраненное значение для операций
    QString currentOperation;          ///< Текущая операция (+, -, *, /)
    bool waitingForOperand;            ///< Флаг ожидания нового операнда
    
    /**
     * @brief Обновление текста на дисплее
     */
    void updateDisplay();
    
    /**
     * @brief Сброс калькулятора в начальное состояние
     */
    void reset();
    
    /**
     * @brief Выполнение математической операции
     * @param operand1 Первый операнд
     * @param operand2 Второй операнд
     * @param operation Символ операции
     * @return Результат вычисления
     */
    double calculate(double operand1, double operand2, const QString &operation);
};