/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Pin.cpp
*/

#include <search.h>
#include "../include/Pin.hpp"
nts::Pin::Pin(nts::IComponent *comp, size_t id) : _compo (*comp), _pin(id)
{
}

bool nts::Pin::isLinked() const
{
    return !_links.empty();
}

bool nts::Pin::linkExists(nts::IComponent &other, size_t otherPin) const
{
    for (auto const &link : _links)
    {
        if (&link.first.get() == &other && link.second == otherPin)
            return true;
    }
    return false;
}

void nts::Pin::dump() const
{
    if (_links.empty())
        std::cout << "\t\tPin " << _pin <<": Not Linked" <<std::endl;
    else if (_links.size() == 1)
    {
        std::cout << "\t\tPin " << _pin << ":" << std::endl;
        std::stringstream ss;
        ss << &_links[0].first.get();
        std::cout << "\t\t\t-Component Address: " << ss.str() << std::endl;
        std::cout << "\t\t\t-Pin              : " << std::to_string(_links[0].second) << std::endl;
    }
    else
    {
        for (size_t i = 0; _links.size() < i; i++)
        {
            std::cout << "  Pin:" << _pin << i <<".  --> ";
            std::stringstream ss;
            ss << &_links[i].first.get();
            std::cout << "Component Address: " << ss.str() << " pin: " << std::to_string
            (_links[i].second) << std::endl;
        }
    }
}
