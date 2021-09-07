/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** PinManager.cpp
*/

#include "../include/PinManager.hpp"
#include "../include/InputPin.hpp"
#include "../include/OutputPin.hpp"

void nts::PinManager::addInput(IComponent *comp, size_t pin)
{
    if (comp == nullptr)
        throw std::runtime_error("addable InputPin is on null component");
    _pins[pin] = std::make_unique<InputPin>(comp, pin);
}

void nts::PinManager::addOutput(nts::IComponent *comp, size_t pin)
{
    if (comp == nullptr)
        throw std::runtime_error("addable InputPin is on null component");
    _pins[pin] = std::make_unique<OutputPin>(comp, pin);
}

nts::Tristate nts::PinManager::compute(std::size_t pin)
{
    if (_pins.find(pin) == _pins.end())
        throw std::runtime_error("pin does not exist");
    return _pins[pin]->compute();
}

nts::Tristate nts::PinManager::compute(nts::PinManager::oneInputFunc gate, size_t pin)
{
    if (_pins.find(pin) == _pins.end())
        throw std::runtime_error("pin does not exist");
    return gate(_pins[pin]->compute());
}

nts::Tristate nts::PinManager::compute(nts::PinManager::twoInputFunc gate, size_t pinOne, size_t pinTwo)
{
    if (_pins.find(pinOne) == _pins.end())
        throw std::runtime_error("pin does not exist");
    if (_pins.find(pinTwo) == _pins.end())
        throw std::runtime_error("pin does not exist");
    return gate(_pins[pinOne]->compute(), _pins[pinTwo]->compute());
}

void nts::PinManager::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (_pins.find(pin) == _pins.end())
        throw std::runtime_error("pin does not exist");
    _pins[pin]->link(other, otherPin);
}

bool nts::PinManager::isLinked(size_t pin) const
{
    auto const pinPos (_pins.find(pin));
    if (pinPos != _pins.end())
        return pinPos->second->isLinked();
    return false;
}

void nts::PinManager::reset()
{
    for (auto &pin : _pins)
        pin.second->reset();
}

void nts::PinManager::dump() const
{
    for (auto &pin : _pins)
        pin.second->dump();
}
