#include <iostream>
#include <string>
//#include <system>
#include "FuncoesGerais.h"

// Validação

void checker(int *variavel, int p1, int p2){
	int numero = *variavel;
	
	while(true){
		try{
			std::cin >> numero;
			if(std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				throw "Entrada invalida";
			} else if(numero < p1 || numero > p2){
				throw "Entrada invalida.";
			} else {
				break;
			}
		}
		catch(const char* e){
			std::cout << "Erro: " << e << std::endl;
			std::cout << "Escolha uma entrada valida!" << std::endl;
		}
	}
	
	*variavel = numero;
}

// Impressão

/*std::string adjust_square(std::string to_print, int num){
	to_print.append((num - to_print.size()), ' ');
	return to_print;
}*/

/*void print_square(std::string to_print1, std::string to_print2, std::string to_print3, std::string to_print4){
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
}*/

//Continuar ou Abandonar

void exit(){

	int numero = -1;

	std::cout << "Voce tem certeza que deseja abandonar o jogo?" << std::endl;
	std::cout << "Digite 0 para NAO ABANDONAR ou 1 para ABANDONAR" << std::endl;
	
	checker(&numero, 0, 1);
	if(numero == 0){ // 0 -> Não abandonar o jogo
		return;
	}else{
		return;
		std::cout << "Adeus, jovem medroso. O seu pai chora no banho ao lembrar que possui um(a) filho(a) covarde..." << std::endl;
  		//system("PAUSE"); EM WINDOWS
  		//system("CLS"); EM WINDOWS
	}
}
