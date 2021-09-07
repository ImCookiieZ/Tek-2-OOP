/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../../include/Chipsets/4013_flipflop.hpp"

nts::flipflop_4013::flipflop_4013(std::string const &value)
{
    ready = false;
    state1 = TRUE;
    state2 = TRUE;
    clockState1 = UNDEFINED;
    clockState2 = UNDEFINED;

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

nts::Tristate nts::flipflop_4013::compute(std::size_t pin)
{
    if (pin == 0) {
        pins.reset();
        ready = false;
        return UNDEFINED;
    }

    if (!ready) {
        ready = true;
        computeClock();
    }

    if (pin == 3)
        return compute1(1);
    if (pin == 4)
        return Not(compute1(1));
    if (pin == 10)
        return compute2(1);
    if (pin == 11)
        return Not(compute2(1));
    return pins.compute(pin);
}

void nts::flipflop_4013::setLink(std::size_t pin, nts::IComponent &other,
                            std::size_t otherPin)
{
    pins.setLink(pin, other, otherPin);
}

void nts::flipflop_4013::dump() const
{
    std::cout << "[4081] " << get_address(this) << std::endl;
    pins.dump();
}

void nts::flipflop_4013::simulate(std::size_t tick)
{
}

nts::Tristate nts::flipflop_4013::compute1(std::size_t pin)
{
    Tristate r = pins.compute(4);
    Tristate input = pins.compute(5);
    Tristate s = pins.compute(6);

    if (s == FALSE && r == FALSE) {
        if (clockState1 == TRUE && input != UNDEFINED)
            return UNDEFINED;
        else if (clockState1 == FALSE)
            return state1;
    }
    else if (s == TRUE && r != UNDEFINED)
        return TRUE;
    else if (s == FALSE && r == TRUE)
        return FALSE;
    return UNDEFINED;
}

nts::Tristate nts::flipflop_4013::compute2(std::size_t pin)
{
    Tristate r = pins.compute(10);
    Tristate input = pins.compute(9);
    Tristate s = pins.compute(8);

    if (s == FALSE && r == FALSE) {
        if (clockState2 == TRUE && input != UNDEFINED)
            return UNDEFINED;
        else if (clockState2 == FALSE)
            return state2;
    }
    else if (s == TRUE && r != UNDEFINED)
        return TRUE;
    else if (s == FALSE && r == TRUE)
        return FALSE;
    return UNDEFINED;
}

void nts::flipflop_4013::computeClock()
{
    if (clockState1 == TRUE && pins.compute(3) == FALSE)
        clockState1 = FALSE;
    else if (clockState1 == FALSE && pins.compute(3) == TRUE)
        clockState1 = TRUE;
    else
        clockState1 = UNDEFINED;

    if (clockState2 == TRUE && pins.compute(11) == FALSE)
        clockState2 = FALSE;
    else if (clockState2 == FALSE && pins.compute(11) == TRUE)
        clockState2 = TRUE;
    else
        clockState2 = UNDEFINED;
}
