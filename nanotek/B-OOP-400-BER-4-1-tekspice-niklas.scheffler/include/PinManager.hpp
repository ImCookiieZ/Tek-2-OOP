/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** PinManager.hpp
*/

#include "Pin.hpp"
#include <functional>
#include <memory>
#include <map>
#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_PINMAP_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_PINMAP_HPP

namespace nts
{
    class PinManager
    {
    private:
        std::map<size_t , std::unique_ptr<Pin>> _pins;
        using oneInputFunc = std::function<Tristate(Tristate)>;
        using twoInputFunc = std::function<Tristate(Tristate, Tristate)>;
    public:

        PinManager() = default;
        ~PinManager() = default;

        PinManager(PinManager const &) = delete ;
        PinManager(PinManager &&) = default;

        void addInput(IComponent *comp, size_t pin);
        void addOutput(IComponent *comp, size_t pin);

        Tristate compute(std::size_t pin);
        Tristate compute(oneInputFunc gate, size_t pin);
        Tristate compute(twoInputFunc gate, size_t pinOne, size_t pinTwo);

        void setLink(size_t pin, IComponent &other, size_t otherPin);
        bool isLinked(size_t pin) const;

        void reset();
        void dump() const;
    };
}

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_PINMAP_HPP
