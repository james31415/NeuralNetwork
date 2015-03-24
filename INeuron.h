#ifndef INEUROIN_H
#define INEUROIN_H

class IActivationFunction;

class INeuron
{
    public:
        INeuron(IActivationFunction* funcActivation) : m_funcActivation(funcActivation) {}
        virtual ~INeuron() {}
        double GetDelta() const;
        double Activate();
        void PostInput(double dInput) { m_dInput += dInput; }
        void Reset() { m_dInput = 0.0; }
        double GetOutput() const { return m_dOutput; }

    private:
        virtual double DoActivate(double dInput) const;
        virtual double TypeSpecificDelta() const = 0;

        IActivationFunction* m_funcActivation;

        double m_dInput;
        double m_dOutput;
};

#endif /* INEUROIN_H */

