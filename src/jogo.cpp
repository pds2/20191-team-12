#include <iostream>
#include <stdio.h>

#include "Habilidade.h"
#include "Batalha.h"
#include "npc.h"
#include "boss.h"
#include "Personagem.h"
#include "FuncoesGerais.h"
#include "menu.h"

#define n_enemies 3


void pausar(){
    //funcao para pausar o texto
    char c;
    std::cout << "\nPRESSIONE ENTER PARA CONTINUAR"<< std::endl;
    c = std::cin.get();
    system("clear");
}
bool exit_game(){
    int c;
    std::cout << "Deseja continuar? (1 - SIM / 0 - NAO)" << std::endl;
    checker(&c, 0, 1);
    if (c == 1){
        std::cout << "Game: Boa Escolha forasteiro!" << std::endl;
        return true;
    }else{ 
        exit(0);
        return false;
    }
}
void result_battle(int n, Personagem &player, int fase){
    //caso perca a batalha
    if (n == 0){
        pausar();
        std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
        exit(0);
    }
    //caso ganhe a batalha
    else if(n == 1){
        std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
        pausar();
    }
    //caso fuja da batalha
    else if(n == 3){
        std::cout << "\n\nchegou aqui\n\n";
        switch (fase) {
            case 1:
                Fase_1(player, 0);
                break;
            case 2:
                Fase_2(player, 0);
                break;
            case 3:
                Fase_3(player, 0);
                break;
            case 4:
                Fase_4(player, 0);
                break;
            case 5:
                Fase_5(player, 0);
                break;
            case 6:
                Fase_6(player, 0);
                break;
            default:
                Fase_7(player, 0);
        }
    }
}

void quiz(int n){
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
            std::cout << "" << std::endl;
        }
        else{
            std::cout << "" << std::endl;
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
            std::cout << "" << std::endl;
        }
        else{
            std::cout << "" << std::endl;
        } 
    }
    else {
        std::cout << "Erro na definicao do quiz. Cheque seus parametros. Erro na posicao: " << op << std::endl;
    }
}
void add_skill_pers(Personagem &player, int fase){
    //criando habilidades
    Habilidade voadora(" Voadora",30,15);
    Habilidade kamehameha ("Kamehameha", 40, 30);
    Habilidade katon ("Katon", 48, 35);
    Habilidade choque_trovao ("Choque do trovao", 55, 40);
    Habilidade golem ("Invocar Golem", 67, 50);
    Habilidade soco_saitama ("Soco do Saitama", 120, 120);
    Habilidade dracarys ("Dracarys", 140, 130);
    Habilidade escorpiao ("Atirar escorpiao", 140, 130);

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
void add_skill_boss(Boss &boss, int fase){
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
        boss.set_skill(escorpiao);
    else if(fase == 8)
        boss.set_skill(dracarys);
}
void Fase_1(Personagem &player, int t_num){

    Npc enemies[n_enemies];
    for(int i =0; i < n_enemies; i++){
    enemies[i].set_life(30);
    enemies[i].set_defense(8);
    enemies[i].set_max_attack(8);
    enemies[i].set_min_attack(5);
    enemies[i].set_name("Bandido");
    }
    
    add_skill_pers(player, 1);
    

    std::cout << "\n~\33[1;33mALGUM LUGAR NO MAR DE DORNE\33[m!~ " <<std::endl;
    std::cout << "Maria: Bem Vindo a sua jornada," << player.get_name() << ". Voce foi invocado para este mundo para combater o mal iminente que assola nossos reinos" << std::endl;
    std::cout << "Maria: Eu sou a sarcedotisa Maria e vou lhe auxiliar na sua jornada. Na sua vida anterior voce era um otaku fracassado, mas de alguma forma lhe acharam digno de nos salvar" <<std::endl;
    std::cout << "Voce: Err... " << std::endl;
    std::cout << "Maria: Segundo a profecia, voce tera que passar por 7 provacoes antes de ser livre para voltar ao seu mundo. Primeiro vamos para dorne para conseguir alguns equipamentos." << std::endl;
    std::cout << "Maria: Nao se esqueca: O inverno esta chegando e a C&A tem varias promocoes em casacos" << std::endl;
    pausar();
    //pausar();
    //system ("clear");

    std::cout << std::endl << "~DORNE - LAR DA CASA MACHADO~" << std::endl;
    std::cout << "Maria: Aqui nos resolvemos os nossos conflitos com batalhas. Ao longo do caminho voce tambem podera treinar para aperfeicoar suas habilidades ou ganhar dinheiro" << std::endl;
    std::cout << "Maria: Mercadores tambem estao sempre disponiveis, neles voce pode comprar novas armas, armaduras e pocoes. Tais servicos estaram disponiveis sempre que precisar! Vamos fazer um teste:" <<std::endl;
   
    int op;
    while(op != 0){
        show_menu(player, enemies[0], t_num, 1);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }
    std::cout << "Maria: Agora que voce ja esta preparado, podemos seguir a nossa jornada\n";
    pausar();
    //system ("clear");

    std::cout << "??? : *Grito*" << std::endl;
    std::cout << "Maria: Parece que alguem precisa de ajuda. Vamos ver o que esta acontecendo." << std::endl;
    std::cout << "Narrador: Tres homens emboscavam uma mulher enquanto ela lutava com um chicote" << std::endl;
    std::cout << "Eliana: Podem vir! Como se simples homens conseguissem me derrotar!" << std::endl;
    std::cout << "Narrador: Um dos homens covardemente joga areia nos seus olhos e outro a apunha-la pelas costas" <<std::endl;
    std::cout << "Maria: O que esta esperando? Voce deve ajuda-la!!" << std::endl;
    pausar();

    for( int i = 0; i < n_enemies; i++){
        int check = batalha(player, enemies[i]);
        //result_battle(check, player, 1);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            system ("clear");
        }else{//fugiu, volta a fase do comeco
            Fase_1(player, 0);
        }
    }
    
    pausar();

    std::cout << "Eliana: Eu nao precisava da sua ajuda, posso me defender sozinha" << std::endl;
    std::cout << "Narrador:  Eliana vai embora e te deixa sozinho" << std::endl;
    std::cout << "Maria: Parabens! O que achou da sua primeira batalha? Nao importa. Vamos, pegue o dinheiro desses bandidos e vamos embora." << std::endl;
    std::cout << "Voce: Para onde vamos?" << std::endl;
    std::cout << "Maria:  Vamos para a Cidade Velha buscar mais informacoes" <<std::endl;
    std::cout << "Narrador: Assim, seguiram para Cidade Velha, para encontrar com os sabios de la" << std::endl;  
    
    std::cout << "\nVoce recebeu nova habilidade: kamehameha" << std::endl;
   
    add_skill_pers(player, 2);
}

