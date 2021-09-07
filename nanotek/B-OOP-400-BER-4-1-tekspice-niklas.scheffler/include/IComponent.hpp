// nanotekspice Bootstrap.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
    public :
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::
            size_t otherPin) = 0;
        virtual void dump() const = 0;
    };
}

std::ostream &operator << (std::ostream &out, nts::Tristate state);
