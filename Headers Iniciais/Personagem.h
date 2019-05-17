#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include<string>

class Personagem{
    protected:
        std::string object_name;
        float life;
        float deffense;
        float attack;
        float stamina; // (ou mana?)
        Inventario inventory;
        Armadura armor;
        Arma weapon;
    public:
};

#endif // PERSONAGEM_H

