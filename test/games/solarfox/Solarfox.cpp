/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "Solarfox.hpp"
#include <utility>

extern "C" {
IGame *create_game(IGraphics *lib) {
    return new Solarfox(lib);
}
}

Solarfox::Solarfox(IGraphics *lib) : lib(lib)
{
}

void Solarfox::start_game()
{
    lib->init_screen(1920, 1080);
    _name = *fill_data("", TEXT, "assets/font.ttf", "red");
    _isRunning = false;
    std::ifstream os;
    os.open("users");
    if (os.is_open())
        getline(os, _name.text);
    _name.text = "name: " + _name.text;
    os.close();

    std::ifstream is;
    is.open("solarfox_scores");
    if (is.is_open()) {
        std::string line;
        while (getline(is, line)) {
            std::stringstream tmp(line);
            std::string sc;
            std::string na;
            tmp >> na >> sc;
            try {
                std::pair<std::string, int> tpair{na, stoi(sc)};
                _scores.emplace_back(tpair);
            } catch (std::exception &) {}
        }
    }
    create_borders();
    create_grid();
}

std::string Solarfox::game_tick()
{
    _input += lib->getPressedKey();

    if (_input.find("exit") != std::string::npos) {
        lib->destroy_screen();
        return "exit";
    }
    if (_input.find("enter") != std::string::npos)
        lib->destroy_screen();
    /*if (!_isRunning) {
        gameover();
        return _input;
    }*/
    lib->clear_screen();
    for (auto &object : _objects["border"]) {
        std::cout << object.second.y2 << std::endl;
        lib->draw(&object.first, object.second.x1, object.second.x2, object
            .second.y1, object.second.y2);
    }
    for (auto &object : _objects["grid"]) {
        std::cout << object.second.y2 << std::endl;
        lib->draw(&object.first, object.second.x1, object.second.x2, object
            .second.y1, object.second.y2);
    }
    lib->display_screen();
    return _input;
}

bool Solarfox::is_running()
{
    return false;
}

void Solarfox::use_graphics_lib(IGraphics *lib)
{
    lib = lib;
}

void Solarfox::reload_all_objects()
{
}

void Solarfox::gameover()
{
    object_creation_data *tmp = fill_data("Game Over",
TEXT, "assets/font.ttf", "red");
    lib->createObject(tmp);
    lib->clear_screen();
    lib->draw(&tmp, 200, 200, 500, 500);

    object_creation_data *tmp2 = fill_data("Press enter to restart", TEXT,
"assets/font.ttf", "green");
    lib->createObject(tmp2);
    lib->draw(&tmp2, 200, 200, 560, 560);
}

void Solarfox::create_borders()
{
    object_creation_data *border_data = fill_data("x", SPRITE,
                                                  "assets/block_snake.png",
                                            "white");
    void *border_obj = lib->createObject(border_data);
    std::vector<object_triple> tmp_vec;
    for (int x = border.x1; x <= border.x2; x += 10)
    {
        pos tmp1 = {x, (x + 10), border.y1, (border.y1 + 20)};
        pos tmp2 = {x, (x + 10), border.y2, (border.y2 + 20)};
        tmp_vec.emplace_back(*create_triple(border_data, tmp1, border_obj));
        tmp_vec.emplace_back(*create_triple(border_data, tmp2, border_obj));
    }
    for (int y = border.y1; y <= border.y2; y += 10)
    {
        pos tmp1 = {border.x1, border.x1 + 10, y, y + 20};
        pos tmp2 = {border.x2, border.x2 + 10, y, y + 20};
        tmp_vec.emplace_back(*create_triple(border_data, tmp1, border_obj));
        tmp_vec.emplace_back(*create_triple(border_data, tmp2, border_obj));
    }
    _objects.insert(std::pair<std::string, std::vector<object_triple>>("border", tmp_vec));
}

object_creation_data *
Solarfox::fill_data(std::string text, object_type type, std::string path,
                    std::string color)
                    {
    object_creation_data *data = new object_creation_data;
    data->text = std::move(text);
    data->type = type;
    data->path_to_resource = std::move(path);
    data->color_name = std::move(color);
    return data;
}

void Solarfox::create_grid()
{
    object_creation_data *vertical_data = fill_data("|", SPRITE,
                                              "assets/block_snake.png", "white");
    void *vertical = lib->createObject(vertical_data);
    object_creation_data *horizontal_data = fill_data("-", SPRITE,
                                                "assets/block_snake.png", "white");
    void *horizontal = lib->createObject(horizontal_data);
    std::vector<object_triple> tmp_vec;
    for (int y = border.y1 + 100; y < border.y2; y += 100) {
        for (int x = border.x1 + 10; x < border.x2; x += 10) {
        pos tmp = {x, x + 10, y, y + 20};
        tmp_vec.emplace_back(*create_triple(horizontal_data, tmp, horizontal));
        }
    }
    for (int x = border.x1 + 100; x < border.x2; x += 100) {
        for (int y = border.y1 + 20; y < border.y2; y += 10) {
            pos tmp = {x, x + 10, y, y + 20};
            tmp_vec.emplace_back(*create_triple(vertical_data, tmp, vertical));
        }
    }
    _objects.insert(std::pair<std::string, std::vector<object_triple>>("grid",
        tmp_vec));
}

object_triple *
Solarfox::create_triple(object_creation_data *data, pos position, void *
object) {
    object_triple *t = new object_triple;
    t->first = *data;
    t->second = position;
    t->third = object;
    return t;
}
