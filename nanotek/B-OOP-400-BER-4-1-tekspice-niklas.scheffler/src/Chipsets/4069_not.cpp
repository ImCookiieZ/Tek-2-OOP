/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../../include/Chipsets/4069_not.hpp"

nts::not_4069::not_4069(std::string const &value)
{
    pins.addInput(this, 1);
    pins.addOutput(this, 2);
    pins.addInput(this, 3);
    pins.addOutput(this, 4);
    pins.addInput(this, 5);
    pins.addOutput(this, 6);
    pins.addOutput(this, 7);
    pins.addOutput(this, 8);
    pins.addInput(this, 9);
    pins.addOutput(this, 10);
    pins.addInput(this, 11);
    pins.addOutput(this, 12);
    pins.addInput(this, 13);
    pins.addOutput(this, 14);
}

nts::Tristate nts::not_4069::compute(std::size_t pin)
{
    if (pin == 0) {
        pins.reset();
        return UNDEFINED;
    }

    if (pin == 2)
        return pins.compute(Not, 1);
    if (pin == 4)
        return pins.compute(Not, 3);
    if (pin == 6)
        return pins.compute(Not, 5);
    if (pin == 8)
        return pins.compute(Not, 9);
    if (pin == 10)
        return pins.compute(Not, 11);
    if (pin == 12)
        return pins.compute(Not, 13);
    return pins.compute(pin);
}

void nts::not_4069::setLink(std::size_t pin, nts::IComponent &other,
                            std::size_t otherPin)
{
    pins.setLink(pin, other, otherPin);
}

void nts::not_4069::dump() const
{
    std::cout << std::endl << "  -Type   :\tnot_4069" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Links  :" << std::endl;
    pins.dump();
}

void nts::not_4069::simulate(std::size_t tick)
{
}

