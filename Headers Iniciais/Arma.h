#ifndef ARMA_H
#define ARMA_H

#include "Equipamento.h"

class Arma : public Equipamento{
    private:
        std::string weapon_name;
        float b_attack;
        float b_defense;
    public:
        virtual void equip(Personagem &A, Armadura &B);
        virtual void unequip(Personagem &A);
};

#endif // ARMADURA_H

