/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4040_COUNTER_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4040_COUNTER_HPP

#include "../IComponent.hpp"
#include "../PinManager.hpp"
#include "../Clock.hpp"
namespace nts
{
    class counter_4040 final : public IComponent
    {
    private:
        bool _resultIsCalculated;
        PinManager _pins;
        Tristate _previus;
        std::uint16_t _counter;
    public:
        counter_4040(std::string &value);
        void simulate(std::size_t tick) final ;
        void dump() const final ;
        void setLink(size_t pin, IComponent &other, size_t otherPin) final ;
        Tristate compute(size_t pin = 1) final ;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_4040_COUNTER_HPP
