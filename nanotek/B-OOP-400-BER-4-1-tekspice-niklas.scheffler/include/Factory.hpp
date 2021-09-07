/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** factory.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_FACTORY_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_FACTORY_HPP

#include "IComponent.hpp"
#include <memory>
#include <unordered_map>

class Factory
{
private:
    using functionPtr = std::unique_ptr<nts::IComponent>(Factory::*)(std::string name) const;
    //    using functionPtr = nts::IComponent *(Parser::*)() const;
    std::unordered_map<std::string, functionPtr> _createComponentFunctions;

    std::unique_ptr<nts::IComponent> create4001(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4008(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4011(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4030(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4069(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4071(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4081(std::string value) const noexcept ;
    std::unique_ptr<nts::IComponent> create4040(std::string value) const noexcept ;

    std::unique_ptr<nts::IComponent> createInput(std::string) const noexcept ;
    std::unique_ptr<nts::IComponent> createTrue(std::string) const noexcept ;
    std::unique_ptr<nts::IComponent> createFalse(std::string) const noexcept ;
    std::unique_ptr<nts::IComponent> createClock(std::string) const noexcept ;

    std::unique_ptr<nts::IComponent> createOutput(std::string) const noexcept ;
public:
    Factory();
    void initCreatorFunctions();
    std::unique_ptr<nts::IComponent>createComponent(const std::string &basic_string,
        const std::string &name);
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_FACTORY_HPP
