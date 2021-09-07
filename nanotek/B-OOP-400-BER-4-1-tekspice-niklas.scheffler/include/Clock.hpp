/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Clock.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_CLOCK_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_CLOCK_HPP

#include "Input.hpp"

namespace nts {
    class Clock : public Input
    {
    public:
        Clock(std::string value);

        void dump() const override;
        void reverse();
    };
}
#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_CLOCK_HPP
