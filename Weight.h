#ifndef WEIGHT_H
#define WEIGHT_H

class INeuron;

class Weight
{
    public:
        Weight(INeuron* inp, INeuron* out, double dWeight, double dLearningRate = 0.1);

        INeuron* GetInputNeuron() const;
        INeuron* GetOutputNeuron() const;
        double GetWeight() const { return m_dWeight; }

        void ComputeAdjustments();
        void ApplyAdjustments() {
            m_dWeight += m_dAdjustment;
            m_dAdjustment = 0.0;
        }

        void Activate() const;

    private:
        INeuron* m_pInput;
        INeuron* m_pOutput;

        double m_dWeight;
        double m_dAdjustment;
        const double m_dLearningRate;
};

#endif /* WEIGHT_H */

