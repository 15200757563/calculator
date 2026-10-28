#include "arithmetic.h"

Arithmetic::Arithmetic()
{
}
double Arithmetic::calculateAdd(double a, double b)
{
    return a + b;
}
double Arithmetic::calculateSubtract(double a, double b)
{
    return a - b;
}
double Arithmetic::calculateMultiply(double a, double b)
{
    return a * b;
}
double Arithmetic::calculateDivide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        // Handle division by zero error
        return 0; // or some error value
    }
}