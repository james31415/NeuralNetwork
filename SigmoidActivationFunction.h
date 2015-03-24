#ifndef SIGMOIDACTIVATIONFUNCTION_H
#define SIGMOIDACTIVATIONFUNCTION_H

#include <cmath>
#include "IActivationFunction.h"

class SigmoidActivationFunction : public IActivationFunction {
    public:
        virtual double Activate(double dInput) { return 1.0 / (1.0 + std::exp(-dInput)); }
        virtual double Derivative(double dInput) { return Activate(dInput) * (1.0 - Activate(dInput)); }
};

#endif /* SIGMOIDACTIVATIONFUNCTION_H */

