#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "boost/multi_array.hpp"
#include "IActivationFunction.h"

typedef boost::multi_array<double, 2> ArrayType;
typedef typename ArrayType::reference RowTypeReference;

class NeuralNetwork {
    public:
        NeuralNetwork(unsigned int nNumberOfInputNeurons,
                unsigned int nNumberOfHiddenNeurons,
                unsigned int nNumberOfOutputNeurons,
                IActivationFunction& funcActivation);

        void FeedForward(const std::vector<double>& Input);
        std::vector<double>& GetOutputs() { return m_vOutputNeurons; }

    private:
        friend class NeuralNetworkTrainer;

        std::vector<double> m_vInputNeurons;
        std::vector<double> m_vHiddenNeurons;
        std::vector<double> m_vOutputNeurons;

        ArrayType m_vvInputHiddenWeights;
        ArrayType m_vvHiddenOutputWeights;

        IActivationFunction& m_funcActivation;

        void InitializeWeights();
};

void InitializeArray(ArrayType& vvArray, double dValue);

#endif /* NEURALNETWORK_H */

