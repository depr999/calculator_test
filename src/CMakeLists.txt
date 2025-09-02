# Создание исполняемого файла
add_executable(Calculator
    main.cpp
    Calculator.cpp
    Calculator.h
)

# Подключение Qt модулей
target_link_libraries(Calculator
    Qt6::Core
    Qt6::Widgets
)

# Установка целевого файла
install(TARGETS Calculator DESTINATION bin)