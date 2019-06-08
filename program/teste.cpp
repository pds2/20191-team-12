#include <iostream>
#include <stdio.h>
#include <Habilidade.h>
#include <Batalha.h>
#include <npc.h>
#include "boss.h"
#include "Personagem.h"


void Fase_1(Personagem &player){

        Npc soldier("guarda", 10, 5, 3, 50);
        Boss teste("teste", 20, 10, 8, 100);
        Habilidade hab1 ("voadora",12,5);
        teste.set_skill(hab1);
        player.add_skill(hab1);



        std::cout << "~ALGUM LUGAR NO MAR DE DORNE~" <<std::endl;
        std::cout << "Maria: Bem Vindo a sua jornada," << player.get_name() << ". Voce foi invocado para este mundo para combater o mal eminente que assola nossos reinos" << std::endl;
        std::cout << "Maria: Eu sou a sarcedotisa Maria e vou lhe auxiliar na sua jornada. Na sua vida anterior voce era um otaku fracassado, mas de alguma forma lhe acharam digno de nos salvar" <<std::endl;
        std::cout << "Voce: Err... " << std::endl;
        std::cout << "Maria: Segundo a profecia, voce tera que passar por 7 provacoes antes de ser livre para voltar ao seu mundo. Primeiro vamos para dorne para conseguir alguns equipamentos." << std::endl;
        std::cout << "Maria: Nao se esqueca: O inverno esta chegando e a C&A tem varias promocoes em casacos" << std::endl;
        std::cout << "PRESSIONE QUALQUER TECLA PARA CONTINUAR"<< std::endl;
        //system("cls"); || system ("clear");

        std::cout << std::endl << "~DORNE - LAR DA CASA MACHADO~" << std::endl;
        std::cout << "Maria: Aqui nos resolvemos os nossos conflitos com batalhas. Ao longo do caminho voce tambem podera treinar para aperfeicoar suas habilidades ou ganhar dinheiro" << std::endl;
        std::cout << "Maria: Mercadores tambem estao sempre disponiveis, neles voce pode comprar novas armas, armaduras e pocoes. Tais servicos estaram disponiveis sempre que precisar! Vamos fazer um teste:" <<std::endl;
        //show_menu();
        std::cout << "Maria: Agora que voce ja esta preparado, podemos seguir a nossa jornada";
        //system("cls"); || system ("clear");

        std::cout << "??? : *Grito*" << std::endl;
        std::cout << "Maria: Parece que alguem precisa de ajuda. Vamos ver o que esta acontecendo." << std::endl;
        std::cout << "Narrador: Varios homens emboscavam uma mulher enquanto ela lutava com um chicote" << std::endl;
        std::cout << "Eliana: Podem vir! Como se simples homens conseguissem me derrotar!" << std::endl;
        std::cout << "Narrador: Um dos homens covardemente joga areia nos seus olhos e outro a apunha-la pelas costas" <<std::endl;
        std::cout << "Maria: O que esta esperando? Voce deve ajuda-la!!" << std::endl;
        
        if(batalha(player, teste) == 1){
            std::cout << "ganhou";
        }
        else {
            std::cout << "perdeu otario";
        }
    
        //system("cls"); || system ("clear");

        std::cout << "Eliana: Eu nao precisava da sua ajuda, posso me defender sozinha" << std::endl;
        std::cout << "Narrador:  Eliana vai embora e te deixa sozinho" << std::endl;
        std::cout << "Maria: Parabens! O que achou da sua primeira batalha? Nao importa. Vamos, pegue o dinheiro desses bandidos e vamos embora." << std::endl;
        std::cout << "Voce: Para onde vamos?" << std::endl;
        std::cout << "Maria:  Vamos para a Cidade Velha buscar mais informacoes" <<std::endl;
        std::cout << "Narrador: Assim, seguiram para Cidade Velha, para encontrar com os sabios de la" << std::endl;  
        //system("cls"); || system ("clear");
    
}

int main(){
    
    Personagem player("gatuno");
    std::cout << "teste\n";
    Fase_1(player);
}




