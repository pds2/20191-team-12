#include <iostream>
#include <stdio.h>

#include "Habilidade.h"
#include "Batalha.h"
#include "npc.h"
#include "boss.h"
#include "Personagem.h"
#include "FuncoesGerais.h"
#include "menu.h"

int a = 0;
int b = 10;

void Fase_1(Personagem &player, int& t_num){

    Npc npc_treino("Inimigo", 10, 5, 8, 30);
    Npc enemies[n_enemies];
    for(int i =0; i < n_enemies; i++){
    enemies[i].set_life(50);
    enemies[i].set_defense(8);
    enemies[i].set_max_attack(8);
    enemies[i].set_min_attack(5);
    enemies[i].set_name("Bandido");
    }

    int a = 0;
    
    std::cout << "\n~ALGUM LUGAR NO MAR DE DORNE~ " <<std::endl;
    std::cout << "Maria: Bem Vindo a sua jornada," << player.get_name() << ". Voce foi invocado para este mundo para combater o mal iminente que assola nossos reinos" << std::endl;
    std::cout << "Maria: Eu sou a sarcedotisa Maria e vou lhe auxiliar na sua jornada. Na sua vida anterior voce era um otaku fracassado, mas de alguma forma lhe acharam digno de nos salvar" <<std::endl;
    std::cout << "Voce: Err... " << std::endl;
    std::cout << "Maria: Segundo a profecia, voce tera que passar por 7 provacoes antes de ser livre para voltar ao seu mundo. Primeiro vamos para dorne para conseguir alguns equipamentos." << std::endl;
    std::cout << "Maria: Nao se esqueca: O inverno esta chegando e a C&A tem varias promocoes em casacos" << std::endl;
    
    pausar();


    std::cout <<  "\n~DORNE - LAR DA CASA MACHADO~" << std::endl;
    std::cout << "Maria: Aqui nos resolvemos os nossos conflitos com batalhas. Ao longo do caminho voce tambem podera treinar para aperfeicoar suas habilidades ou ganhar dinheiro" << std::endl;
    std::cout << "Maria: Mercadores tambem estao sempre disponiveis, neles voce pode comprar novas armas, armaduras e pocoes. Tais servicos estarao disponiveis sempre que precisar! Vamos fazer um teste:" <<std::endl;
   
    int op = 1;
    while(op != 0){
        show_menu(player, npc_treino, t_num, 1);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }
    std::cout << "Maria: Agora que voce ja esta preparado, podemos seguir a nossa jornada\n";
    pausar();

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
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_1(player, a);
        }
    }

    std::cout << "Eliana: Eu nao precisava da sua ajuda, posso me defender sozinha" << std::endl;
    std::cout << "Narrador:  Eliana vai embora e te deixa sozinho" << std::endl;
    std::cout << "Maria: Parabens! O que achou da sua primeira batalha? Nao importa. Vamos, pegue o dinheiro desses bandidos e vamos embora." << std::endl;
    std::cout << "Voce: Para onde vamos?" << std::endl;
    std::cout << "Maria:  Vamos para a Cidade Velha buscar mais informacoes" <<std::endl;
    std::cout << "Narrador: Assim, seguiram para Cidade Velha, para encontrar com os sabios de lah" << std::endl;  
    
    int cash = reward(1, 1.5, player);
    add_skill_pers(player, 1);
    
    std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
    std::cout << "Voce recebeu nova habilidade: Voadora" << std::endl;
    
    player.display_stats();
    show_menu_h();
}

