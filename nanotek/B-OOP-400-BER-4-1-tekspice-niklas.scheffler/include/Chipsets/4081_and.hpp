/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4081_AND_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4081_AND_HPP

#include <string>

#include "../IComponent.hpp"
#include "../PinManager.hpp"
#include "../Gates.hpp"
#include "../Help.hpp"

namespace nts
{
    class and_4081 : public IComponent
    {
    public:
        and_4081(std::string const &value);
        ~and_4081() = default;

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t
        otherPin) override;
        void dump() const override;

    private:
        PinManager pins;
    };

}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4081_AND_HPP
