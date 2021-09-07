/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** OutputPin.cpp
*/

#include "../include/OutputPin.hpp"

nts::OutputPin::OutputPin(IComponent *compo, size_t pin) : Pin(compo, pin)
{
}

void nts::OutputPin::link(nts::IComponent &other, size_t otherPin)
{
    if (&_compo == &other && _pin == otherPin)
    {
        throw std::runtime_error("selflinking OutputPin");
    }
    if (!linkExists(other, otherPin))
    {
        _links.emplace_back(other, otherPin);
        other.setLink(otherPin, _compo, _pin);
    }
}

nts::Tristate nts::OutputPin::compute()
{
    return UNDEFINED;
}

void nts::OutputPin::reset()
{
}

