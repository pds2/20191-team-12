#include <iostream>
#include <Personagem.h>
#include <Allegro.h>

using namespace std

bool exit(&c){
    cout << "Deseja continuar? (1 - SIM / 0 - NAO)" << endl;
    checker(&c, 1, 0);
    if (c)
        return TRUE;
    else 
        return FALSE;
}

void get_stage_game(int n){

    if (n == 1){
        cout << "~ALGUM LUGAR NO MAR DE DORNE~" <<endl;
        cout << "Maria: Bem Vindo a sua jornada," << player.name << ". Voce foi invocado para este mundo para combater o mal eminente que assola nossos reinos" << endl;
        cout << "Maria: Eu sou a sarcedotisa Maria e vou lhe auxiliar na sua jornada. Na sua vida anterior voce era um otaku fracassado, mas de alguma forma lhe acharam digno de nos salvar" <<endl;
        cout << "Voce: Err... " << endl;
        cout << "Maria: Segundo a profecia, voce tera que passar por 7 provacoes antes de ser livre para voltar ao seu mundo. Primeiro vamos para dorne para conseguir alguns equipamentos." << endl;
        cout << "Maria: Nao se esqueca: O inverno esta chegando e a C&A tem varias promocoes em casacos" << endl;
        
        //pressione alguma tecla para continuar
        cout << endl << "~DORNE - LAR DA CASA MACHADO~" << endl;
        
        cout << "Maria: Aqui nos resolvemos os nossos conflitos com batalhas. Ao longo do caminho voce tambem podera treinar para aperfeicoar suas habilidades ou ganhar dinheiro" << endl;
        cout << "Maria: Mercadores tambem estao sempre disponiveis, neles voce pode comprar novas armas, armaduras e pocoes. Tais servicos estaram disponiveis sempre que precisar! Vamos fazer um teste:" <<endl;
        show_menu();
        cout << "Maria: Agora que voce ja esta preparado, podemos seguir a nossa jornada"

        //pressione alguma tecla para continuar
        cout << "??? : *Grito*" << endl;
        cout << "Maria: Parece que alguem precisa de ajuda. Vamos ver o que esta acontecendo." << endl;
        cout << "Narrador: Varios homens emboscavam uma mulher enquanto ela lutava com um chicote"
        cout << "Eliana: Podem vir! Como se simples homens conseguissem me derrotar!" < endl;
        cout << "Narrador: Um dos homens covardemente joga areia nos seus olhos e outro a apunha-la pelas costas" <<endl;
        cout << "Maria: O que esta esperando? Voce deve ajuda-la!!" << endl;
        // funcao batalha 

        //pressione alguma tecla para continuar
        cout << "Eliana: Eu nao precisava da sua ajuda, posso me defender sozinha" << endl;
        cout << "Narrador:  Eliana vai embora e te deixa sozinho" << endl;
        cout << "Maria: Parabens! O que achou da sua primeira batalha? Nao importa. Vamos, pegue o dinheiro desses bandidos e vamos embora." << endl;
        cout << "Voce: Para onde vamos?" << endl;
        cout << "Maria:  Vamos para a Cidade Velha buscar mais informacoes" <<endl;
        cout << "Narrador: Assim, seguiram para Cidade Velha, para encontrar com os sabios de la" << endl;  

        //limpar a tela
    
    }
    else if(n == 2){
        Fase 2

        cout << "\n ~CIDADE VELHA~" << endl;
        cout << "Maria: Chegamos a cidade velha, vamos procurar alguem para nos ajudar" << endl;
        cout << "Sabio: Sejam bem vindos. Do que precisam? Tenho que voltar a fazer nada urgentemente" << endl;
        cout << "Maria: Queremos saber mais sobre o motivo do " << player.name << ser invocado aqui" << endl;
        cout << " Sabio: Pois bem. Voce foi invocado para este mundo para derrotar o rei da night e impedir que o nosso reino se torne uma eterna balada sertaneja" << endl;
        cout << "Voce: "humm..." << endl;
        cout << "Maria: Deseja ajudar a nossa causa?" << endl;
        cin >> op;

        //exibir menu de escolha (0/1) sair/continuar

        cout << "Sabio: Antes de tudo quero saber se es digno" << endl;

        //chama quiz 1


        cout << "A ameaca que procuram esta no norte. Voces devem seguir pelo nosso reino em busca de apoio." << endl;
        cout << "Sabio: Voces devem primeiro seguir para os Jardins Altos. Ele eh chamado assim porque foi la que Michael Jordan nasceu. Ele eh muito alto." << endl;
        cout << "Voce: Err... arigato eu acho" << endl;
        cout << "Sabio: Nao acredito que ajudei um otaco. Vao embora daqui, tenho varios nada pra fazer. Adeus" << endl;

        cout << "\n ~JARDINS ALTOS - LAR DA FAMILIA Tyrell ~ " << endl; 
        cout << "Narrador: Chegando la encontram com Sir Loiro Jose. Eles explicam a situacao e voce eh desafio para uma batalha" << endl;
        cout << "Sir Louro Jose: Me prove que eh digno!" << endl;

        //funcao batalha 

        cout << "Sir Louro Jose: Percebi que eh digno de minha ajuda." << endl;
        cout << "Voce recebeu x moedas" << endl;
        //somar o dinheiro do personagem
        cout <<"Maria: Vamos continuar rumo ao norte." << endl;

        //*fase++;
    }
    else if(n == 3){
        
        cout << "\n ~ARREDORES DA CIDADE DOS REIS~" << endl;
        cout << "Maria: Acho que estamos perto da capital. Podemos passar por la para procurar apoio" << endl;
        cout << "Guarda: Forasteiros sao proibidos" << endl;
        cout << "Voce: Como assim? Precisamos ver o rei!!" << endl;
        cout << "Guarda: Sofremos um ataque recentemente. Ninguem entra ate segundas ordens." << endl;
              
        
        cout << "\n~CASTELO DE ROCHA - LAR DA FAMILIA LAGO~" << endl;
        cout <<
    }
}
