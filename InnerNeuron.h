#ifndef INNERNEURON_H
#define INNERNEURON_H

#include <vector>
#include "INeuron.h"

class Weight;

class InnerNeuron : public INeuron
{
    public:
        InnerNeuron(IActivationFunction* funcActivation) : INeuron(funcActivation) {}
    private:
        virtual double TypeSpecificDelta() const;

        std::vector<Weight*> m_vWeights;
};

#endif /* INNERNEURON_H */

