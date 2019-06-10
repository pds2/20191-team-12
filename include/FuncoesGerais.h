#ifndef FUNCOES_GERAIS_H
#define FUNCOES_GERAIS_H

#include <string>
#include "Personagem.h"

void checker(int *variavel, int p1, int p2);
std::string adjust_square(std::string to_print, int num);
void print_square(std::string to_print1, std::string to_print2, std::string to_print3, std::string to_print4); // square_size padrão = 35
<<<<<<< HEAD
void exit();
int reward(int fase_num, int multiplicador, Personagem &player);
=======
int reward(int fase_num, int multiplicador);
>>>>>>> 323b6754e4351c736916496e53c71263f696d653

#endif
