#include <algorithm>
#include <iostream>
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(unsigned int nNumberOfInputNeurons,
        unsigned int nNumberOfHiddenNeurons,
        unsigned int nNumberOfOutputNeurons,
        IActivationFunction& funcActivation)
    : m_vInputNeurons(nNumberOfInputNeurons)
    , m_vHiddenNeurons(nNumberOfHiddenNeurons)
    , m_vOutputNeurons(nNumberOfOutputNeurons)
    , m_vvInputHiddenWeights(boost::extents[nNumberOfInputNeurons][nNumberOfHiddenNeurons])
    , m_vvHiddenOutputWeights(boost::extents[nNumberOfHiddenNeurons][nNumberOfOutputNeurons])
    , m_funcActivation(funcActivation)
{}

void NeuralNetwork::InitializeWeights() {}
void NeuralNetwork::FeedForward(const std::vector<double>& input) {
    auto& fA = m_funcActivation;
    std::for_each(input.begin(), input.end(), [&fA](double d) {
            std::cout << fA.Activate(d) << " "
            << fA.Derivative(d) << std::endl; });
}

