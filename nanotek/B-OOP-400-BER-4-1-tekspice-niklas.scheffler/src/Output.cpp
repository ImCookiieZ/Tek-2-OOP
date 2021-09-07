/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Output.cpp
*/

#include "../include/Output.hpp"

nts::Output::Output() : _value(UNDEFINED)
{
    _map.addInput(this, 1);
}

nts::Tristate nts::Output::compute(size_t pin)
{
    if (pin == 0)
    {
        _map.reset();
        return UNDEFINED;
    }
    else if (!_map.isLinked(1))
    {
        throw std::runtime_error("Output is not linked");
    }
    _value = _map.compute(1);
    return _value;
}

void nts::Output::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    _map.setLink(pin, other, otherPin);
}

void nts::Output::dump() const
{
    std::cout << std::endl << "  -Type   :\tOutput" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Value  :\t" << _value << std::endl;
    std::cout << "  -Links  :" << std::endl;
    _map.dump();
}

void nts::Output::display() const
{
}

void nts::Output::display(const std::string &name) const
{
    std::cout << "  " << name << ": " << _value << std::endl;
}

void nts::Output::simulate(std::size_t tick)
{
}
