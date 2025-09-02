# Находим Catch2
find_package(Catch2 REQUIRED)

# Создаем тестовый исполняемый файл для логики
add_executable(CalculatorLogicTests test_logic.cpp)

# Подключаем заголовочные файлы
target_include_directories(CalculatorLogicTests PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
)

# Подключаем библиотеки
target_link_libraries(CalculatorLogicTests PRIVATE 
    Qt6::Core
    Qt6::Widgets
    Catch2::Catch2WithMain
)

# Добавляем исходные файлы калькулятора
target_sources(CalculatorLogicTests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/Calculator.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

# Включаем автоматическую генерацию UI
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Добавляем тест
add_test(NAME CalculatorLogicTests COMMAND CalculatorLogicTests)