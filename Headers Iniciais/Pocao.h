#ifndef POCAO_H
#define POCAO_H

class Pocao{
	protected:
    int i_stamina;
    int i_life;
    int quantity;
	public:
	Pocao();
	Pocao(int _stamina, int _life, int _quantity);
	
    int get_stamina();
    int get_life();
    int get_quantity();
    void set_quantity(int num);
};

#endif
