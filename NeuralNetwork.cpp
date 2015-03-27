#include <algorithm>
#include <iostream>
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(unsigned int nNumberOfInputNeurons,
        unsigned int nNumberOfHiddenNeurons,
        unsigned int nNumberOfOutputNeurons,
        IActivationFunction& funcActivation)
    : m_vInputNeurons(nNumberOfInputNeurons + 1, 0.0)
    , m_vHiddenNeurons(nNumberOfHiddenNeurons + 1, 0.0)
    , m_vOutputNeurons(nNumberOfOutputNeurons, 0.0)
    , m_vvInputHiddenWeights(boost::extents[nNumberOfInputNeurons + 1][nNumberOfHiddenNeurons])
    , m_vvHiddenOutputWeights(boost::extents[nNumberOfHiddenNeurons + 1][nNumberOfOutputNeurons])
    , m_funcActivation(funcActivation)
{
    m_vInputNeurons[nNumberOfInputNeurons] = -1.0;
    m_vHiddenNeurons[nNumberOfHiddenNeurons] = -1.0;

    InitializeWeights();
}

void NeuralNetwork::InitializeWeights() {
    InitializeArray(m_vvInputHiddenWeights, 1.0);
    InitializeArray(m_vvHiddenOutputWeights, 1.0);
}

void InitializeArray(ArrayType& vvArray, double dValue) {
    std::for_each(vvArray.begin(), vvArray.end(), [dValue](RowTypeReference r) {
            std::fill(r.begin(), r.end(), dValue);
    });
}

void NeuralNetwork::FeedForward(const std::vector<double>& input) {
    typedef ArrayType::index_range range;
    std::copy(input.begin(), input.end(), m_vInputNeurons.begin());

    unsigned int j = 0;
    std::generate_n(m_vHiddenNeurons.begin(), m_vHiddenNeurons.size() - 1, [&]() {
        ArrayType::array_view<1>::type myview = m_vvInputHiddenWeights[boost::indices[range(0, m_vInputNeurons.size())][j]];
        ++j;
        return m_funcActivation.Activate(std::inner_product(m_vInputNeurons.begin(), m_vInputNeurons.end(), myview.begin(), 0.0));
    });

    unsigned int k = 0;
    std::generate(m_vOutputNeurons.begin(), m_vOutputNeurons.end(), [&]() {
        ArrayType::array_view<1>::type myview = m_vvHiddenOutputWeights[boost::indices[range(0, m_vvHiddenOutputWeights.size())][k]];
        ++k;
        return m_funcActivation.Activate(std::inner_product(m_vHiddenNeurons.begin(), m_vHiddenNeurons.end(), myview.begin(), 0.0));
    });
}

