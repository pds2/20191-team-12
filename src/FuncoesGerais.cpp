#include <iostream>
#include <string>
//#include <system>
#include "FuncoesGerais.h"
#include <math.h>
#include "jogo.h"


#define n_enemies 3

//funcoes jogo

void pausar(){
    //funcao para pausar o texto
    std::cout << "\nPRESSIONE ENTER PARA CONTINUAR"<< std::endl;
    std::cin.get();
    system("clear");
}
bool exit_game(){
    //funcao para sair do jogo
    int c;
    std::cout << "Deseja continuar? (1 - SIM / 0 - NAO)" << std::endl;
    checker(&c, 0, 1);
    if (c == 1){
        std::cout << "Game: Boa Escolha, forasteiro!" << std::endl;
        return true;
    }else{ 
        std::cout << "Game: Adeus, jovem medroso. O seu pai chora no banho ao lembrar que possui um(a) filho(a) covarde..." << std::endl;
        exit(0);
        return false;
    }
}

void quiz(int n, Personagem &player){//quizes chamados nas fases
    int op;
    if(n == 1){
        std::cout << "\nQual o time de futebol que o Clegane menos gosta?\n";
        std::cout << "-------------------------------------------------\n";
		std::cout << "| 1 - Corintians                      2 - Botafogo  |\n";
		std::cout << "|                                                   |\n";
		std::cout << "| 3 - Flamengo                 	    4 - Atlético  |\n";
		std::cout << "-------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);
        if(op == 2){
            std::cout << "Sabio: Vejo que tem um otimo senso de humor. Vou ajuda-lo" << std::endl;
            int cash = reward(2, 1, player);
            std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
        }
        else{
            std::cout << "Sabio: Eh tao lerdo quanto parece..." << std::endl;
        }
    }
    else if(n == 2){
        std::cout << "\nO que nos dizemos ao Deus da Morte?" << std::endl;
        std::cout << "-------------------------------------------------------------\n";
		std::cout << "| 1 - Nao assisto Death Note     2 - Sem tempo, irmao        |\n";
		std::cout << "|                                                   	   |\n";
		std::cout << "| 3 - Hoje nao                   4 - Conheca a minha espada  |\n";
		std::cout << "-------------------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

        if(op == 3){
            std::cout << "Melissa: Vejo que de fato conhece os principios do nosso senhor" << std::endl;
            int cash = reward(3, 2, player);
            std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
        }
        else{
            std::cout << "Melissa: ..." << std::endl;
        }
    }
    else if(n == 3){
        std::cout << "??? : Vallar Morghulis\n";
        std::cout << "-----------------------------------------------------\n";
		std::cout << "| 1- Nao sei falar russo		3- Valar Dothraki	   |\n";
		std::cout << "|								                       |\n";
		std::cout << "|	2- Valar Doeharis		    4- Bom dia             |\n";	
        std::cout << "------------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

        if(op == 2){
            std::cout << "???: Eh bom encontrar companheiros de causa" << std::endl;
            int cash = reward(4, 2, player);
            std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
        }
        else{
            std::cout << "???: Eu devo ter te confundido" << std::endl;
        }

    }
    else if(n == 4){
        std::cout << "Qual o nome de um dos dragoes da Daniela?" << std::endl;
        std::cout << "-----------------------------------------\n";
		std::cout << "| 1- Dracarys			3- Drohgo		   |\n";
		std::cout << "|						        		   |\n";
		std::cout << "|	2- Drogon			4- Dragon		   |\n";
		std::cout << "-----------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

        if(op == 2){
            std::cout << "Narrador: Parabens, Biologo" << std::endl;
            int cash = reward(4, 2, player);
            std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
        }
        else{
            std::cout << "Narrador: errroooou kkkkkk" << std::endl;
        }        
    }
    else if(n == 5){
        std::cout << "Quem eh a mulher vermelha?" << std::endl;
        std::cout << "-----------------------------------------------------\n";
		std::cout << "| 1- Feiticeira Escarlate		3- Melisandre		   |\n";
		std::cout << "|								                       |\n";
		std::cout << "|	2- Red Woman			    4- Sacerdotisa do fogo |\n";
		std::cout << "-----------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

         if(op == 3){
            std::cout << "Narrador: Parabens!" << std::endl;
            int cash = reward(5, 2, player);
            std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
        }
        else{
            std::cout << "Narrador: Voce eh burro, cara... que loucura" << std::endl;
        } 
    }
    else {
        std::cout << "Erro na definicao do quiz. Cheque seus parametros. Erro na posicao: " << op << std::endl;
    }
}
void add_skill_pers(Personagem &player, int fase){//cria e adiciona skills de personagem
    //criando habilidades
    Habilidade voadora(" Voadora",30,10);
    Habilidade kamehameha ("Kamehameha", 40, 15);
    Habilidade katon ("Katon", 70, 25);
    Habilidade choque_trovao ("Choque do trovao", 100, 40);
    Habilidade golem ("Invocar Golem", 67, 50);
    Habilidade soco_saitama ("Soco do Saitama", 220, 50);
    Habilidade dracarys ("Dracarys", 400, 60);
    Habilidade escorpiao ("Atirar escorpiao", 400, 60);

    //adicionando habilidades
    if(fase == 1)
        player.add_skill(voadora);
    else if(fase == 2)
        player.add_skill(kamehameha);
    else if(fase == 3)
        player.add_skill(katon);
    else if(fase == 4)
        player.add_skill(choque_trovao);
    else if (fase == 5)
        player.add_skill(golem);
    else if (fase == 6)
        player.add_skill(soco_saitama);
    else if(fase == 7)
        player.add_skill(dracarys);
    else if(fase == 8)
        player.add_skill(escorpiao);
}
void add_skill_boss(Boss &boss, int fase){//cria e adiciona skills de boss
    //criando habilidades
    Habilidade pedrada(" Pedrada",30,15);
    Habilidade corte_suave (" Corte Suave", 40, 30);
    Habilidade corte_tubarao (" Corte Tubarao", 48, 35);
    Habilidade corte_trovao (" Corte do Trovao", 55, 40);
    Habilidade chute_flam (" Chute flamejante", 67, 50);
    Habilidade furacao (" Furacao de gelo", 120, 120);
    Habilidade dracarys (" Dracarys", 140, 130);
    Habilidade escorpiao (" Atirar Escorpiao", 140, 130);

    //adicionando habilidades
    if(fase == 1)
        boss.set_skill(pedrada);
    else if(fase == 2)
        boss.set_skill(corte_suave);
    else if(fase == 3)
        boss.set_skill(corte_tubarao);
    else if(fase == 4)
        boss.set_skill(corte_trovao);
    else if (fase == 5)
        boss.set_skill(chute_flam);
    else if (fase == 6)
        boss.set_skill(furacao);
    else if(fase == 7)
        boss.set_skill(dracarys);
    else if(fase == 8)
        boss.set_skill(escorpiao);
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

// Validação

void checker(int *variavel, int p1, int p2){//funcao generica para checar opcoes
	int numero = *variavel;
	std::string numero_;
	while(true){
		try{
			std::getline(std::cin, numero_);
			numero = std::atoi(numero_.c_str());

			if(numero < p1 || numero > p2){
				throw "Entrada invalida.";
			} else {
				break;
			}
		} catch(const char* e){
			std::cout << "Erro: " << e << std::endl;
			std::cout << "Escolha uma entrada valida!" << std::endl;
		}
	}
	
	*variavel = numero;
}

int reward(int fase_num, int multiplicador, Personagem &player){ //função de recompensa de ouro
	
	srand (time(NULL));
	const int goldinicial = (rand()% 10 + 10); // varia entre 10 e 20
	float resultado;

	resultado = pow(multiplicador,(fase_num - 1)) * goldinicial;

	player.set_gold((player.get_gold()) + (int)resultado);

    return (int)resultado;
}

