#include <algorithm>
#include "OutputNeuron.h"
#include "OutputLayer.h"

OutputLayer::OutputLayer(unsigned int nNumberOfNeurons, IActivationFunction* funcActivation) {
    for (unsigned int n = 0; n < nNumberOfNeurons; ++n) {
        m_vNeurons.push_back(new OutputNeuron(funcActivation));
    }
}

OutputLayer::~OutputLayer() {
    std::for_each(m_vNeurons.begin(), m_vNeurons.end(), [](OutputNeuron* pNeuron) {
            delete pNeuron;
            });
}

void OutputLayer::Activate() {
    std::for_each(m_vNeurons.begin(), m_vNeurons.end(), [](OutputNeuron* pNeuron) {
            pNeuron->Activate();
            });
}

std::vector<double> OutputLayer::GetOutput() const {
    std::vector<double> output;
    std::for_each(m_vNeurons.begin(), m_vNeurons.end(), [&output](OutputNeuron* pNeuron) {
            output.push_back(pNeuron->GetOutput());
            });
    return output;
}
