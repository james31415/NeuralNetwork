#include "ILayer.h"
#include "InputLayer.h"
#include "InnerLayer.h"
#include "OutputLayer.h"
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(unsigned int nNumberOfLayers,
                unsigned int nNumberOfInputNeurons,
                unsigned int nNumberOfInnerNeurons,
                unsinged int nNumberOfOutputNeurons) {
    m_Layers.reserve(nNumberOfLayers + 2);
    m_Layers.push_back(new InputLayer(nNumberOfInputNeurons));
    
    for (unsigned int n = 0; n < nNumberOfLayers; ++n) {
        m_Layers.push_back(new InnerLayer(nNumberOfInnerNeurons));
    }

    m_Layers.push_back(new OutputLayer(nNumberOfOutputNeurons));
}

NeuralNetwork::~NeuralNetwork() {
    for (auto&& layer : m_Layers) {
        delete layer;
    }
}
