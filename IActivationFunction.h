#ifndef IACTIVATIONFUNCTION_H
#define IACTIVATIONFUNCTION_H

class IActivationFunction
{
    public:
        virtual double Activate(double dInput) const = 0;
        virtual double Derivative(double dInput) const = 0;
};

#endif /* IACTIVATIONFUNCTION_H */

