#pragma once

#include <QMainWindow>

// Предварительное объявление класса из UI
namespace Ui {
class Calculator;
}

/**
 * @class Calculator
 * @brief Основной класс калькулятора
 * 
 * Класс реализует простой калькулятор с базовыми
 * арифметическими операциями: сложение, вычитание,
 * умножение и деление.
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

private:
    Ui::Calculator *ui; ///< Указатель на UI форму
    double currentValue; ///< Текущее значение на дисплее
    double storedValue; ///< Сохраненное значение для операций
    QString currentOperation; ///< Текущая операция (+, -, *, /)
    
    /**
     * @brief Обновление дисплея калькулятора
     */
    void updateDisplay();
};