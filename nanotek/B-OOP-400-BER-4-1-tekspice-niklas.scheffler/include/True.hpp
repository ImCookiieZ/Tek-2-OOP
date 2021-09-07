/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** True.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_TRUE_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_TRUE_HPP

#include "Input.hpp"

namespace nts
{
    class True : public Input
    {
    public:
        True();
        void dump() const override;
        void setValue(Tristate value) override;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_TRUE_HPP
