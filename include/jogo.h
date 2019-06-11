#include <iostream>
#include <stdio.h>

#include "Habilidade.h"
#include "Batalha.h"
#include "npc.h"
#include "boss.h"
#include "Personagem.h"
#include "FuncoesGerais.h"
#include "menu.h"

#define n_enemies 3

void jogo();
void Fase_1(Personagem &player, int &t_num);
void Fase_2(Personagem &player, int &t_num);
void Fase_3(Personagem &player, int &t_num);
void Fase_4(Personagem &player, int &t_num);
void Fase_5(Personagem &player, int &t_num);
void Fase_6(Personagem &player, int &t_num);
void Fase_7(Personagem &player, int &t_num);