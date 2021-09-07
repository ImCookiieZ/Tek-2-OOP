/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "core.hpp"
#include "graphical.hpp"
#include "menu.hpp"

void print_usage()
{
    std::cout << "Pass library as first argument." << std::endl;
    exit(84);
}

int main(int ac, char **av)
{
    if (ac != 2)
        print_usage();
    Menu m;
    void *lib = dlopen(av[1], RTLD_LAZY);
    auto g = (IGraphics *(*)()) dlsym(lib, "create_graphics");
    IGraphics *glib = g();
    m.use_graphics_lib(glib);
    m.set_handler(lib);
    m.start_game();
    while (m.game_tick().find("exit") == std::string::npos);
//    delete glib;
    return (0);
}