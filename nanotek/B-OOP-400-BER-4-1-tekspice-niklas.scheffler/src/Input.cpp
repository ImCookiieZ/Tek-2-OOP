/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Input.cpp
*/

#include "../include/Input.hpp"

nts::Input::Input(const std::string &value) : _outPin(this, 1)
{
    setValue(value);
}

nts::Tristate nts::Input::compute(size_t pin)
{
    if (pin == 0)
    {
        _outPin.reset();
        return UNDEFINED;
    }
    else if (pin == 1)
        return _value;
    throw std::runtime_error("pin is unknown");
}

void nts::Input::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin == 1)
        _outPin.link(other, otherPin);
    else
        throw std::runtime_error("pin is unknown");
}

void nts::Input::dump() const
{
    std::cout << std::endl << "  -Type   :\tInput" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Value  :\t" << _value << std::endl;
    std::cout << "  -Links  :" << std::endl;
    _outPin.dump();
}

nts::Tristate nts::Input::value() const
{
    return _value;
}

void nts::Input::setValue(nts::Tristate value)
{
    delete _nextValue;
    _nextValue = new Tristate(value);
}

void nts::Input::setValue(int value)
{
    switch (value)
    {
        case 1:
            setValue(TRUE);
            break;
        case 0:
            setValue(FALSE);
            break;
        default:
            setValue(UNDEFINED);
    }
}

void nts::Input::setValue(const std::string &value)
{
    try
    {
        setValue(std::stoi(value));
    } catch (std::exception const&)
    {
        setValue(UNDEFINED);
    }
}

void nts::Input::simulate(std::size_t tick)
{
}

void nts::Input::display(const std::string &name) const
{
    std::cout << "  " << name << ": " << _value << std::endl;
}

void nts::Input::checkSet()
{
    if (_nextValue != nullptr)
    {
        _value = *_nextValue;
        delete _nextValue;
        _nextValue = nullptr;
    }
}
