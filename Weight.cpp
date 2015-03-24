#include "INeuron.h"
#include "Weight.h"

Weight::Weight(INeuron* inp, INeuron* out, double dWeight, double dLearningRate)
    : m_pInput(inp)
    , m_pOutput(out)
    , m_dWeight(dWeight)
    , m_dLearningRate(dLearningRate)
{}

INeuron* Weight::GetInputNeuron() const { return m_pInput; }
INeuron* Weight::GetOutputNeuron() const { return m_pOutput; }

void Weight::ComputeAdjustments() {
    m_dAdjustment = -m_dLearningRate;
    m_dAdjustment *= m_pOutput->GetDelta();
    m_dAdjustment *= m_pInput->GetOutput();
}

void Weight::Activate() const {
    m_pOutput->PostInput(m_dWeight * m_pInput->GetOutput());
}

