#include <catch2/catch_test_macros.hpp>
#include "../src/Calculator.h"
#include <QApplication>

// Фикстура для инициализации Qt один раз
struct QtTestFixture {
    QtTestFixture() {
        static int argc = 1;
        static char* argv[] = {(char*)"test", nullptr};
        app = new QApplication(argc, argv);
    }
    
    ~QtTestFixture() {
        delete app;
    }
    
    QApplication* app;
};

TEST_CASE_METHOD(QtTestFixture, "Calculator Logic Tests", "[logic]") {
    Calculator calc;
    
    SECTION("Initial state should be zero") {
        REQUIRE(calc.getCurrentValue() == 0.0);
        REQUIRE(calc.getStoredValue() == 0.0);
        REQUIRE(calc.getCurrentOperation().isEmpty());
    }
    
    SECTION("Single digit input") {
        calc.digitPressed(5);
        REQUIRE(calc.getCurrentValue() == 5.0);
    }
    
    SECTION("Multiple digits input") {
        calc.digitPressed(1);
        calc.digitPressed(2);
        calc.digitPressed(3);
        REQUIRE(calc.getCurrentValue() == 123.0);
    }
    
    SECTION("Addition: 2 + 3 = 5") {
        calc.digitPressed(2);
        calc.setOperation("+");
        calc.digitPressed(3);
        calc.calculateResult();
        REQUIRE(calc.getCurrentValue() == 5.0);
    }
    
    SECTION("Subtraction: 5 - 3 = 2") {
        calc.digitPressed(5);
        calc.setOperation("-");
        calc.digitPressed(3);
        calc.calculateResult();
        REQUIRE(calc.getCurrentValue() == 2.0);
    }
    
    SECTION("Multiplication: 4 * 5 = 20") {
        calc.digitPressed(4);
        calc.setOperation("*");
        calc.digitPressed(5);
        calc.calculateResult();
        REQUIRE(calc.getCurrentValue() == 20.0);
    }
    
    SECTION("Division: 10 / 2 = 5") {
        calc.digitPressed(1);
        calc.digitPressed(0);
        calc.setOperation("/");
        calc.digitPressed(2);
        calc.calculateResult();
        REQUIRE(calc.getCurrentValue() == 5.0);
    }
    
    SECTION("Division by zero should return zero") {
        calc.digitPressed(5);
        calc.setOperation("/");
        calc.digitPressed(0);
        calc.calculateResult();
        REQUIRE(calc.getCurrentValue() == 0.0);
    }
    
    SECTION("Clear should reset everything") {
        calc.digitPressed(7);
        calc.setOperation("+");
        calc.digitPressed(3);
        calc.clear();
        
        REQUIRE(calc.getCurrentValue() == 0.0);
        REQUIRE(calc.getStoredValue() == 0.0);
        REQUIRE(calc.getCurrentOperation().isEmpty());
    }
}