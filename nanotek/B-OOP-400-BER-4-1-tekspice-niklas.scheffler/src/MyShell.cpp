/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** MyShell.cpp
*/

#include "../include/MyShell.hpp"
#include <csignal>
bool Stopped::Run = true;
MyShell::MyShell(Circuit &circuit)
{
    _circuit = circuit;
}

void MyShell::run()
{
    std::cout << "> ";
    std::string line;
    if (!getline(std::cin, line))
        return;
    std::string valueOne;
    std::string valueTwo;
    if (line == "simulate")
        _circuit.simulate();
    else if (line == "display")
        _circuit.Display();
    else if (line == "exit")
        return;
    else if (line == "dump")
        _circuit.dump();
    else if (line == "loop")
    {
        std::signal(SIGINT, Stopped::StopShell);
        while (Stopped::Run)
        {
            _circuit.simulate();
            _circuit.Display();
        }
        std::signal(SIGINT, SIG_DFL);
    }
    else
    {
        size_t pos = line.find('=');
        if (pos != std::string::npos)
        {
            valueOne = line.substr(0, pos);
            valueTwo = line.substr(pos + 1);
            _circuit.setInput(valueOne, valueTwo);
        }
        else
        {
            throw std::runtime_error("no valid input!");
        }
    }
    run();
}

void Stopped::StopShell(int)
{
    Run = false;
}
