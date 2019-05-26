#ifndef ARMADURA_H
#define ARMADURA_H

#include <string>

class Armadura{
  private:
  	int id;
    std::string name;
    int b_defense;
    int price;
  public:
    Armadura();
   	Armadura(int id, std::string _name, int _b_defense, int price);

   	int get_id();
   	void set_id(int _id);
    int get_defense();
    void set_defense(int _b_defense);
    std::string get_name();
    void set_name(std::string _name);
    int get_price();
   	void set_price(int _price);
   	void display_armor();

    void equip(Armadura toequip);
    void unequip();
        
};

#endif // ARMADURA_H
