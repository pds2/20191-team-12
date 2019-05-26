#ifndef BATALHA_H_INCLUDED__
#define BATALHA_H_INCLUDED__

void batalha(&Personagem heroi, &Mob npc);
void menu2(&Personagem heroi, &Mob npc);
void menu3(&Personagem heroi, &Mob npc);
void atacar(&Personagem heroi, &Mob npc);
void atacar_mob(&Personagem heroi, &Mob npc);
void atacar_hab(&Personagem heroi, &Mob npc);
void atacar_hab_boss(&Personagem heroi, &Mob npc);
void fugir(&Personagem heroi);

#endif // BATALHA_H_INCLUDED