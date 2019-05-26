#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <string>

class Equipamento {
public:
    virtual void equip(Equipamento *toequip) = 0;
    virtual void unequip() = 0;
};

#endif // EQUIPAMENTO_H