void Fase_2(Personagem &player, int t_num){

    Npc enemies[n_enemies];
    for(int i = 0; i < n_enemies; i++){
        enemies[i].set_life(30);
        enemies[i].set_defense(4);
        enemies[i].set_max_attack(10);
        enemies[i].set_min_attack(7);
        enemies[i].set_name("Guarda");
    }

    Boss loiro_jose ("Loiro Jose", 10, 12, 6, 80);
    add_skill_boss(loiro_jose, 2);

    pausar();
    system ("clear");

    std::cout << "\n ~CIDADE VELHA~" << std::endl;
    std::cout << "Maria: Chegamos a cidade velha, vamos procurar alguem para nos ajudar" << std::endl;
    std::cout << "Sabio: Sejam bem vindos. Do que precisam? Tenho que voltar a fazer nada urgentemente" << std::endl;
    std::cout << "Maria: Queremos saber mais sobre o motivo do " << player.get_name() << " ser invocado aqui" << std::endl;
    std::cout << " Sabio: Pois bem. Voce foi invocado para este mundo para derrotar o rei da night e impedir que o nosso reino se torne uma eterna balada sertaneja" << std::endl;
    std::cout << "Voce: humm..." << std::endl;
    std::cout << "Sabio: Antes de tudo quero saber se es digno" << std::endl;

    pausar();
    system ("clear");

    quiz(1);

    std::cout << "A ameaca que procuram esta no norte. Voces devem seguir pelo nosso reino em busca de apoio." << std::endl;
    std::cout << "Sabio: Voces devem primeiro seguir para os Jardins Altos. Ele eh chamado assim porque foi la que Michael Jordan nasceu. Ele eh muito alto." << std::endl;
    std::cout << "Voce: Err... obrigado... eu acho" << std::endl;
    std::cout << "Sabio: Nao acredito que ajudei um otaco. Vao embora daqui, tenho varios nada pra fazer. Adeus" << std::endl;

    pausar();
    //pausar();
    system ("clear");

    int op;
    while(op != 0){
        show_menu(player, enemies[0], t_num, 1);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }

    std::cout << "\n ~JARDINS ALTOS - LAR DA FAMILIA Tyrell ~ " << std::endl; 
    std::cout << "Narrador: Chegando la encontram com Sir Loiro Jose. Voces explicam a situacao e voce eh desafiado para uma batalha contra os guardas e depois Sir Loiro" << std::endl;
    std::cout << "Sir Louro Jose: Me prove que eh digno!" << std::endl;

    pausar();
    system ("clear");

    //funcao batalha 
    for( int i = 0; i < n_enemies; i++){
        int check = batalha(player, enemies[i]);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            system ("clear");
        }else{//fugiu, volta a fase do comeco
            Fase_1(player, 0);
        }
    }

    int check = batalha(player, loiro_jose);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            system ("clear");
        }else{//fugiu, volta a fase do comeco
            Fase_2(player, 0);
        }
    pausar();
    system ("clear");

    std::cout << "Sir Louro Jose: Percebi que eh digno de minha ajuda." << std::endl;
    int cash = reward(2, 20);
    
    std::cout << "Voce recebeu" << cash << " moedas" << std::endl;
    std::cout <<"Maria: Vamos continuar rumo ao norte." << std::endl;    
}

