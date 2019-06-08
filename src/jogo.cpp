#include <iostream>
#include <Personagem.h>
#include <menu.h>
#include <stdio.h>
#include <FuncoesGerais.h>


bool exit_game(int* c){
    std::cout << "Deseja continuar? (1 - SIM / 0 - NAO)" << std::endl;
    checker(c, 1, 0);
    if (*c == 1){
        std::cout << "Game: Boa Escolha forasteiro!" << std::endl;
        return true;
    }else{ 
        exit(0);
        return false;
    }
}
void result_battle(int n, int* fase, int* vidas, int* dinheiro){
    //caso perca a batalha
    if (n == 0){
        *vidas = *vidas - 1;
    }
    //caso ganhe a batalha
    else if(n == 1){
        *fase = *fase + 1;
    }
    //caso fuja da batalha
    else if(n == 3){
        *dinheiro = *dinheiro - 100;
    }
}

void quiz(int* n){
    int op;
    if(*n == 1){
        std::cout << "\nQual o time de futebol que o Clegane menos gosta?\n";
        std::cout << "-------------------------------------------------\n";
		std::cout << "| 1 - Corintians                      2 - Botafogo  |\n";
		std::cout << "|                                                   |\n";
		std::cout << "| 3 - Flamengo                 	    4 - Atlético  |\n";
		std::cout << "-------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);
        if(op == 2){
            std::cout << "Sabio: Vejo que tem um otimo senso de humor. Vou ajuda-lo" << std::endl;
        }
        else{
            std::cout << "Sabio: Eh tao lerdo quanto parece..." << std::endl;
        }
    }
    else if(*n == 2){
        std::cout << "\nO que nos dizemos ao Deus da Morte?" << std::endl;
        std::cout << "-------------------------------------------------------------\n";
		std::cout << "| 1 - Nao assisto Death Note     2 - Sem tempo, irmao        |\n";
		std::cout << "|                                                   	   |\n";
		std::cout << "| 3 - Hoje nao                   4 - Conheca a minha espada  |\n";
		std::cout << "-------------------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

        if(op == 3){
            std::cout << "Melissa: Vejo que de fato conhece os principios do nosso senhor" << std::endl;
        }
        else{
            std::cout << "Melissa: ..." << std::endl;
        }
    }
    else if(*n == 3){
        std::cout << "??? : Vallar Morghulis\n";
        std::cout << "-----------------------------------------------------\n";
		std::cout << "| 1- Nao sei falar russo		3- Valar Dothraki	   |\n";
		std::cout << "|								                       |\n";
		std::cout << "|	2- Valar Doeharis		    4- Bom dia             |\n";	
        std::cout << "------------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

        if(op == 2){
            std::cout << "???: Eh bom encontrar companheiros de causa" << std::endl;
        }
        else{
            std::cout << "???: Eu devo ter te confundido" << std::endl;
        }

    }
    else if(*n == 4){
        std::cout << "Qual o nome de um dos dragoes da Daniela?" << std::endl;
        std::cout << "-----------------------------------------\n";
		std::cout << "| 1- Dracarys			3- Drohgo		   |\n";
		std::cout << "|						        		   |\n";
		std::cout << "|	2- Drogon			4- Dragon		   |\n";
		std::cout << "-----------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

        if(op == 2){
            std::cout << "" << std::endl;
        }
        else{
            std::cout << "" << std::endl;
        }        
    }
    else if(*n == 5){
        std::cout << "Quem eh a mulher vermelha?" << std::endl;
        std::cout << "-----------------------------------------------------\n";
		std::cout << "| 1- Feiticeira Escarlate		3- Melisandre		   |\n";
		std::cout << "|								                       |\n";
		std::cout << "|	2- Red Woman			    4- Sacerdotisa do fogo |\n";
		std::cout << "-----------------------------------------------------\n Sua escolha: ";
		checker(&op, 1, 4);

         if(op == 3){
            std::cout << "" << std::endl;
        }
        else{
            std::cout << "" << std::endl;
        } 
    }
    else {
        std::cout << "Erro na definicao do quiz. Cheque seus parametros. Erro na posicao: " << op << std::endl;
    }
    *n = *n + 1;
}

