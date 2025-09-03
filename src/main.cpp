#include "Calculator.h"
#include <QApplication>

/**
 * @mainpage Qt Calculator Documentation
 * @brief Документация калькулятора на Qt
 * 
 * 
 * ## Сборка и запуск
 * \code
 * mkdir build && cd build
 * cmake .. && make
 * ./src/Calculator
 * \endcode
 * 
 * ## Тестирование
 * \code
 * ./tests/CalculatorLogicTests
 * \endcode
 * 
 * @author Евгений Палыч
 * @version 2.0
 * @date 2025
 */

/**
 * @brief Точка входа в приложение
 * 
 * Создает и запускает Qt приложение с калькулятором.
 * 
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код завершения приложения
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.setWindowTitle("Qt Calculator");
    calculator.show();
    return app.exec();
}