void Fase_2(Personagem &player, int& t_num){

    Npc npc_treino("Inimigo", 10, 5, 8, 40);
    Npc enemies[n_enemies];
    for(int i = 0; i < n_enemies; i++){
        enemies[i].set_life(65);
        enemies[i].set_defense(8);
        enemies[i].set_max_attack(10);
        enemies[i].set_min_attack(7);
        enemies[i].set_name("Guarda");
    }
    int a = 0;

    Boss loiro_jose ("Loiro Jose", 20, 15, 12, 100);
    add_skill_boss(loiro_jose, 2);

    pausar();

    std::cout << "\n ~CIDADE VELHA~" << std::endl;
    std::cout << "Maria: Chegamos a cidade velha, vamos procurar alguem para nos ajudar" << std::endl;
    std::cout << "Sabio: Sejam bem vindos. Do que precisam? Tenho que voltar a fazer nada urgentemente" << std::endl;
    std::cout << "Maria: Queremos saber mais sobre o motivo do " << player.get_name() << " ser invocado aqui" << std::endl;
    std::cout << " Sabio: Pois bem. Voce foi invocado para este mundo para derrotar o rei da night e impedir que o nosso reino se torne uma eterna balada sertaneja" << std::endl;
    std::cout << "Voce: humm..." << std::endl;
    std::cout << "Sabio: Antes de tudo quero saber se es digno" << std::endl;

    pausar();

    quiz(1, player);

    pausar();

    std::cout << "Sabio: A ameaca que procuram esta no norte. Voces devem seguir pelo nosso reino em busca de apoio." << std::endl;
    std::cout << "Sabio: Voces devem primeiro seguir para os Jardins Altos. Ele eh chamado assim porque foi la que Michael Jordan nasceu. Ele eh muito alto." << std::endl;
    std::cout << "Voce: Err... obrigado... eu acho" << std::endl;
    std::cout << "Sabio: Nao acredito que ajudei um otaco. Vao embora daqui, tenho varios nada pra fazer. Adeus" << std::endl;

    pausar();

    int op = 1;
    while(op != 0){
        show_menu(player, npc_treino, t_num, 2);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }

    std::cout << "\n ~JARDINS ALTOS - LAR DA FAMILIA TYRELL ~ " << std::endl; 
    std::cout << "Narrador: Chegando la encontram com Sir Loiro Jose. Voces explicam a situacao e voce eh desafiado para uma batalha contra os guardas e depois Sir Loiro" << std::endl;
    std::cout << "Sir Louro Jose: Me prove que eh digno!" << std::endl;

    pausar();

    //funcao batalha 
    for( int i = 0; i < n_enemies; i++){
        int check = batalha(player, enemies[i]);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_2(player, a);
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
            Fase_2(player, a);
        }

    std::cout << "Sir Louro Jose: Percebi que eh digno de minha ajuda." << std::endl;
    std::cout <<"Maria: Vamos continuar rumo ao norte." << std::endl;    

    int cash = reward(2, 1.5, player);
    add_skill_pers(player, 2);
    
    std::cout << "Voce recebeu " << cash << " moedas" << std::endl;
    std::cout << "\nVoce recebeu nova Habilidade: Kamehameha" << std::endl;
    player.display_stats();
    show_menu_h();
    
    pausar();
}

