/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** InputPin.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_INPUTPIN_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_INPUTPIN_HPP

#include "Pin.hpp"

namespace nts
{
    class InputPin final : public Pin
    {
    private:
        nts::Tristate _actualState;
        bool _resultIsCalculated;
    public:
        InputPin(IComponent *compo, size_t pin);
        ~InputPin() = default;

        void link(IComponent &other, size_t otherPin) override;
        Tristate compute() override ;
        void reset() override ;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_INPUTPIN_HPP
