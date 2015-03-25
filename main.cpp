#include <iostream>
#include "LinearActivationFunction.h"
#include "NeuralNetwork.h"

int main() {
    LinearActivationFunction func;
    NeuralNetwork nn(2, 2, 2, func);
    nn.FeedForward(std::vector<double>({9, 3}));

    for (auto& v : nn.GetOutputs())
        std::cout << v << std::endl;

    return 0;
}
