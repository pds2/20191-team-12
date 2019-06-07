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
        cout << "Maria: Queremos saber mais sobre o motivo do " << player.name << "ser invocado aqui" << endl;
        cout << " Sabio: Pois bem. Voce foi invocado para este mundo para derrotar o rei da night e impedir que o nosso reino se torne uma eterna balada sertaneja" << endl;
        cout << "Voce: humm..." << endl;
        cout << "Sabio: Antes de tudo quero saber se es digno" << endl;

        //chama quiz 1


        cout << "A ameaca que procuram esta no norte. Voces devem seguir pelo nosso reino em busca de apoio." << endl;
        cout << "Sabio: Voces devem primeiro seguir para os Jardins Altos. Ele eh chamado assim porque foi la que Michael Jordan nasceu. Ele eh muito alto." << endl;
        cout << "Voce: Err... obrigado... eu acho" << endl;
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
        
        cout << "\n ~ARREDORES DA CIDADE DOS REIS - CAPITAL DO REINO~" << endl;
        cout << "Maria: Acho que estamos perto da capital. Podemos passar por la para procurar apoio" << endl;
        cout << "\n ~ NA CAPITAL ~ " << endl;
        cout << "Voce: O que eh todo esse alvoroco?!!" << endl;
        cout << "Pessoa aleatoria: A mao do rei foi acusada de traicao e vai ser executado" << endl;
        cout << "Narrador: Neste momento a mao do rei eh decaptado" << endl;
        cout << "Voce: Ultimamente nao da pra confiar nem na sombra quem dira na mao haha" << endl;
        cout << "Maria: Cuidado com as suas piadas sem graca, alguem pode perder a cabeca" << endl;
        cout << "Pessoa aleatoria: Vou sair de perto de voces" << endl;

        cout << "\n Narrador: Eles decidem que a cidade nao eh muito acolhedora e decidem continuar a sua jornada" << endl;
        cout << "\n Narrador: No caminho eles encontram com uma mulher vestida de vermelho e ela os aborda" << endl;
        cout << "???: Meu nome eh Melissa. Meu lorde disse que por aqui encontraria alguem capaz de nos salvar. Mas antes devo ter certeza de que sao voces" <<endl;
        //quiz 2
        cout << "Narrador: Eles acompanham Melissa ate Pedra de Dinossauro onde esta Saulo Barao" <<endl;
        cout << "Saulo: Melissa, sao esses??" <<endl;
        cout << "Melissa: Sim, meu senhor" << endl;
        cout << "Saulo: Esse dai me parece muito franzino, nao vai aguentar nem um golpe de espada" << endl;
        cout << "Voce: Vem Tranquilo" << endl;
        //funcao batalha
        
        cout << "Saulo: Parece que era digno, afinal. Siga para Castelo de Rocha, tenho uma missao para voce: matar Tiao Lago" << endl;
        cout << "Voce: Porque eu faria isso?" << endl;
        cout << "Saulo: Porque se me ajudar eu apoiarei a sua causa" << endl;
    else if (n == 4){
                
        cout << "\n~CASTELO DE ROCHA - LAR DA FAMILIA LAGO~" << endl;
        cout << "Guarda: Forasteiro, identifique-se" << endl;
        cout << "Voce: Sou o " << player.name << "venho tratar de negocios com o Lorde Tiao" << endl;
        cout << "Narrador: Voce tenta convencer o guarda a entrar, mas ele nao deixa. Entao voce se infiltra pelo calabouco e encontra "
        cout << "Voce: Tiao, venho em nome de Saulo Barao, voce encontrara o seu fim hoje" << endl;    
        cout << "Tiao: Quem eh voce?" << endl;
        //funcao batalha

        cout << "Narrador: Apos derrotar Tiao os guardas vem atras de voce. Voces dois fogem pelo mar e chegam as ilhas de ferro" << endl;
        cout << "\n ~NO PORTO~" << endl;
        cout << "Pessoa aleatoria 1 : Saulo cometeu o erro de atacar a cidades dos reis e foi derrotado" << endl;
        cout << "Pessoa aleatoria 2: Quem eh Saulo?" << endl;
        cout << "Pessoa aleatoria 1:  Me impressiona sua falta de cultura" << endl;
        cout << "Pessoa aleatoria 2: Mentira. Eu sei que a mulher dos dragoes vai derrotar todo mundo" << endl;
        cout << "Pessoa aleatoria 1: Unico dragao que conheco eh a minha esposa com raiva" << endl;
        cout << "Maria: Saulo foi derrotado, o que faremos agora?" << endl;

    }
    else if(n == 5){
        //derrotar a galera das ilhas de ferro
        cout << "\n ILHAS DE FERRO - LAR DA FAMILIA GREIJOY" << endl;
        cout << " Maria: Devemos encontrar o chefe da ilha em busca de apoio." << endl;
        cout << "Narrador: Voces encontram com o chefe e pedem ajudar, mas ele se recusa." << endl;
        cout << "**: Voce disse que veio de onde mesmo? Voce parece muito com a descricao do assassino de Tiao Lago." <<endl;
        cout << "Voce: Eu nao sei do que esta falando" << endl;
        cout << "**: Voce nao faz ideia da recompensa pela sua cabeca, se eu levar a sua cabeca para a Celia ela com certeza se casara comigo e me tornarei rei" <<endl;
        //funcao batalha
        cout << "";

    }
    else if (n == 6){
        //chega no norte e ganha uma espada da pedra do dragao depois luta com o rei da noite
    }
    else if (n == 7){
        //escolher entre trair ou apoiar a dani
    }
    }
}
