/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4008_ADDER_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4008_ADDER_HPP

#include <string>

#include "../IComponent.hpp"
#include "../PinManager.hpp"
#include "../Gates.hpp"
#include "../Help.hpp"

namespace nts
{
    class adder_4008 : public IComponent
    {
    public:
        adder_4008(std::string const &value);
        ~adder_4008() = default;

        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t
        otherPin) override;
        void dump() const override;

    private:
        std::pair<nts::Tristate, nts::Tristate> computeS1();
        std::pair<nts::Tristate, nts::Tristate> computeS2();
        std::pair<nts::Tristate, nts::Tristate> computeS3();
        std::pair<nts::Tristate, nts::Tristate> computeS4();

        PinManager pins;
    };

}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4008_ADDER_HPP
