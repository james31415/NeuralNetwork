#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include "INeuron.h"

class InputNeuron : public INeuron
{
    private:
        virtual double DoActivate(double dInput) const { return dInput; }
        virtual double TypeSpecificDelta() const {
            throw "Should not be getting the delta of InputNeuron.";
        }
};

#endif /* INPUTNEURON_H */

