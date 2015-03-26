#include <cstdlib>
#include <iostream>
#include "LinearActivationFunction.h"
#include "TrainingSet.h"
#include "NeuralNetworkTrainer.h"
#include "NeuralNetwork.h"

int main(int, char* argv[]) {
    LinearActivationFunction func;
    NeuralNetwork nn(2, 2, 1, func);
    NeuralNetworkTrainer nt(&nn);

    std::vector<TrainingSet> tSet;
    tSet.push_back({{0, 0}, {0}});
    tSet.push_back({{0, 1}, {1}});
    tSet.push_back({{1, 0}, {1}});
    tSet.push_back({{1, 1}, {0}});

    for (auto& ts : tSet)
    {
        for (auto& d : ts.input)
            std::cout << d << " ";
        std::cout << ": ";
        for (auto& d : ts.output)
            std::cout << d << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < atoi(argv[1]); ++i)
        nt.Train(tSet);

    nn.FeedForward(std::vector<double>({0, 1}));
    for (auto& v : nn.GetOutputs())
        std::cout << v << std::endl;

    return 0;
}
