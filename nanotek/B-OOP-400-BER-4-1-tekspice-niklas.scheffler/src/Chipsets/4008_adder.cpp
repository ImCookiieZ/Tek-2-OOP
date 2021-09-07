/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../../include/Chipsets/4008_adder.hpp"

nts::adder_4008::adder_4008(std::string const &value)
{
    pins.addInput(this, 1);
    pins.addInput(this, 2);
    pins.addInput(this, 3);
    pins.addInput(this, 4);
    pins.addInput(this, 5);
    pins.addInput(this, 6);
    pins.addInput(this, 7);
    pins.addOutput(this, 8);
    pins.addInput(this, 9);
    pins.addOutput(this, 10);
    pins.addOutput(this, 11);
    pins.addOutput(this, 12);
    pins.addOutput(this, 13);
    pins.addOutput(this, 14);
    pins.addInput(this, 15);
    pins.addOutput(this, 16);
}

nts::Tristate sum(nts::Tristate a, nts::Tristate b, nts::Tristate &c)
{
    // (a && b) || (a && c) || (b && c)
    c = Or(Or(And(a, b), And(a, c)), And(b, c));
    // a xor b xor c
    auto const result{Xor(Xor(a, b), c)};

    return result;
}

nts::Tristate nts::adder_4008::compute(std::size_t pin)
{
    if (pin == 0) {
        pins.reset();
        return UNDEFINED;
    }

    if (pin == 10)
        return computeS1().first;
    if (pin == 11)
        return computeS2().first;
    if (pin == 12)
        return computeS3().first;
    if (pin == 13)
        return computeS4().first;
    if (pin == 14)
        return computeS4().second;
    return pins.compute(pin);
}

void nts::adder_4008::setLink(std::size_t pin, nts::IComponent &other,
                              std::size_t otherPin)
{
    pins.setLink(pin, other, otherPin);
}

void nts::adder_4008::dump() const
{
    std::cout << std::endl << "  -Type   :\tadder_4008" << std::endl << "  -Address:\t";
    std::stringstream ss;
    ss << this;
    std::cout << ss.str();
    std::cout << " " << std::endl;
    std::cout << "  -Links  :" << std::endl;
    pins.dump();
}

std::pair<nts::Tristate, nts::Tristate> nts::adder_4008::computeS1() {
    auto carry{pins.compute(9)};
    auto result = std::make_pair(
        sum(pins.compute(6), pins.compute(7), carry), carry);
    return result;
}

std::pair<nts::Tristate, nts::Tristate> nts::adder_4008::computeS2() {
    auto carry{computeS1().second};
    auto result = std::make_pair(
        sum(pins.compute(4), pins.compute(5), carry), carry);
    return result;
}

std::pair<nts::Tristate, nts::Tristate> nts::adder_4008::computeS3() {
    auto carry{computeS2().second};
    auto result = std::make_pair(
        sum(pins.compute(2), pins.compute(3), carry), carry);
    return result;
}

std::pair<nts::Tristate, nts::Tristate> nts::adder_4008::computeS4() {
    auto carry{computeS3().second};
    auto result = std::make_pair(
        sum(pins.compute(15), pins.compute(1), carry), carry);
    return result;
}

void nts::adder_4008::simulate(std::size_t tick)
{
}
