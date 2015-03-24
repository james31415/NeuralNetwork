#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "boost/multi_array.hpp"
#include "IActivationFunction.h"

class NeuralNetwork {
    public:
        NeuralNetwork(unsigned int nNumberOfInputNeurons,
                unsigned int nNumberOfHiddenNeurons,
                unsigned int nNumberOfOutputNeurons,
                IActivationFunction& funcActivation);

        void FeedForward(const std::vector<double>& Input);

    private:
        void InitializeWeights();

        std::vector<double> m_vInputNeurons;
        std::vector<double> m_vHiddenNeurons;
        std::vector<double> m_vOutputNeurons;

        boost::multi_array<double, 2> m_vvInputHiddenWeights;
        boost::multi_array<double, 2> m_vvHiddenOutputWeights;

        IActivationFunction& m_funcActivation;
};
#endif /* NEURALNETWORK_H */

