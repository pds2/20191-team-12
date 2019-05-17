#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <string>

class Equipamento{
    public:
        virtual void equip(Personagem &A) = 0;
        virtual void unequip(Personagem &A) = 0;
};

#endif // EQUIPAMENTO_H
