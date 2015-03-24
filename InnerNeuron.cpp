#include <algorithm>
#include <numeric>
#include "Weight.h"
#include "InnerNeuron.h"

double InnerNeuron::TypeSpecificDelta() const {
    std::vector<double> w;
    std::for_each(m_vWeights.begin(), m_vWeights.end(), [&w](Weight* v) 
            { w.push_back(v->GetWeight()); });

    std::vector<double> d;
    std::for_each(m_vWeights.begin(), m_vWeights.end(), [&d](Weight* v)
            { d.push_back(v->GetOutputNeuron()->GetDelta()); });

    return std::inner_product(w.begin(), w.end(), d.begin(), 0.0);
}
