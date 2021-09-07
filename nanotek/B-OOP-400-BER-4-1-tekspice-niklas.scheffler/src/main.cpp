// nanotekspice Bootstrap.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

//#include "../include/Component.hpp"
#include "../include/Parser.hpp"
int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::runtime_error("minimum of two arguments");
        Circuit circuit;
        Parser parser(av[1], circuit);
        circuit.simulate();
        MyShell shell(circuit);
//        circuit.setInput("b", "0");
//        circuit.setInput("a", "1");
//        circuit.Display();
//        circuit.simulate();
//        circuit.Display();
//        circuit.simulate();
//        circuit.Display();
        shell.run();
    } catch (std::runtime_error &ex)
    {
        std::cerr << ex.what() << std::endl;
        return 84;
    }
	return 0;
}
