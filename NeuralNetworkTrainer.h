#ifndef NEURALNETWORKTRAINER_H
#define NEURALNETWORKTRAINER_H

#include <vector>
#include "boost/multi_array.hpp"

typedef boost::multi_array<double, 2> ArrayType;

class NeuralNetwork;
class TrainingSet;

class NeuralNetworkTrainer {
    public:
        NeuralNetworkTrainer(NeuralNetwork* nn);
        void Train(const std::vector<TrainingSet>& vtSets);

    private:
        void TrainOne(const TrainingSet& tSet);
        void BackPropagate(const std::vector<double>& vDesiredOutput);
        double GetOutputErrorGradient(double dDesired, double dObserved);
        double GetHiddenErrorGradient(unsigned int j);
        void UpdateWeights();

        NeuralNetwork* m_nn;

        double m_dLearningRate;

        ArrayType m_vvInputHiddenDeltas;
        ArrayType m_vvHiddenOutputDeltas;

        std::vector<double> m_vHiddenErrorGradients;
        std::vector<double> m_vOutputErrorGradients;
};

#endif /* NEURALNETWORKTRAINER_H */

