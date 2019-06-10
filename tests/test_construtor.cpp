#include "doctest.h"
#include "Personagem.h"
#include "Arma.h"
#include "Inventario.h"
#include "npc.h"
#include "Habilidade.h"
#include "boss.h"



TEST_CASE("Testando o Construtor de Arma"){
  Arma A;
  CHECK_EQ(A.get_id() , 0);
  CHECK_EQ(A.get_name() , "Sem arma");
  CHECK_EQ(A.get_attack() , 0);
  CHECK_EQ(A.get_price(), 0);

  Arma B(1,"Espada", 80, 50);
  CHECK_EQ(B.get_id() , 1);
  CHECK_EQ(B.get_name() ,  "Espada");
  CHECK_EQ(B.get_attack(), 80);
  CHECK_EQ(B.get_price() , 50);
}

TEST_CASE("Testando Setters e Getters de Arma"){
	Arma A;
	A.set_name("Faca");
	CHECK_EQ(A.get_name() , "Faca");
	A.set_price(20);
	CHECK_EQ(A.get_price() , 20);
	A.set_attack(35);
	CHECK_EQ(A.get_attack() , 35);
	A.set_id(5);
	CHECK_EQ(A.get_id() , 5);
}

TEST_CASE("Testando Construtor de Armadura"){
	Armadura A(3, "Roupa", 20, 5);
	CHECK_EQ(A.get_id() , 3);
	CHECK_EQ(A.get_name() , "Roupa");
	CHECK_EQ(A.get_defense() , 20);
	CHECK_EQ(A.get_price() , 5);

	Armadura B;
  	CHECK_EQ(B.get_id() , 0);
  	CHECK_EQ(B.get_name() ,  "Sem armadura");
  	CHECK_EQ(B.get_defense() , 0);
  	CHECK_EQ(B.get_price() , 0 );
}

TEST_CASE("Testando o Construtor de Personagem") {
	Personagem P ("Alan Turing");
	CHECK_EQ(P.get_name(), "Alan Turing");
	CHECK_EQ(P.get_life(), 100);
	CHECK_EQ(P.get_defense(),20);
	CHECK_EQ(P.get_attack(), 20);
	CHECK_EQ(P.get_stamina(), 100);

	Personagem Z("Jack", 500,200,150,1000);
	CHECK_EQ(Z.get_name(),"Jack");
	CHECK_EQ(Z.get_attack(), 150);
	CHECK_EQ(Z.get_life(), 500);
	CHECK_EQ(Z.get_defense(), 200);
 	CHECK_EQ(Z.get_stamina(), 1000);
}

TEST_CASE("Testando Construtor de Npc"){
 	Npc N;
 	CHECK_EQ(N.get_max_attack(), 0);
 	CHECK_EQ(N.get_min_attack(),0);
 	CHECK_EQ(N.get_defense(), 0);
 	CHECK_EQ(N.get_life(), 0);
 	
 	Npc C("Soldado", 30, 25, 50, 80);
 	CHECK_EQ(C.get_name(), "Soldado");
 	CHECK_EQ(C.get_max_attack(), 30);
 	CHECK_EQ(C.get_min_attack(), 25);
 	CHECK_EQ(C.get_defense(), 50);
 	CHECK_EQ(C.get_life(), 80);
}

TEST_CASE("Testando Setters e Getters de Npc"){
 	Npc N;
 	N.set_name("Guarda");
 	N.set_max_attack(40);
 	N.set_min_attack(35);
 	N.set_defense(50);
 	N.set_life(100);

 	CHECK_EQ(N.get_name(), "Guarda");
 	CHECK_EQ(N.get_max_attack(), 40);
 	CHECK_EQ(N.get_min_attack(), 35);
 	CHECK_EQ(N.get_defense(), 50);
 	CHECK_EQ(N.get_life(),100);
 	CHECK_EQ(N.type(), 0);
}

TEST_CASE("Testando Construtor de Habilidade"){
	Habilidade H;
	Habilidade J("Habilidade", 50, 30);

	CHECK_EQ(H.get_name(), "Habilidade Nula");
	CHECK_EQ(H.get_damage(), 0);
	CHECK_EQ(H.get_spend(), 0);

	CHECK_EQ(J.get_name(), "Habilidade");
	CHECK_EQ(J.get_damage(), 50);
	CHECK_EQ(J.get_spend(), 30);
}

TEST_CASE("Testando Construtor de Boss"){
	Boss B("Chefe", 80, 70, 60, 75);

	CHECK_EQ(B.get_name(), "Chefe");
	CHECK_EQ(B.get_max_attack(), 80);
	CHECK_EQ(B.get_min_attack(), 70);
	CHECK_EQ(B.get_defense(), 60);
	CHECK_EQ(B.get_life(), 75);
}

TEST_CASE("Testando metodos de Boss"){
	Boss B ("Champ", 0, 0, 0, 0);
	Habilidade H("Soco", 30, 5);
	B.set_skill(H);
	B.set_max_attack(150);
	B.set_min_attack(130);
	B.set_defense(100);
	B.set_life(200);
	CHECK_EQ(B.get_max_attack(), 150);
	CHECK_EQ(B.get_min_attack(), 130);
	CHECK_EQ(B.get_defense(), 100);
	CHECK_EQ(B.get_life(), 200);
	CHECK_EQ(B.type(), 1);
	CHECK_EQ(B.get_hdamage(), 30);
	CHECK_EQ(B.get_hspend(), 5);
}