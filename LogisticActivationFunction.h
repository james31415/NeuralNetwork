#ifndef LOGISTICACTIVATIONFUNCTION_H
#define LOGISTICACTIVATIONFUNCTION_H

#include "IActivationFunction.h"

class LogisticActivationFunction : public IActivationFunction
{
    public:
        virtual double Activate(double dInput) const;
        virtual double Derivative(double dInput) const;
};

#endif /* LOGISTICACTIVATIONFUNCTION_H */

