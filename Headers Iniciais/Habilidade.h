#ifndef HABILIDADE_H
#define HABILIDADE_H

#include <string>

class Habilidade{
	private:
		int damage;
		int spend;
		std::string name;
	public:
		Habilidade(std::string, int, int);
		Habilidade();
		int get_damage();
		int get_spend();
		std::string get_name();
		
		void set_nome(std::string);
		void set_damage(int);
		void set_spend(int);
};

#endif