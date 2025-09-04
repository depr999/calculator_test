#include "Calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator calculator;
    calculator.setWindowTitle("Qt Calculator");
    calculator.show();
    return app.exec();
}
