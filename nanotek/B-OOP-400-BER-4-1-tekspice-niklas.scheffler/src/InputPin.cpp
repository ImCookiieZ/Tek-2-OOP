/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** InputPin.cpp
*/

#include "../include/InputPin.hpp"

nts::InputPin::InputPin(IComponent *compo, size_t pin) : Pin(compo, pin), _actualState(UNDEFINED)
, _resultIsCalculated(false)
{}

void nts::InputPin::link(nts::IComponent &other, size_t otherPin)
{
    if (&_compo == &other && _pin == otherPin)
    {
        throw std::runtime_error("selflink InputPin");
    }
    if (!linkExists(other, otherPin))
    {
        if (isLinked())
            throw std::runtime_error("multiple setLink");
        _links.emplace_back(other, otherPin);
        other.setLink(otherPin, _compo, _pin);
    }
}

nts::Tristate nts::InputPin::compute()
{
    if (isLinked())
    {
        if (!_resultIsCalculated)
        {
            _resultIsCalculated = true;
            _actualState = _links[0].first.get().compute(_links[0].second);
        }
        return _actualState;
    }
    return UNDEFINED;
}

void nts::InputPin::reset()
{
    _resultIsCalculated = false;
}

