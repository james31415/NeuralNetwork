#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>

class ILayer;

class NeuralNetwork
{
    public:
        NeuralNetwork(unsigned int nNumberOfLayers,
                unsigned int nNumberOfInputNeurons,
                unsigned int nNumberOfInnerNeurons,
                unsinged int nNumberOfOutputNeurons);
        std::vector<double> Activate(std::vector<double> input);

        virtual ~NeuralNetwork();
    private:
        std::vector<ILayer*> m_Layers;
};

#endif /* NEURALNETWORK_H */

