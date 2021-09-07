/*
** EPITECH PROJECT, 2021
** B_OOP_400_BER_4_1_arcade_adrian_lewitzki
** File description:
** main.cpp
*/

#include "../games/nibbler/Nibbler.hpp"
int main()
{
    srand(0);
    Nibbler s;
    s.start_game();
    while (s.game_tick() != "q");
    return 0;
}