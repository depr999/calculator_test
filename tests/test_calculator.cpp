// #define CATCH_CONFIG_MAIN
// #include <catch2/catch_test_macros.hpp>
// #include <catch2/catch_session.hpp>
// #include <QApplication>
// #include "../src/Calculator.h"

// // Фикстура для инициализации Qt
// struct QtFixture {
//     QtFixture() {
//         static int argc = 1;
//         static char* argv[] = {(char*)"test", nullptr};
//         app = new QApplication(argc, argv);
//     }
    
//     ~QtFixture() {
//         delete app;
//     }
    
//     QApplication* app;
// };

// TEST_CASE_METHOD(QtFixture, "Calculator Initial State", "[calculator]") {
//     Calculator calc;
    
//     REQUIRE(calc.getCurrentValue() == 0.0);
//     REQUIRE(calc.getStoredValue() == 0.0);
//     REQUIRE(calc.getCurrentOperation().isEmpty());
// }

// TEST_CASE_METHOD(QtFixture, "Digit Input", "[calculator]") {
//     Calculator calc;
    
//     SECTION("Single digit") {
//         calc.digitPressed(5);
//         REQUIRE(calc.getCurrentValue() == 5.0);
//     }
    
//     SECTION("Multiple digits") {
//         calc.digitPressed(1);
//         calc.digitPressed(2);
//         calc.digitPressed(3);
//         REQUIRE(calc.getCurrentValue() == 123.0);
//     }
// }

// TEST_CASE_METHOD(QtFixture, "Arithmetic Operations", "[calculator]") {
//     Calculator calc;
    
//     SECTION("Addition: 2 + 3 = 5") {
//         calc.digitPressed(2);
//         calc.setOperation("+");
//         calc.digitPressed(3);
//         calc.calculateResult();
//         REQUIRE(calc.getCurrentValue() == 5.0);
//     }
    
//     SECTION("Subtraction: 5 - 3 = 2") {
//         calc.digitPressed(5);
//         calc.setOperation("-");
//         calc.digitPressed(3);
//         calc.calculateResult();
//         REQUIRE(calc.getCurrentValue() == 2.0);
//     }
    
//     SECTION("Multiplication: 4 * 5 = 20") {
//         calc.digitPressed(4);
//         calc.setOperation("*");
//         calc.digitPressed(5);
//         calc.calculateResult();
//         REQUIRE(calc.getCurrentValue() == 20.0);
//     }
    
//     SECTION("Division: 10 / 2 = 5") {
//         calc.digitPressed(1);
//         calc.digitPressed(0);
//         calc.setOperation("/");
//         calc.digitPressed(2);
//         calc.calculateResult();
//         REQUIRE(calc.getCurrentValue() == 5.0);
//     }
// }

// TEST_CASE_METHOD(QtFixture, "Clear Operation", "[calculator]") {
//     Calculator calc;
    
//     calc.digitPressed(7);
//     REQUIRE(calc.getCurrentValue() == 7.0);
    
//     calc.clear();
//     REQUIRE(calc.getCurrentValue() == 0.0);
//     REQUIRE(calc.getStoredValue() == 0.0);
//     REQUIRE(calc.getCurrentOperation().isEmpty());
// }

// #define CATCH_CONFIG_MAIN
// #include <catch2/catch_test_macros.hpp>

// // Мокаем Qt компоненты
// class MockQApplication {
// public:
//     MockQApplication(int &argc, char **argv) {}
//     int exec() { return 0; }
// };

// // Подменяем реальные классы на моки
// #define QApplication MockQApplication
// #define QMainWindow void

// // Теперь подключаем наш код
// #include "../src/CalculatorLogic.h"

// // Возвращаем оригинальные имена
// #undef QApplication
// #undef QMainWindow

// TEST_CASE("CalculatorLogic operations", "[logic]") {
//     CalculatorLogic calc;
    
//     SECTION("Initial state") {
//         REQUIRE(calc.getCurrentValue() == 0.0);
//     }
    
//     SECTION("Digit input") {
//         calc.pressDigit(5);
//         REQUIRE(calc.getCurrentValue() == 5.0);
//     }
    
//     SECTION("Addition") {
//         calc.pressDigit(2);
//         calc.setOperation("+");
//         calc.pressDigit(3);
//         double result = calc.calculateResult();
//         REQUIRE(result == 5.0);
//     }
// }

#include <catch2/catch.hpp>
#include "../src/Calculator.h"  // Путь к вашему исходному файлу

// Мок для QApplication
class MockQApplication {
public:
    MockQApplication(int &argc, char **argv) {}
    int exec() { return 0; }
};

// Тестируем калькулятор без реального UI
TEST_CASE("Calculator logic") {
    Calculator calc;
    
    // Симулируем нажатие кнопок
    calc.digitPressed(2);
    calc.setOperation("+");
    calc.digitPressed(3);
    calc.calculateResult();
    
    SECTION("Addition") {
        REQUIRE(calc.getCurrentValue() == 5.0);
    }
    
    calc.clear();
    calc.digitPressed(5);
    calc.setOperation("-");
    calc.digitPressed(3);
    calc.calculateResult();
    
    SECTION("Subtraction") {
        REQUIRE(calc.getCurrentValue() == 2.0);
    }
}

