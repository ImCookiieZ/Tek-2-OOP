/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** True.cpp
*/

#include "../include/True.hpp"

nts::True::True() : Input("1")
{
    checkSet();
}

void nts::True::dump() const
{
    std::cout << std::endl << "  -Type   :\tTrue" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Value  :\t" << _value << std::endl;
    std::cout << "  -Links  :" << std::endl;
    _outPin.dump();
}

void nts::True::setValue(nts::Tristate value)
{
    throw std::runtime_error("True component not setable!");
}
