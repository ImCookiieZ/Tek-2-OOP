/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4071_OR_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4071_OR_HPP

#include <string>

#include "../IComponent.hpp"
#include "../PinManager.hpp"
#include "../Gates.hpp"
#include "../Help.hpp"

namespace nts
{
    class or_4071 : public IComponent
    {
    public:
        or_4071(std::string const &value);
        ~or_4071() = default;

        Tristate compute(std::size_t pin = 1) override;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t
        otherPin) override;
        void dump() const override;

    private:
        PinManager pins;
    };

}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4071_OR_HPP
