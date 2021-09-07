/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** OutputPin.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_OUTPUTPIN_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_OUTPUTPIN_HPP

#include "Pin.hpp"

namespace nts
{
    class OutputPin final : public Pin
    {
    public:
        OutputPin(IComponent *compo, size_t pin);
        ~OutputPin() = default;

        void link(IComponent &other, size_t otherPin) override;
        Tristate compute() override ;
        void reset() override ;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_OUTPUTPIN_HPP
