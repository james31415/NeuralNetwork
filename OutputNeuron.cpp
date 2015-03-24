#include "OutputNeuron.h"

double OutputNeuron::TypeSpecificDelta() const
{
    return GetOutput() - m_dTarget;
}