void Fase_3(Personagem &player, int& t_num){

    Npc npc_treino("Inimigo", 10, 5, 8, 50);

    Boss estenio ("Estenio Barao", 23, 15, 12, 250);
    add_skill_boss(estenio, 2);

    int a = 0;

    std::cout << "\n ~ARREDORES DA CIDADE DOS REIS - CAPITAL DO REINO~" << std::endl;
    std::cout << "Maria: Acho que estamos perto da capital. Podemos passar por la para procurar apoio" << std::endl;

    pausar();

    std::cout << "\n ~ NA CAPITAL ~ " << std::endl;
    std::cout << "Voce: O que eh todo esse alvoroco?!!" << std::endl;
    std::cout << "Pessoa aleatoria: A mao do rei foi acusada de traicao e vai ser executado" << std::endl;
    std::cout << "Narrador: Neste momento a mao do rei eh decaptado" << std::endl;
    std::cout << "Voce: Ultimamente nao da pra confiar nem na sombra quem dira na mao haha" << std::endl;
    std::cout << "Maria: Cuidado com as suas piadas sem graca, alguem pode perder a cabeca" << std::endl;
    std::cout << "Pessoa aleatoria: Vou sair de perto de voces" << std::endl;

    pausar();
    quiz(3, player);
    pausar();
    int op = 1;
    while(op != 0){
        show_menu(player, npc_treino, t_num, 3);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }
    pausar();

    std::cout << "\n Narrador: Eles percebem que a cidade nao eh muito acolhedora e continuam a sua jornada" << std::endl;
    std::cout << "\n Narrador: No caminho eles encontram com uma mulher vestida de vermelho e ela os aborda" << std::endl;
    std::cout << "???: Meu nome eh Melissa. Meu lorde disse que por aqui encontraria alguem capaz de nos salvar. Mas antes devo ter certeza de que sao voces" <<std::endl;
    
    quiz(2, player);
    

    pausar();

    std::cout << "Narrador: Eles acompanham Melissa ate Pedra de Dinossauro onde esta Estenio Barao" <<std::endl;
    std::cout << "Estenio: Melissa, sao esses??" <<std::endl;
    std::cout << "Melissa: Sim, meu senhor" << std::endl;
    std::cout << "Estenio: Esse dai me parece muito franzino, nao vai aguentar nem um golpe de espada" << std::endl;
    std::cout << "Voce: Vem Tranquilo" << std::endl;
   
    int check = batalha(player, estenio);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            system ("clear");
        }else{//fugiu, volta a fase do comeco
            Fase_3(player, a);
        }

    std::cout << "Estenio: Parece que era digno, afinal. Siga para Castelo de Rocha, tenho uma missao para voce: matar Tiao Lago" << std::endl;
    std::cout << "Voce: Porque eu faria isso?" << std::endl;
    std::cout << "Estenio: Porque se me ajudar eu apoiarei a sua causa" << std::endl;
    
    int cash = reward(3, 1.5, player);
    add_skill_pers(player, 3);

    std::cout << "\nVoce recebeu nova Habilidade: Katon" << std::endl;
    std::cout << "Voce recebeu " << cash << " moedas" << std::endl;

    player.display_stats();
    show_menu_h();
    pausar();
}

void Fase_4(Personagem &player, int& t_num){

    Npc npc_treino("Inimigo", 10, 5, 8, 50);
    Npc enemies[n_enemies];
    for(int i = 0; i < n_enemies; i++){
        enemies[i].set_life(60);
        enemies[i].set_defense(10);
        enemies[i].set_max_attack(12);
        enemies[i].set_min_attack(10);
        enemies[i].set_name("Guarda");
    }
    int a = 0;

    Boss tiao ("Tiao Lago", 30, 20, 15, 200);
    add_skill_boss(tiao, 3);

    
    
    std::cout << "\n~CASTELO DE ROCHA - LAR DA FAMILIA LAGO~" << std::endl;
    std::cout << "Guarda: Forasteiro, identifique-se" << std::endl;
    std::cout << "Voce: Sou o " << player.get_name() << "venho tratar de negocios com o Lorde Tiao" << std::endl;
    std::cout << "Narrador: Voce tenta convencer o guarda a entrar, mas ele nao deixa. Entao voce se infiltra pelo calabouco e encontra " << std::endl;
    std::cout << "Voce: Tiao, venho em nome de Estenio Barao, voce encontrara o seu fim hoje" << std::endl;    
    std::cout << "Tiao: Quem eh voce?" << std::endl;
    
    pausar();
    int op = 1;
    while(op != 0){
        show_menu(player, npc_treino, t_num, 4);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }
    pausar();

    int check = batalha(player, tiao);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_4(player, a);
        }
    pausar();

    add_skill_pers(player, 4);
    int cash = reward(4, 1.5, player);
    std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
    std::cout << "\nVoce recebeu nova Habilidade: Choque do Trovao" << std::endl;

    pausar();
    quiz(4, player);
    pausar();

    std::cout << "Narrador: Apos derrotar Tiao os guardas vem atras de voce." << std::endl;

    for( int i = 0; i < n_enemies; i++){
        int check = batalha(player, enemies[i]);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_4(player, a);
        }
    }

    std::cout << "Voces dois fogem pelo mar e chegam as ilhas de ferro" << std::endl;
    std::cout << "\n ~NO PORTO~" << std::endl;
    std::cout << "Pessoa aleatoria 1 : Estenio cometeu o erro de atacar a cidades dos reis e foi derrotado" << std::endl;
    std::cout << "Pessoa aleatoria 2: Quem eh Estenio?" << std::endl;
    std::cout << "Pessoa aleatoria 1:  Me impressiona sua falta de cultura" << std::endl;
    std::cout << "Pessoa aleatoria 2: Mentira. Eu sei que a mulher dos dragoes vai derrotar todo mundo" << std::endl;
    std::cout << "Pessoa aleatoria 1: Unico dragao que conheco eh a minha esposa com raiva" << std::endl;
    std::cout << "Maria: Estenio foi derrotado, o que faremos agora?" << std::endl;

    player.display_stats();
    show_menu_h();
    pausar();
}

