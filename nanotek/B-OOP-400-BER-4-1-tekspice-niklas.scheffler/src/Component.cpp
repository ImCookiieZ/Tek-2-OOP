#include "../include/Component.hpp"

void Component::linkTo(IComponent* link_to)
{
}

void Component::dump() const
{
}

void Component::setLink(std::size_t pin, nts::IComponent &other,
                        std::size_t otherPin)
                        {
}

int Component::execute()
{
    return 0;
}

void Component::simulate(std::size_t tick)
{
}

nts::Tristate Component::compute(std::size_t pin)
{
    return nts::FALSE;
}


std::ostream &operator << (std::ostream &out, nts::Tristate state)
{
    if (state == nts::Tristate::UNDEFINED)
        out << "U";
    else if (state == nts::FALSE)
        out << "0";
    else
        out << "1";
    return out;
}