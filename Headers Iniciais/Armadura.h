#ifndef ARMADURA_H
#define ARMADURA_H

#include "Equipamento.h"

class Armadura : public Equipamento{
    private:
        std::string armor_name;
        float b_life;
        float b_defense;
    public:
        virtual void equip(Personagem &A);
        virtual void unequip(Personagem &A);
};

#endif // ARMADURA_H
