/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../../include/Chipsets/4040_counter.hpp"

void nts::counter_4040::simulate(std::size_t tick)
{
}

void nts::counter_4040::dump() const
{
        std::cout << std::endl << "  -Type   :\tcounter_4040" << std::endl << "  -Address:\t";
        std::stringstream ss;
        ss << this;
        std::cout << ss.str();
        std::cout << " " << std::endl;
        std::cout << "  -Links  :" << std::endl;
        _pins.dump();
}

void nts::counter_4040::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    _pins.setLink(pin, other, otherPin);
}

nts::Tristate nts::counter_4040::compute(size_t pin)
{
    if (pin == 0)
    {
        _resultIsCalculated = false;
        _pins.reset();
        return UNDEFINED;
    }
    if (!_resultIsCalculated)
    {
        Tristate after = _pins.compute(10);
        if (_pins.compute(11) == TRUE)
            _pins.reset();
        else if (after == FALSE && _previus == TRUE)
        {
            if (_counter == 4095)
                _counter = 0;
            else
                _counter++;
        }
        _resultIsCalculated = true;
        _previus = after;
    }
    switch (pin)
    {
        case 9:
            if (_counter >> (1 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 7:
            if (_counter >> (2 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 6:
            if (_counter >> (3 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 5:
            if (_counter >> (4 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 3:
            if (_counter >> (5 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 2:
            if (_counter >> (6 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 4:
            if (_counter >> (7 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 13:
            if (_counter >> (8 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 12:
            if (_counter >> (9 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 14:
            if (_counter >> (10 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 15:
            if (_counter >> (11 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        case 1:
            if (_counter >> (12 - 1) & 1)
                return TRUE;
            else
                return FALSE;
        default:
            _pins.compute(pin);
    }
    return nts::FALSE;
}

nts::counter_4040::counter_4040(std::string &value)
{
    _pins.addInput(this, 10); // clock
    _pins.addInput(this, 11); //reset

    _pins.addOutput(this, 9); // q1
    _pins.addOutput(this, 7); // q2
    _pins.addOutput(this, 6); // q3
    _pins.addOutput(this, 5); // q4
    _pins.addOutput(this, 3); // q5
    _pins.addOutput(this, 2); // q6
    _pins.addOutput(this, 4); // q7
    _pins.addOutput(this, 13);// q8
    _pins.addOutput(this, 12);// q9
    _pins.addOutput(this, 14);//q10
    _pins.addOutput(this, 15);//q11
    _pins.addOutput(this, 1); //q12

    _pins.addOutput(this, 8); //VSS
    _pins.addOutput(this, 16); //VDD
}

