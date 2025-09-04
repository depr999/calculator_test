#pragma once

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

    double getCurrentValue() const { return currentValue; }
    double getStoredValue() const { return storedValue; }
    QString getCurrentOperation() const { return currentOperation; }

    void digitPressed(int digit);
    void setOperation(const QString& operation);
    void calculateResult();
    void clear();

private slots:
    void digitClicked();
    void operationClicked();
    void equalClicked();
    void clearClicked();
    void pointClicked();

private:
    Ui::Calculator *ui;
    double currentValue;
    double storedValue;
    QString currentOperation;
    bool waitingForOperand;

    void updateDisplay();
    void reset();
    double calculate(double operand1, double operand2, const QString &operation);
};
