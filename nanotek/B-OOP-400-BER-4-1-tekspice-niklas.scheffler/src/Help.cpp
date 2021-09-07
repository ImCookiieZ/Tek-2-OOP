/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/Help.hpp"

std::string get_address(void const *address)
{
    std::ostringstream ss;
    ss << address;
    return "<" + ss.str() + ">";
}