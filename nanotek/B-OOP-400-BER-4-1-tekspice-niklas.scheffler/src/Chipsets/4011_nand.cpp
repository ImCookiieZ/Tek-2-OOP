/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../../include/Chipsets/4011_nand.hpp"

nts::nand_4011::nand_4011(std::string const &value)
{
    pins.addInput(this, 1);
    pins.addInput(this, 2);
    pins.addOutput(this, 3);
    pins.addOutput(this, 4);
    pins.addInput(this, 5);
    pins.addInput(this, 6);
    pins.addOutput(this, 7);
    pins.addInput(this, 8);
    pins.addInput(this, 9);
    pins.addOutput(this, 10);
    pins.addOutput(this, 11);
    pins.addInput(this, 12);
    pins.addInput(this, 13);
    pins.addOutput(this, 14);
}

nts::Tristate nts::nand_4011::compute(std::size_t pin)
{
    if (pin == 0) {
        pins.reset();
        return UNDEFINED;
    }

    if (pin == 3)
        return pins.compute(Nand, 1, 2);
    if (pin == 4)
        return pins.compute(Nand, 5, 6);
    if (pin == 10)
        return pins.compute(Nand, 8, 9);
    if (pin == 11)
        return pins.compute(Nand, 12, 13);
    return pins.compute(pin);
}

void nts::nand_4011::setLink(std::size_t pin, nts::IComponent &other,
                            std::size_t otherPin)
{
    pins.setLink(pin, other, otherPin);
}

void nts::nand_4011::dump() const
{
    std::cout << std::endl << "  -Type   :\tnand_4011" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Links  :" << std::endl;
    pins.dump();
}

void nts::nand_4011::simulate(std::size_t tick)
{
}
