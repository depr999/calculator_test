cmake_minimum_required(VERSION 3.16)
project(CalculatorTest VERSION 1.0.0 LANGUAGES CXX)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Включение автоматического moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Поиск Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # Создаем цель для документации
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/docs/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
    message(STATUS "Doxygen found: documentation target 'docs' available")
else()
    message(WARNING "Doxygen not found: documentation will not be generated")
endif()

# Добавление подкаталогов
add_subdirectory(src)

# Установка целевых файлов
install(TARGETS Calculator DESTINATION bin)

# Включение тестов
enable_testing()

# Добавление тестов
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests AND IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    add_subdirectory(tests)
endif()