void get_stage_game(int n, Personagem &player){

    if (n == 1){
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
        // funcao batalha 
        //system("cls"); || system ("clear");

        std::cout << "Eliana: Eu nao precisava da sua ajuda, posso me defender sozinha" << std::endl;
        std::cout << "Narrador:  Eliana vai embora e te deixa sozinho" << std::endl;
        std::cout << "Maria: Parabens! O que achou da sua primeira batalha? Nao importa. Vamos, pegue o dinheiro desses bandidos e vamos embora." << std::endl;
        std::cout << "Voce: Para onde vamos?" << std::endl;
        std::cout << "Maria:  Vamos para a Cidade Velha buscar mais informacoes" <<std::endl;
        std::cout << "Narrador: Assim, seguiram para Cidade Velha, para encontrar com os sabios de la" << std::endl;  
        //system("cls"); || system ("clear");
    
    }
    else if(n == 2){

        std::cout << "\n ~CIDADE VELHA~" << std::endl;
        std::cout << "Maria: Chegamos a cidade velha, vamos procurar alguem para nos ajudar" << std::endl;
        std::cout << "Sabio: Sejam bem vindos. Do que precisam? Tenho que voltar a fazer nada urgentemente" << std::endl;
        std::cout << "Maria: Queremos saber mais sobre o motivo do " << player.get_name() << "ser invocado aqui" << std::endl;
        std::cout << " Sabio: Pois bem. Voce foi invocado para este mundo para derrotar o rei da night e impedir que o nosso reino se torne uma eterna balada sertaneja" << std::endl;
        std::cout << "Voce: humm..." << std::endl;
        std::cout << "Sabio: Antes de tudo quero saber se es digno" << std::endl;

        //chama quiz 1


        std::cout << "A ameaca que procuram esta no norte. Voces devem seguir pelo nosso reino em busca de apoio." << std::endl;
        std::cout << "Sabio: Voces devem primeiro seguir para os Jardins Altos. Ele eh chamado assim porque foi la que Michael Jordan nasceu. Ele eh muito alto." << std::endl;
        std::cout << "Voce: Err... obrigado... eu acho" << std::endl;
        std::cout << "Sabio: Nao acredito que ajudei um otaco. Vao embora daqui, tenho varios nada pra fazer. Adeus" << std::endl;

        std::cout << "\n ~JARDINS ALTOS - LAR DA FAMILIA Tyrell ~ " << std::endl; 
        std::cout << "Narrador: Chegando la encontram com Sir Loiro Jose. Eles explicam a situacao e voce eh desafio para uma batalha" << std::endl;
        std::cout << "Sir Louro Jose: Me prove que eh digno!" << std::endl;

        //funcao batalha 

        std::cout << "Sir Louro Jose: Percebi que eh digno de minha ajuda." << std::endl;
        std::cout << "Voce recebeu x moedas" << std::endl;
        //somar o dinheiro do personagem
        std::cout <<"Maria: Vamos continuar rumo ao norte." << std::endl;

        //*fase++;
    }
    else if(n == 3){
        
        std::cout << "\n ~ARREDORES DA CIDADE DOS REIS - CAPITAL DO REINO~" << std::endl;
        std::cout << "Maria: Acho que estamos perto da capital. Podemos passar por la para procurar apoio" << std::endl;
        std::cout << "\n ~ NA CAPITAL ~ " << std::endl;
        std::cout << "Voce: O que eh todo esse alvoroco?!!" << std::endl;
        std::cout << "Pessoa aleatoria: A mao do rei foi acusada de traicao e vai ser executado" << std::endl;
        std::cout << "Narrador: Neste momento a mao do rei eh decaptado" << std::endl;
        std::cout << "Voce: Ultimamente nao da pra confiar nem na sombra quem dira na mao haha" << std::endl;
        std::cout << "Maria: Cuidado com as suas piadas sem graca, alguem pode perder a cabeca" << std::endl;
        std::cout << "Pessoa aleatoria: Vou sair de perto de voces" << std::endl;

        std::cout << "\n Narrador: Eles decidem que a cidade nao eh muito acolhedora e decidem continuar a sua jornada" << std::endl;
        std::cout << "\n Narrador: No caminho eles encontram com uma mulher vestida de vermelho e ela os aborda" << std::endl;
        std::cout << "???: Meu nome eh Melissa. Meu lorde disse que por aqui encontraria alguem capaz de nos salvar. Mas antes devo ter certeza de que sao voces" <<std::endl;
        //quiz 2
        std::cout << "Narrador: Eles acompanham Melissa ate Pedra de Dinossauro onde esta Saulo Barao" <<std::endl;
        std::cout << "Saulo: Melissa, sao esses??" <<std::endl;
        std::cout << "Melissa: Sim, meu senhor" << std::endl;
        std::cout << "Saulo: Esse dai me parece muito franzino, nao vai aguentar nem um golpe de espada" << std::endl;
        std::cout << "Voce: Vem Tranquilo" << std::endl;
        //funcao batalha
        
        std::cout << "Saulo: Parece que era digno, afinal. Siga para Castelo de Rocha, tenho uma missao para voce: matar Tiao Lago" << std::endl;
        std::cout << "Voce: Porque eu faria isso?" << std::endl;
        std::cout << "Saulo: Porque se me ajudar eu apoiarei a sua causa" << std::endl;
    }
    else if (n == 4){
                
        std::cout << "\n~CASTELO DE ROCHA - LAR DA FAMILIA LAGO~" << std::endl;
        std::cout << "Guarda: Forasteiro, identifique-se" << std::endl;
        std::cout << "Voce: Sou o " << player.get_name() << "venho tratar de negocios com o Lorde Tiao" << std::endl;
        std::cout << "Narrador: Voce tenta convencer o guarda a entrar, mas ele nao deixa. Entao voce se infiltra pelo calabouco e encontra " << std::endl;
        std::cout << "Voce: Tiao, venho em nome de Saulo Barao, voce encontrara o seu fim hoje" << std::endl;    
        std::cout << "Tiao: Quem eh voce?" << std::endl;
        //funcao batalha

        std::cout << "Narrador: Apos derrotar Tiao os guardas vem atras de voce. Voces dois fogem pelo mar e chegam as ilhas de ferro" << std::endl;
        std::cout << "\n ~NO PORTO~" << std::endl;
        std::cout << "Pessoa aleatoria 1 : Saulo cometeu o erro de atacar a cidades dos reis e foi derrotado" << std::endl;
        std::cout << "Pessoa aleatoria 2: Quem eh Saulo?" << std::endl;
        std::cout << "Pessoa aleatoria 1:  Me impressiona sua falta de cultura" << std::endl;
        std::cout << "Pessoa aleatoria 2: Mentira. Eu sei que a mulher dos dragoes vai derrotar todo mundo" << std::endl;
        std::cout << "Pessoa aleatoria 1: Unico dragao que conheco eh a minha esposa com raiva" << std::endl;
        std::cout << "Maria: Saulo foi derrotado, o que faremos agora?" << std::endl;

    }
    else if(n == 5){
        //derrotar a galera das ilhas de ferro
        std::cout << "\n ILHAS DE FERRO - LAR DA FAMILIA GREIJOY" << std::endl;
        std::cout << " Maria: Devemos encontrar o chefe da ilha em busca de apoio." << std::endl;
        std::cout << "Narrador: Voces encontram com o chefe e pedem ajudar, mas ele se recusa." << std::endl;
        std::cout << "**: Voce disse que veio de onde mesmo? Voce parece muito com a descricao do assassino de Tiao Lago." <<std::endl;
        std::cout << "Voce: Eu nao sei do que esta falando" << std::endl;
        std::cout << "**: Voce nao faz ideia da recompensa pela sua cabeca, se eu levar a sua cabeca para a Celia ela com certeza se casara comigo e me tornarei rei" <<std::endl;
        //funcao batalha
        std::cout << "Narrador: Ganha dele e vira amigo do theon q vai levar ele pro norte" << std::endl;

    }
    else if (n == 6){
        //chega no norte e ganha uma espada da pedra do dragao depois luta com o rei da noite
        std::cout << "Narrador: chega no norte conhece a dany, recebe a espada com vidro de dragao e luta contra o rei da noite" <<std::endl;
        //funcao batalha
    }
    else if (n == 7){
        int escolha;
        //escolher entre trair ou apoiar a dani
        std::cout << "Narrador: dany taca fogo em porto real e vc deve escolher entre apoia-la ou trai-la" << std::endl;
        //menu de selecao
        if(escolha == 1){
            //apoia a dany e luta com o jon
        } 
        else if (escolha == 2){
            //trai a dany e luta com ela
        }
        else{
            std::cout <<"Narrador: Acho que voce nao entendeu... vou repetir pra ver se voce eh burro ou sonso" << std::endl;
        }
    }
    
}