void Fase_3(Personagem &player, int t_num){

    std::cout << "\n ~ARREDORES DA CIDADE DOS REIS - CAPITAL DO REINO~" << std::endl;
    std::cout << "Maria: Acho que estamos perto da capital. Podemos passar por la para procurar apoio" << std::endl;
    std::cout << "\n ~ NA CAPITAL ~ " << std::endl;
    std::cout << "Voce: O que eh todo esse alvoroco?!!" << std::endl;
    std::cout << "Pessoa aleatoria: A mao do rei foi acusada de traicao e vai ser executado" << std::endl;
    std::cout << "Narrador: Neste momento a mao do rei eh decaptado" << std::endl;
    std::cout << "Voce: Ultimamente nao da pra confiar nem na sombra quem dira na mao haha" << std::endl;
    std::cout << "Maria: Cuidado com as suas piadas sem graca, alguem pode perder a cabeca" << std::endl;
    std::cout << "Pessoa aleatoria: Vou sair de perto de voces" << std::endl;


    pausar();
    system("clear");

    std::cout << "\n Narrador: Eles decidem que a cidade nao eh muito acolhedora e decidem continuar a sua jornada" << std::endl;
    std::cout << "\n Narrador: No caminho eles encontram com uma mulher vestida de vermelho e ela os aborda" << std::endl;
    std::cout << "???: Meu nome eh Melissa. Meu lorde disse que por aqui encontraria alguem capaz de nos salvar. Mas antes devo ter certeza de que sao voces" <<std::endl;
    
    quiz(2);

    pausar();
    system("clear");

    std::cout << "Narrador: Eles acompanham Melissa ate Pedra de Dinossauro onde esta Estenio Barao" <<std::endl;
    std::cout << "Estenio: Melissa, sao esses??" <<std::endl;
    std::cout << "Melissa: Sim, meu senhor" << std::endl;
    std::cout << "Estenio: Esse dai me parece muito franzino, nao vai aguentar nem um golpe de espada" << std::endl;
    std::cout << "Voce: Vem Tranquilo" << std::endl;
    //funcao batalha
    
    pausar();
    system("clear");

    std::cout << "Estenio: Parece que era digno, afinal. Siga para Castelo de Rocha, tenho uma missao para voce: matar Tiao Lago" << std::endl;
    std::cout << "Voce: Porque eu faria isso?" << std::endl;
    std::cout << "Estenio: Porque se me ajudar eu apoiarei a sua causa" << std::endl;
    int cash = reward(3, 30);
    std::cout << "Voce recebeu" << cash << " moedas" << std::endl;
}

