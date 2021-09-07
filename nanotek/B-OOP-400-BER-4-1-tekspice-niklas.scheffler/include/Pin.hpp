/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Pin.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_PIN_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_PIN_HPP
#include "IComponent.hpp"
#include <utility>
#include <functional>
namespace nts
{
    class Pin
    {
    public:
        using Link = std::pair<std::reference_wrapper<IComponent>, size_t>;
    protected:
        IComponent &_compo;
        size_t _pin;
        std::vector<Link> _links;
    public:
        Pin(IComponent *comp, size_t id);
        ~Pin() = default;
        Pin(Pin const &) = delete;
        Pin(Pin &&) = default;

//        Pin &operator=(Pin const &) = delete;
//        Pin &operator=(Pin &&) = default;

        virtual void link(IComponent &other, size_t otherPin) = 0;
        virtual Tristate compute() = 0;
        virtual void reset() = 0;

        bool isLinked() const;
        bool linkExists(IComponent &other, size_t otherPin) const;
        void dump() const;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_PIN_HPP