void Fase_5(Personagem &player, int& t_num){

    Npc npc_treino("Inimigo", 10, 5, 8, 150);
    Npc enemies[n_enemies];
    for(int i = 0; i < n_enemies; i++){
        enemies[i].set_life(70);
        enemies[i].set_defense(8);
        enemies[i].set_max_attack(10);
        enemies[i].set_min_attack(7);
        enemies[i].set_name("Guarda");
    }

    int a = 0;

    Boss euron ("Euron", 20, 12, 12, 150);
    add_skill_boss(euron, 5);

    pausar();
    int op = 1;
    while(op != 0){
        show_menu(player, enemies[0], t_num, 5);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }

    std::cout << "\n ILHAS DE FERRO - LAR DA FAMILIA GREIJOY" << std::endl;
    std::cout << " Maria: Devemos encontrar o chefe da ilha em busca de apoio." << std::endl;
    std::cout << "Narrador: Voces encontram com o chefe e pedem ajudar, mas ele se recusa." << std::endl;
    std::cout << "Euron: Voce disse que veio de onde mesmo? Voce parece muito com a descricao do assassino de Tiao Lago." <<std::endl;
    std::cout << "Voce: Eu nao sei do que esta falando" << std::endl;
    std::cout << "Euron: Voce nao faz ideia da recompensa pela sua cabeca, se eu levar a sua cabeca para a Celia ela com certeza se casara comigo e me tornarei rei" <<std::endl;
    
    for( int i = 0; i < n_enemies; i++){
        int check = batalha(player, enemies[i]);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_5(player, a);
        }
    }

    int check = batalha(player, euron);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_5(player, a);
        }
    

    add_skill_pers(player, 5);
    int cash = reward(5, 1.5, player);

    std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
    std::cout << "\nVoce recebeu nova Habilidade: Invocar Golem" << std::endl;

    pausar();
    quiz(5, player);
    pausar();

    std::cout << "Theo: Voce nao faz ideia de como sou grato!" << std::endl;
    std::cout << "Voce: Quem eh voce?" << std::endl;
    std::cout << "Theo: Policial disfarcado. Enconsta na parede bonita, vou te levar pro norte." << std::endl;
    
    player.display_stats();
    show_menu_h();
    pausar();
}
void Fase_6(Personagem &player, int& t_num){

    Npc npc_treino("Inimigo", 10, 5, 8, 150);
    Npc enemies[n_enemies];
    for(int i = 0; i < n_enemies; i++){
        enemies[i].set_life(80);
        enemies[i].set_defense(8);
        enemies[i].set_max_attack(10);
        enemies[i].set_min_attack(7);
        enemies[i].set_name("Walking Dead");
    }

    int a = 0;

    Boss night_k ("Rei da Night", 80, 50, 40, 2000);
    add_skill_boss(night_k, 6);
    
    std::cout << "Voce: Nossa que frio de congelar pinguim!" << std::endl;
    std::cout << "Maria: Bem vindo ao norte, otario" << std::endl;
    std::cout << "Theo: Venha vou te apresentar os meus amigos. Aqueles la sao o Joao das Neves e a Daniela. A Daniela quer o trono de Westeros. Nao mexa com ela que ela trem tres calango de fogo" << std::endl;
    std::cout << "Voce: E o Joao ?" << std::endl;
    std::cout << "Theo: O Joao tem saude" << std::endl;

    pausar();
    int op = 1;
    while(op != 0){
        show_menu(player, enemies[0], t_num, 6);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }

    std::cout << "Narrador: Passam alguns dias e finalmente, depois de sete temporadas, o rei da night chega a westeros. Voce deve derrota-lo." << std::endl;

    for( int i = 0; i < n_enemies; i++){
        int check = batalha(player, enemies[i]);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_6(player, a);
        }
    }
    int check = batalha(player, night_k);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_4(player, a);
        }
    

    std::cout << "Narrador: apos a batalha todos lhe saudam como heroi. Entretanto, a luta continua. Voce deve apoiar Daniela a tomar o trono de Celia" <<std::endl;
    
    add_skill_pers(player, 6);
    int cash = reward(6, 1.5, player);

    std::cout << "\nVoce recebeu " << cash << " moedas" << std::endl;
    std::cout << "\nVoce recebeu nova Habilidade: Soco do Saitama" << std::endl;

    player.display_stats();
    show_menu_h();
    pausar();
}
void Fase_7(Personagem &player, int& t_num){

    int escolha;
    int op = 1;
    Npc npc_treino("Inimigo", 10, 5, 8, 150);
    Npc enemies[n_enemies];
    for(int i = 0; i < n_enemies; i++){
        enemies[i].set_life(35);
        enemies[i].set_defense(8);
        enemies[i].set_max_attack(10);
        enemies[i].set_min_attack(7);
        enemies[i].set_name("Soldado");
    }

    int a = 0;
    int b = 10;

    pausar();

    while(op != 0){
        show_menu(player, enemies[0], t_num, 1);
        std::cout << "Deseja acessar o menu novamente?(0 - NAO/ 1 - SIM)" << std::endl;
        checker(&op, 0,1);
    }
    std::cout << "Narrador: Daniela faz churrasco de porto real e todos especulam que ela tenha ficado biruta." << std::endl;
    std::cout << "Joao das Neves: *susurro* nao podemos mata-la, ela nos salvou" << std::endl;
    std::cout << "Tiaozinho: e agora vai nos destruir" << std::endl;
    std::cout << "Maria: Oh nao. O que devemos fazer?" << std::endl;
    
    std::cout << "\nVoce deseja trair a Daniela? (1 - Sim/ 0 - Nao)" << std::endl;
    checker(&escolha, 0,1);

    if(escolha == 0){
        std::cout << "Voce: Vamos apoiar Daniela. Nunca gostei desse Joao das Neves" << std::endl;
        add_skill_pers(player, 7);
        std::cout << "\nVoce recebeu nova Habilidade: Dracarys" << std::endl;
        Boss joao ("Joao das Neves", 120, 50, 200, 1500);
        add_skill_boss(joao, 8);
        
        pausar();

        int check = batalha(player, joao);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_7(player, a);
        }
    } 
    else if (escolha == 1){
        std::cout << "Voce: Vamos mata-la. Nunca gostei daquele calango" << std::endl;
        std::cout << "Narrador: Voce se junta aos traidores e lutar contra Daniela" << std::endl;
        std::cout << "\nVoce recebeu nova Habilidade: Atirar Escorpiao" << std::endl;
        Boss daniela ("Daniela", 120, 50, 200, 1500);
        add_skill_boss(daniela, 7);

        pausar();

        int check = batalha(player, daniela);
        if ( check == 0){//perdeu
            pausar();
            std::cout << "\n\nVOCE FOI DERROTADO! OBRIGADO POR JOGAR!!" << std::endl;
            exit(0);
        }else if(check == 1){//ganhou
            std::cout << "\n Parabens pela vitoria!\n"<< std::endl;
            pausar();
        }else{//fugiu, volta a fase do comeco
            pausar();
            Fase_7(player, b);
        }
    }
    else{
        std::cout <<"Narrador: Acho que voce nao entendeu... vou repetir pra ver se voce eh burro ou sonso" << std::endl;
        pausar();
        Fase_7(player, b);
    }
    std::cout << "\nOBRIGADO POR JOGAR!! ESPERO QUE TENHA SE DIVERTIDO!" << std::endl;
}