#include "../include/Circuit.hpp"
#include "../include/InputPin.hpp"
void Circuit::addComponent(std::unique_ptr<nts::IComponent>component, const std::string &name,
    const std::string &type)
{
    std::shared_ptr<nts::IComponent> newComponent = std::move(component);
    if (_components.find(name) != _components.end())
        throw std::runtime_error("variable '" + name + "' has multiple definition");
    _components[name] = newComponent;
    if (type == "input" || type == "clock")
        _inputs[name] = std::dynamic_pointer_cast<nts::Input>(newComponent);
    else if (type == "output")
        _outputs[name] = std::dynamic_pointer_cast<nts::Output>(newComponent);
    if (type == "clock")
        _clocks[name] = std::dynamic_pointer_cast<nts::Clock>(newComponent);
}

void Circuit::simulate(std::size_t tick) {
    for (size_t i = 0; i < tick; i++)
    {
        for (auto &it : _inputs)
            it.second->checkSet();
        for (auto &it : _components)
        {
            it.second->compute(0);
        }
        for (auto &it : _outputs)
        {
            it.second->compute(1);
        }
        for (auto  &it : _clocks)
            it.second->reverse();
        _ticks++;
    }
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    return nts::FALSE;
}

void Circuit::setLink(std::size_t pin, nts::IComponent &other,
                      std::size_t otherPin)
{
}

void Circuit::dump() const
{
    bool start = true;
    for (auto &it : _components)
    {
        if (start)
            start = false;
        else
            std::cout << std::endl;
        std::cout << it.first << ":";
        it.second->dump();
    }
}
//
//void
//Circuit::setLink(std::pair<std::string, size_t> pairOne, std::pair<std::string, size_t> pairTwo)
//{
//    nts::IComponent *first;
//    nts::IComponent *second;
//    if (_components.find(pairOne.first) == _components.end())
//        throw std::runtime_error("Pin1 '" + pairOne.first + "' unknown");
//    if (_components.find(pairTwo.first) == _components.end())
//        throw std::runtime_error("Pin2 '" + pairTwo.first + "' unknown");
//    first = _components[pairOne.first].get();
//    second = _components[pairTwo.first].get();
//    first->setLink(pairOne.second, *second, pairTwo.second);
//    second->setLink(pairTwo.second, *first, pairOne.second);
//}

void Circuit::setInput(const std::string &name, const std::string &value)
{
    for (auto const &comp : _inputs)
    {
        if (comp.first == name)
        {
            comp.second->setValue(value);
            return;
        }
    }
    throw std::runtime_error("variable '" + name + "'not setable");
}

void Circuit::Display()
{
    std::cout << "tick: " << _ticks - 1 << std::endl;
    std::cout << "input(s):" <<std::endl;
    for (auto const &inp: _inputs)
        inp.second->display(inp.first);
    std::cout << "output(s):" <<std::endl;
    for (auto const &outp: _outputs)
        outp.second->display(outp.first);
}

void Circuit::setLink(std::string namePinOne, size_t numberPinOne, std::string namePinTwo,
                      size_t numberPinTwo)
{
    nts::IComponent *first;
    nts::IComponent *second;
    if (_components.find(namePinOne) == _components.end())
        throw std::runtime_error("Pin1 '" + namePinOne + "' unknown");
    if (_components.find(namePinTwo) == _components.end())
        throw std::runtime_error("Pin2 '" + namePinTwo + "' unknown");
    first = _components[namePinOne].get();
    second = _components[namePinTwo].get();
    first->setLink(numberPinOne, *second, numberPinTwo);
    second->setLink(numberPinTwo, *first, numberPinOne);
}


