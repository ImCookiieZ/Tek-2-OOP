/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** Factory.cpp
*/

#include "../include/Factory.hpp"
#include "../include/all_components.hpp"

std::unique_ptr<nts::IComponent>Factory::createComponent(const std::string &type, const
std::string &value)
{
//    std::cout << "type: " << type << " value: " << value << std::endl;
    if (_createComponentFunctions.find(type) == _createComponentFunctions.end())
        throw std::runtime_error("type '" + type + "' not found");
    return (this->*_createComponentFunctions[type])(value);
}

void Factory::initCreatorFunctions()
{
    _createComponentFunctions["output"] = &Factory::createOutput;
    _createComponentFunctions["input"] = &Factory::createInput;

    _createComponentFunctions["true"] = &Factory::createTrue;
    _createComponentFunctions["false"] = &Factory::createFalse;
    _createComponentFunctions["clock"] = &Factory::createClock;

    _createComponentFunctions["4001"] = &Factory::create4001;
    _createComponentFunctions["4008"] = &Factory::create4008;
    _createComponentFunctions["4011"] = &Factory::create4011;
    _createComponentFunctions["4030"] = &Factory::create4030;
    _createComponentFunctions["4069"] = &Factory::create4069;
    _createComponentFunctions["4071"] = &Factory::create4071;
    _createComponentFunctions["4081"] = &Factory::create4081;
    _createComponentFunctions["4040"] = &Factory::create4040;
    //here init components
}

std::unique_ptr<nts::IComponent> Factory::create4071(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::or_4071(value));
}

std::unique_ptr<nts::IComponent> Factory::createInput(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::Input(value));
}

std::unique_ptr<nts::IComponent> Factory::createOutput(std::string) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::Output());
}

Factory::Factory()
{
    initCreatorFunctions();
}

std::unique_ptr<nts::IComponent> Factory::createTrue(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::True());
}

std::unique_ptr<nts::IComponent> Factory::createFalse(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::False());
}

std::unique_ptr<nts::IComponent> Factory::createClock(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::Clock(value));
}

std::unique_ptr<nts::IComponent> Factory::create4001(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::nor_4001(value));
}

std::unique_ptr<nts::IComponent> Factory::create4008(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::adder_4008(value));
}

std::unique_ptr<nts::IComponent> Factory::create4011(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::nand_4011(value));
}

std::unique_ptr<nts::IComponent> Factory::create4030(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::xor_4030(value));
}

std::unique_ptr<nts::IComponent> Factory::create4069(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::not_4069(value));
}

std::unique_ptr<nts::IComponent> Factory::create4081(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::and_4081(value));
}

std::unique_ptr<nts::IComponent> Factory::create4040(std::string value) const noexcept
{
    return std::unique_ptr<nts::IComponent>(new nts::counter_4040(value));
}
