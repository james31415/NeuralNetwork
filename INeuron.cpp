#include "IActivationFunction.h"
#include "INeuron.h"

double INeuron::GetDelta() const {
    double dDelta = TypeSpecificDelta();
    dDelta *= m_funcActivation->Derivative(m_dInput);

    return dDelta;
}

double INeuron::Activate() {
    m_dOutput = DoActivate(m_dInput);
    return m_dOutput;
}

double INeuron::DoActivate(double dInput) const
{
    return m_funcActivation->Activate(dInput);
}
