#include "Horner.h"

double Horner::horner(double kf[], int n, double x)
{
    double result = kf[0];
    for (int i = 1; i <= n; ++i)
    {
        result = result * x + kf[i];
    }
    return result;
}
