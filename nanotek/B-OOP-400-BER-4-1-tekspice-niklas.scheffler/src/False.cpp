/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** False.cpp
*/

#include "../include/False.hpp"

nts::False::False() : Input("0")
{
    checkSet();
}

void nts::False::setValue(nts::Tristate value)
{
    throw std::runtime_error("False component not setable!");
}

void nts::False::dump() const
{
    std::cout << std::endl << "  -Type   :\tFalse" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Value  :\t" << _value << std::endl;
    std::cout << "  -Links  :" << std::endl;
    _outPin.dump();
}
