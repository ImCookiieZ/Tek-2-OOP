#include <memory>
#include "IComponent.hpp"
#include <map>
#include <string>
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"

class Circuit : nts::IComponent
{
private:
    std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
    std::map<std::string, std::shared_ptr<nts::Input>> _inputs;
    std::map<std::string, std::shared_ptr<nts::Output>> _outputs;
    std::map<std::string, std::shared_ptr<nts::Clock>> _clocks;
    size_t _ticks = 0;
public:
    Circuit() = default;
    virtual ~Circuit() = default;
    virtual void simulate(std::size_t tick = 1);
    virtual nts::Tristate compute(std::size_t pin);
//    virtual void setLink(std::pair<std::string, size_t>pairOne, std::pair<std::string,
//        size_t>pairTwo);
    virtual void setLink(std::string namePinOne, size_t numberPinOne, std::string namePinTwo,
        size_t numberPinTwo);
    virtual void setLink(std::size_t pin, nts::IComponent &other, std::
    size_t otherPin);
    virtual void dump() const;
	void addComponent(std::unique_ptr<nts::IComponent>component, const std::string &name, const
	std::string &type);
	void setInput(std::string const &name, std::string const &value);

	void Display();
};