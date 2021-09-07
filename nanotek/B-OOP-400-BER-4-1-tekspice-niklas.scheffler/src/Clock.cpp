/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Clock.cpp
*/

#include "../include/Clock.hpp"

nts::Clock::Clock(std::string value) : Input(value)
{
}

void nts::Clock::dump() const
{
    std::cout << std::endl << "  -Type   :\tClock" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Value  :\t" << _value << std::endl;
    std::cout << "  -Links  :" << std::endl;
    _outPin.dump();
}

void nts::Clock::reverse()
{
    if (_value == TRUE)
    {
        delete _nextValue;
        _nextValue = new Tristate(FALSE);
    }
    else if (_value == FALSE)
    {
        delete _nextValue;
        _nextValue = new Tristate(TRUE);
    }
}
