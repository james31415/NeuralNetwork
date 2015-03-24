#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H

#include <vector>

class IActivationFunction;
class OutputNeuron;

class OutputLayer
{
    public:
        OutputLayer(unsigned int nNumberOfNeurons, IActivationFunction* funcActivation);
        ~OutputLayer();
        void Activate();
        std::vector<double> GetOutput() const;

    private:
        std::vector<OutputNeuron*> m_vNeurons;
};

#endif /* OUTPUTLAYER_H */

