| [Descrição] | [Compilação] | [Tutorial] | [UserStories] | 
|-------------|--------------|------------|---------------|
- - -
# 20191-team-12

Projeto Final da Disciplina de Programação e Desenvolvimento de Software II

## Descrição
Jogo de batalhas estilo RPG, inspirado na série game of thrones, tendo o modo conquista com batalhas 1x1.

## Compilação

**O jogo é compatível apenas para sistemas Mac e Linux.** 
Deve ser feito o Download do repositório na máquina desejada. Após isto, deve acessar o terminal, realizar o caminho até a pasta 20191-team-12, e digitar o comando "make". Em algumas versões de linux e mac, deve ser acrescentado "-B" junto ao comando make.
Tendo isto concluído, o executável será gerado na pasta "bin". Para rodar o programa sem trocar de diretório é só utilizar "./bin/main" (sem as aspas).
Para a realização dos testes a compilação é feita de forma semelhante, porém, adicinando "tests" depois do make.

## Tutorial
O jogo é composto por sete fases, onde cada uma delas possui um boss. Em algumas fases também possuem quizes, com perguntas relacionadas à serie com recompensas pelos acertos. Cada fase começa com uma contextualização e os npcs vão explicando a sua jornada. 
A interface é totalmente textual, dessa forma todos os comandos do usuário são recebidos pelo teclado. Também possui uma loja, na qual podem ser comprados armas, armaduras e poções, e é permitido treinar um numero variável de vezes em cada fase. Ao final de cada fase é exibido os status do personagem e espólios obtidos. Por fim, a todo momento o usuário é permitido sair do jogo ou fugir da batalha (opções no menu).

## UserStories
1.
Sou um jogador iniciante, não tenho conhecimento do funcionamento de RPGs e gosto de jogos que desafiem o meu raciocínio.

    - Ter uma interface clara.
    - Interação para explicar o funcionamento do jogo.
    - Possuir desafios (quiz) para incrementar o funcionamento do jogo.
    - As primeiras batalhas devem ter uma dificuldade mais baixa para treinar os jogadores .

2.
Sou muito fã de Game of Thrones e fiquei sabendo de um RPG inspirado na série. Já sei como funcionam os RPGs e gosto de jogar sozinho. Quero poder incorporar aspectos da minha casa favorita.

    - Ter referencias divertidas da série.
    - Ter a opção de jogar sozinho ou com um amigo.
    - Esquema de batalhas com uma dificuldade crescente para estimular os jogadores mais experientes.
    - Possuir caracteristicas que remetem à ambientação e as casas da série.
    - Possuir habilidades específicas de acordo com a casa/classe.

3.
Sou uma jogadora experiente de RPG e quero jogar um jogo com um tema diferenciado. Quero poder melhorar as habilidades do meu personagem de acordo com o meu gosto. Porém, assisti somente uma temporada de game of thrones (ainda não superei a morte do meu personagem favorito), então conheço pouco de referencias

    - Possibilidade de escolher as habilidades a serem melhoradas.
    - Possibilidade de comprar armas e objetos diferentes para o personagem.
    - Upar o nivel do personagem com o passar das fases.
    - Escolher um atributo a ser melhorado a cada nivel subido.

4.
Sou um entusiasta de jogos de RPG e quero jogar um jogo com um sistema de batalha simples e divertido mas que seja desafiador com a evolução do jogo.

    - Batalhas por turnos e com tempo.
    - Opções de escolha na batalha claras e simples.
    - Atributos e Habilidades divertidas.
    - Inimigos com grau de dificuldade crescente .

5.
Sou um jogador de diferentes tipos de RPG e quero jogar um jogo que me permita comprar itens e equipamentos para personalizar meu personagem ao longo das fases. 

    - Ter um tutorial que explique o funcionamento básico da loja.
    - Ter uma loja com diferentes equipamentos, divididos em classes/casas.
    - Balancear os equipamentos para que não deixem o jogo muito fácil nem muito difícil.
    - Atualizar a loja com novos equipamentos à medida que o jogo progride. 

6.
Sou um amante de jogos e desenvolvedor de software, por isso quero um jogo bem otimizado para rodar em meu computador sem problemas técnicos.

    - Não possuir bugs.
    - Ocupar pouco espaço no HD.
    - Utilizar a memória RAM de forma inteligente, sem desperdícios.
    - Boa estruturação de código para facilitar futuras alterações nas funcionalidades do jogo.

[Descrição]: #descrição
[Compilação]: #compilação
[Tutorial]: #tutorial
[UserStories]: #userstories
