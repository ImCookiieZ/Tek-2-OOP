/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4013_FLIPFLOP_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4013_FLIPFLOP_HPP

#include <string>

#include "../IComponent.hpp"
#include "../PinManager.hpp"
#include "../Gates.hpp"
#include "../Help.hpp"

namespace nts
{
    class flipflop_4013 : public IComponent
    {
    public:
        flipflop_4013(std::string const &value);
        ~flipflop_4013() = default;

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t
        otherPin) override;
        void dump() const override;

        void computeClock();
        Tristate compute1(std::size_t pin);
        Tristate compute2(std::size_t pin);

    private:
        PinManager pins;

        Tristate state1;
        Tristate state2;
        Tristate clockState1;
        Tristate clockState2;
        bool ready;
    };

}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4013_FLIPFLOP_HPP
