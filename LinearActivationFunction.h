#ifndef LINEARACTIVATIONFUNCTION_H
#define LINEARACTIVATIONFUNCTION_H

#include "IActivationFunction.h"

class LinearActivationFunction : public IActivationFunction {
    public:
        virtual double Activate(double dInput) { return dInput; }
        virtual double Derivative(double) { return 1.0; }
};

#endif /* LINEARACTIVATIONFUNCTION_H */

