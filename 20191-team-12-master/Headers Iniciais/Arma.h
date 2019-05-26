#ifndef ARMA_H
#define ARMA_H

#include <string>

class Arma{
  private:
    int id;
    std::string name;
    int b_attack;
    int price;
  public:
    Arma();
    Arma(int _id, std::string _name, int _b_attack, int _price);

    int get_id();
    void set_id(int _id);
    int get_attack();
    void set_attack(int _attack);
    std::string get_name();
    void set_name(std::string _name);
    int get_price();
    void set_price(int _price);
    void display_weapon();

    void equip(Arma toequip);
    void unequip();
};

#endif // ARMADURA_H
