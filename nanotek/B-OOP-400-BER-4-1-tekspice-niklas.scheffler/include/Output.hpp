/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Output.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_OUTPUT_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_OUTPUT_HPP

#include "PinManager.hpp"

namespace nts
{
    class Output : public IComponent
    {
    protected:
        Tristate _value;
        PinManager _map;
    public:
        Output();
        ~Output() = default;

        void simulate(std::size_t tick) override;
        Tristate compute(size_t pin = 1) override ;
        void setLink(size_t pin, IComponent &other, size_t otherPin) override ;
        void dump() const override ;

        virtual void display() const;
        virtual void display(std::string const &name) const;
    };
}
#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_OUTPUT_HPP