void Fase_4(Personagem &player, int t_num){
    std::cout << "\n~CASTELO DE ROCHA - LAR DA FAMILIA LAGO~" << std::endl;
    std::cout << "Guarda: Forasteiro, identifique-se" << std::endl;
    std::cout << "Voce: Sou o " << player.get_name() << "venho tratar de negocios com o Lorde Tiao" << std::endl;
    std::cout << "Narrador: Voce tenta convencer o guarda a entrar, mas ele nao deixa. Entao voce se infiltra pelo calabouco e encontra " << std::endl;
    std::cout << "Voce: Tiao, venho em nome de Estenio Barao, voce encontrara o seu fim hoje" << std::endl;    
    std::cout << "Tiao: Quem eh voce?" << std::endl;
    
    pausar();
    system("clear");
    //funcao batalha


    int cash = reward(3, 30);
    std::cout << "Voce recebeu" << cash << " moedas" << std::endl;

    pausar();
    system("clear");

    std::cout << "Narrador: Apos derrotar Tiao os guardas vem atras de voce. Voces dois fogem pelo mar e chegam as ilhas de ferro" << std::endl;
    std::cout << "\n ~NO PORTO~" << std::endl;
    std::cout << "Pessoa aleatoria 1 : Estenio cometeu o erro de atacar a cidades dos reis e foi derrotado" << std::endl;
    std::cout << "Pessoa aleatoria 2: Quem eh Estenio?" << std::endl;
    std::cout << "Pessoa aleatoria 1:  Me impressiona sua falta de cultura" << std::endl;
    std::cout << "Pessoa aleatoria 2: Mentira. Eu sei que a mulher dos dragoes vai derrotar todo mundo" << std::endl;
    std::cout << "Pessoa aleatoria 1: Unico dragao que conheco eh a minha esposa com raiva" << std::endl;
    std::cout << "Maria: Estenio foi derrotado, o que faremos agora?" << std::endl;


}

void Fase_5(Personagem &player, int t_num){
    //derrotar a galera das ilhas de ferro
    std::cout << "\n ILHAS DE FERRO - LAR DA FAMILIA GREIJOY" << std::endl;
    std::cout << " Maria: Devemos encontrar o chefe da ilha em busca de apoio." << std::endl;
    std::cout << "Narrador: Voces encontram com o chefe e pedem ajudar, mas ele se recusa." << std::endl;
    std::cout << "**: Voce disse que veio de onde mesmo? Voce parece muito com a descricao do assassino de Tiao Lago." <<std::endl;
    std::cout << "Voce: Eu nao sei do que esta falando" << std::endl;
    std::cout << "**: Voce nao faz ideia da recompensa pela sua cabeca, se eu levar a sua cabeca para a Celia ela com certeza se casara comigo e me tornarei rei" <<std::endl;
    //funcao batalha
    std::cout << "Theo: Voce nao faz ideia de como sou grato!" << std::endl;
    std::cout << "Voce: Quem eh voce?" << std::endl;
    std::cout << "Theo: Policial disfarcado. Enconsta na parede bonita, vou te levar pro norte." << std::endl;
    
}
void Fase_6(Personagem &player, int t_num){
    //chega no norte e ganha uma espada da pedra do dragao depois luta com o rei da noite
    std::cout << "Voce: Nossa que frio de congelar pinguim!" << std::endl;
    std::cout << "Maria: Bem vindo ao norte, otario" << std::endl;
    std::cout << "Theo: Venha vou te apresentar os meus amigos. Aqueles la sao o Joao das Neves e a Daniela. A Daniela quer o trono de Westeros. Nao mexa com ela que ela trem tres calango de fogo" << std::endl;
    std::cout << "Voce: E o Joao ?" << std::endl;
    std::cout << "Theo: O Joao tem saude" << std::endl;

    std::cout << "Narrador: Passam alguns dias e finalmente, depois de sete temporadas, o rei da night chega a westeros. Voce deve derrota-lo." << std::endl;

    //funcao batalha

    std::cout << "Narrador: apos a batalha todos lhe saudam como heroi. Entretanto, a luta continua. Voce deve apoiar Daniela a tomar o trono de Celia" <<std::endl;
    //recebe coisas
}
void Fase_7(Personagem &player, int t_num){
    int escolha;
    //escolher entre trair ou apoiar a dani
    std::cout << "Narrador: Daniela faz churrasco de porto real e todos especulam que ela tenha ficado biruta." << std::endl;
    std::cout << "Joao das Neves: *susurro* nao podemos mata-la, ela nos salvou" << std::endl;
    std::cout << "Tiaozinho: e agora vai nos destruir" << std::endl;
    std::cout << "Maria: Oh nao. O que devemos fazer?" << std::endl;
  
    //menu de selecao
    if(escolha == 1){
        std::cout << "Voce: Vamos apoiar Daniela. Nunca gostei desse Joao das Neves" << std::endl;
        //batalha
    } 
    else if (escolha == 2){
        std::cout << "Voce: Vamos mata-la. Nunca gostei daquele calango" << std::endl;
        std::cout << "Narrador: Voce se junta aos traidores e luta contra Daniela" << std::endl;
    }
    else{
        std::cout <<"Narrador: Acho que voce nao entendeu... vou repetir pra ver se voce eh burro ou sonso" << std::endl;
        Fase_7(player, 10);
        pausar();
        system("clear");
    }
}