/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../../include/Chipsets/4017_johnson.hpp"

nts::johnson_4017::johnson_4017(std::string const &value)
{
    pins.addOutput(this, 1);
    pins.addOutput(this, 2);
    pins.addOutput(this, 3);
    pins.addOutput(this, 4);
    pins.addOutput(this, 5);
    pins.addOutput(this, 6);
    pins.addOutput(this, 7);
    pins.addOutput(this, 8);
    pins.addOutput(this, 9);
    pins.addOutput(this, 10);
    pins.addOutput(this, 11);
    pins.addInput(this, 12);
    pins.addInput(this, 13);
    pins.addInput(this, 14);
    pins.addInput(this, 15);
}

nts::Tristate nts::johnson_4017::compute(std::size_t pin)
{
    if (pin == 0) {
        pins.reset();
        return UNDEFINED;
    }

    if (pin == 3)
        return pins.compute(Nor, 1, 2);
    if (pin == 4)
        return pins.compute(Nor, 5, 6);
    if (pin == 10)
        return pins.compute(Nor, 8, 9);
    if (pin == 11)
        return pins.compute(Nor, 12, 13);
    return pins.compute(pin);
}

void nts::johnson_4017::setLink(std::size_t pin, nts::IComponent &other,
                            std::size_t otherPin)
{
    pins.setLink(pin, other, otherPin);
}

void nts::johnson_4017::dump() const
{
    std::cout << std::endl << "  -Type   :\tjohnson_4017" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Links  :" << std::endl;
    pins.dump();
}

void nts::johnson_4017::simulate(std::size_t tick)
{
}
