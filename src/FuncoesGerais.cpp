#include <iostream>
#include <string>
#include "FuncoesGerais.h"

// Validação

void checker(int *variavel, int p1, int p2){
	int numero = *variavel;
	std::cin >> numero;
	while(numero < p1 || numero > p2){
		std::cout << "Escolha um numero valido!\n";
		std::cin >> numero;

		if (std::cin.fail()){
         	std::cin.clear();
         	std::cin.ignore(10000, '\n');
			}
		}
	*variavel = numero;
}

// Impressão

std::string adjust_square(std::string to_print, int num){
	to_print.append((num - to_print.size()), ' ');
	return to_print;
}

void print_square(std::string to_print1, std::string to_print2, std::string to_print3, std::string to_print4){
	to_print1 = adjust_square(to_print1, 35);
	to_print2 = adjust_square(to_print2, 35);
	to_print3 = adjust_square(to_print3, 35);
	to_print4 = adjust_square(to_print4, 35);


	std::cout << R"(+-----------------------------------+
|)" << to_print1 << R"(|
|)" << to_print2 << R"(|
|)" << to_print3 << R"(|
|)" << to_print4 << R"(|
+-----------------------------------+)" << std::endl;
}