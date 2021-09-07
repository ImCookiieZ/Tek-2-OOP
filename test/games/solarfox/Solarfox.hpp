/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_ARCADE_ADRIAN_LEWITZKI_SOLARFOX_HPP
#define B_OOP_400_BER_4_1_ARCADE_ADRIAN_LEWITZKI_SOLARFOX_HPP

#include <vector>
#include "../IGame.hpp"
#include "../../core/graphical.hpp"
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

typedef struct
{
    int x1;
    int x2;
    int y1;
    int y2;
} pos;

template<typename T1, typename  T2, typename  T3>
class Triple
{
public:
    T1 first;
    T2 second;
    T3 third;
};
using object_triple = Triple<object_creation_data, pos, void *>;

class Solarfox final : public IGame
{
private:
    IGraphics *lib = nullptr;
    bool _isRunning;
    std::chrono::steady_clock::time_point _last_tick;
    pos border = {100, 900, 100, 800};
    std::map<std::string, std::vector<object_triple>>
    _objects;
    int _cur_direction;
    std::pair<int, int> _mov;
    object_creation_data _name;
    std::vector<std::pair<std::string, int>> _scores;
    std::string _input;

    static object_creation_data *fill_data(std::string text, object_type type,
                                   std::string path, std::string color);
    static object_triple *create_triple(object_creation_data *data, pos
    position, void *object);
    void gameover();
    void create_borders();
    void create_grid();
public:
    explicit Solarfox(IGraphics *lib);
    void start_game() final;
    std::string game_tick() final;
    bool is_running() final;
    void use_graphics_lib(IGraphics *lib) final;
    void reload_all_objects() final;
};

extern "C" {
IGame *create_game(IGraphics *lib);
}

#endif //B_OOP_400_BER_4_1_ARCADE_ADRIAN_LEWITZKI_SOLARFOX_HPP
