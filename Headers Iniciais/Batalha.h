#ifndef BATALHA_H_INCLUDED__
#define BATALHA_H_INCLUDED__

#include "Personagem.h"
#include "mob.h"
#include "boss.h"

void batalha(Personagem &heroi, Mob &npc);
void menu2(Personagem &heroi, Mob &npc);
void menu3(Personagem &heroi, Mob &npc);
void atacar(Personagem &heroi, Mob &npc);
void atacar_mob(Personagem &heroi, Mob &npc);
void atacar_hab(Personagem &heroi, Mob &npc, Habilidade hab);
void atacar_hab_boss(Personagem&, Boss&);
void fugir(Personagem &heroi);

#endif // BATALHA_H_INCLUDED