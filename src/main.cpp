#include "Calculator.h"
#include <QApplication>

/**
 * @mainpage Calculator Application
 * @brief Простой калькулятор на Qt

 * Это тестовое приложение для изучения:
 * - Qt framework
 * - CMake сборки
 * - Doxygen документации
 * 
 * @author Zhekabaunty
 * @version 2.0
 */

/**
 * @brief Точка входа в приложение
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код завершения приложения
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.show();
    return app.exec();
}