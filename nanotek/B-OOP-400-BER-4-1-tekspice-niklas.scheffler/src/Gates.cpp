/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/Gates.hpp"

nts::Tristate And(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == nts::TRUE && pin2 == nts::TRUE)
        return nts::TRUE;
    else if (pin1 == nts::Tristate::FALSE || pin2 == nts::Tristate:: FALSE)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate Or(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == nts::TRUE || pin2 == nts::TRUE)
        return nts::TRUE;
    else if (pin1 == nts::Tristate::FALSE && pin2 == nts::Tristate:: FALSE)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate Not(nts::Tristate pin)
{
    if (pin == nts::TRUE)
        return nts::FALSE;
    else if (pin == nts::FALSE)
        return nts::TRUE;
    return nts::UNDEFINED;
}

nts::Tristate Nand(nts::Tristate pin1, nts::Tristate pin2)
{
    return Not(And(pin1, pin2));
}

nts::Tristate Nor(nts::Tristate pin1, nts::Tristate pin2)
{
    return Not(Or(pin1, pin2));
}

nts::Tristate Xor(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == nts::UNDEFINED || pin2 == nts::UNDEFINED)
        return nts::UNDEFINED;
    else if (pin1 != pin2)
        return nts::TRUE;
    return nts::FALSE;
}

nts::Tristate Xnor(nts::Tristate pin1, nts::Tristate pin2)
{
    return Not(Xor(pin1, pin2));
}
