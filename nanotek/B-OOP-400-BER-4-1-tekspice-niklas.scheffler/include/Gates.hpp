/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_GATES_HPP
#define B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_GATES_HPP

#include "IComponent.hpp"

nts::Tristate And(nts::Tristate pin1, nts::Tristate pin2);
nts::Tristate Or(nts::Tristate pin1, nts::Tristate pin2);
nts::Tristate Not(nts::Tristate pin);
nts::Tristate Nand(nts::Tristate pin1, nts::Tristate pin2);
nts::Tristate Nor(nts::Tristate pin1, nts::Tristate pin2);
nts::Tristate Xor(nts::Tristate pin1, nts::Tristate pin2);
nts::Tristate Xnor(nts::Tristate pin1, nts::Tristate pin2);

#endif //B_OOP_400_BER_4_1_TEKSPICE_NIKLAS_SCHEFFLER_GATES_HPP
