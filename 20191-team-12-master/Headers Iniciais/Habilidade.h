#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <string>

class Habilidade{
	private:
		int damage;
		int spend;
		std::string name;
	public:
		Habilidade(int, int);
		int get_damage();
		int get_spend();
		std::string get_name();
};

#endif