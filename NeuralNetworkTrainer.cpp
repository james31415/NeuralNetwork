#include <algorithm>
#include "NeuralNetwork.h"
#include "TrainingSet.h"
#include "NeuralNetworkTrainer.h"

NeuralNetworkTrainer::NeuralNetworkTrainer(NeuralNetwork* nn)
    : m_nn(nn) 
    , m_dLearningRate(0.1)
    , m_vvInputHiddenDeltas(boost::extents[m_nn->m_vInputNeurons.size()][m_nn->m_vHiddenNeurons.size()])
    , m_vvHiddenOutputDeltas(boost::extents[m_nn->m_vHiddenNeurons.size()][m_nn->m_vOutputNeurons.size()])
    , m_vHiddenErrorGradients(nn->m_vHiddenNeurons.size())
    , m_vOutputErrorGradients(nn->m_vOutputNeurons.size())
{
    InitializeArray(m_vvInputHiddenDeltas, 0.0);
    InitializeArray(m_vvHiddenOutputDeltas, 0.0);
}

void NeuralNetworkTrainer::Train(const std::vector<TrainingSet>& vpTrainingSets) {
    for (auto& tSet : vpTrainingSets)
        TrainOne(tSet);
}

void NeuralNetworkTrainer::TrainOne(const TrainingSet& tSet) {
    m_nn->FeedForward(tSet.input);
    BackPropagate(tSet.output);
    UpdateWeights();
}

void NeuralNetworkTrainer::BackPropagate(const std::vector<double>& vDesiredOutput) {
    for (unsigned int k = 0; k < m_nn->m_vOutputNeurons.size(); ++k) {
        m_vOutputErrorGradients[k] = GetOutputErrorGradient(vDesiredOutput[k], m_nn->m_vOutputNeurons[k]);

        for (unsigned int j = 0; j < m_nn->m_vHiddenNeurons.size(); ++j) {
            m_vvHiddenOutputDeltas[j][k] += m_dLearningRate * m_nn->m_vHiddenNeurons[j] * m_vOutputErrorGradients[k];
        }
    }

    for (unsigned int j = 0; j < m_nn->m_vHiddenNeurons.size() - 1; ++j) {
        m_vHiddenErrorGradients[j] = GetHiddenErrorGradient(j);

        for (unsigned int i = 0; i < m_nn->m_vInputNeurons.size(); ++i) {
            m_vvInputHiddenDeltas[i][j] += m_dLearningRate * m_nn->m_vInputNeurons[i] * m_vHiddenErrorGradients[j];
        }
    }
}

double NeuralNetworkTrainer::GetOutputErrorGradient(double dDesired, double dObserved) {
    if (dObserved < 0.2)
        dObserved = 0.0;
    else if (dObserved > 0.8)
        dObserved = 1.0;
    else
        dObserved = -1.0;

    return m_nn->m_funcActivation.Derivative(dObserved) * (dDesired - dObserved);
}

double NeuralNetworkTrainer::GetHiddenErrorGradient(unsigned int j) {
    double dSum = 0.0;
    for (unsigned int k = 0; k < m_nn->m_vOutputNeurons.size(); ++k) {
        dSum += m_nn->m_vvHiddenOutputWeights[j][k] * m_vOutputErrorGradients[k];
    }

    return m_nn->m_funcActivation.Derivative(m_nn->m_vHiddenNeurons[j]) * dSum;
}

void NeuralNetworkTrainer::UpdateWeights() {
    for (unsigned int k = 0; k < m_nn->m_vOutputNeurons.size(); ++k) {
        for (unsigned int j = 0; j < m_nn->m_vHiddenNeurons.size(); ++j) {
            m_nn->m_vvHiddenOutputWeights[j][k] += m_vvHiddenOutputDeltas[j][k];
            m_vvHiddenOutputDeltas[j][k] = 0.0;
        }
    }

    for (unsigned int j = 0; j < m_nn->m_vHiddenNeurons.size() - 1; ++j) {
        for (unsigned int i = 0; i < m_nn->m_vInputNeurons.size(); ++i) {
            m_nn->m_vvInputHiddenWeights[i][j] += m_vvInputHiddenDeltas[i][j];
            m_vvInputHiddenDeltas[i][j] = 0.0;
        }
    }
}
