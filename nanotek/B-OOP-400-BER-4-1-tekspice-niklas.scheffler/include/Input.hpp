/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Input.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_INPUT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_INPUT_HPP

#include "OutputPin.hpp"

namespace nts
{
    class Input : public IComponent
    {
    protected:
        Tristate _value = UNDEFINED;
        Tristate *_nextValue = nullptr;
        OutputPin _outPin;
    public:
        Input(std::string const &value);
        ~Input() = default;

        void simulate(std::size_t tick) override;
        Tristate compute(size_t pin) override final;
        void setLink(size_t pin, IComponent &other, size_t otherPin) override final;
        void dump() const override ;

        virtual Tristate value() const final;
        virtual void setValue(Tristate value);
        void setValue(int value);
        void setValue(std::string const &value);
        virtual void display(std::string const &name) const;

        void checkSet();
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_INPUT_HPP
