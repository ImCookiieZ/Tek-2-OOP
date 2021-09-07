/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_tekspice_niklas_scheffler
** File description:
** MyShell.hpp
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_MYSHELL_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_MYSHELL_HPP
#include "Circuit.hpp"
class MyShell
{
private:
    Circuit _circuit;
public:
    MyShell(Circuit &circuit);
    void run();
//    static void stopShell(int code);
};

class Stopped
{
public:
    static bool Run;
    static void StopShell(int);
};

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_MYSHELL_HPP
