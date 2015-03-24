#include "SigmoidActivationFunction.h"
#include "NeuralNetwork.h"

int main() {
    SigmoidActivationFunction func;
    NeuralNetwork nn(8, 8, 8, func);
    nn.FeedForward(std::vector<double>({0, 1, 2, 3}));

    return 0;
}
