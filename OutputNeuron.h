#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

#include "INeuron.h"

class OutputNeuron : public INeuron
{
    public:
        OutputNeuron(IActivationFunction* funcActivation) : INeuron(funcActivation) {}
        void SetTarget(double dTarget) { m_dTarget = dTarget; }

    private:
        virtual double TypeSpecificDelta() const;

        double m_dTarget;
};

#endif /* OUTPUTNEURON_H */

