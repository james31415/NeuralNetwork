#include <cmath>
#include "LogisticActivationFunction.h"

double LogisticActivationFunction::Activate(double dInput) const
{
    return 1.0 / (1.0 + std::exp(-dInput));
}

double LogisticActivationFunction::Derivative(double dInput) const
{
    return Activate(dInput) * (1.0 - Activate(dInput));
}
