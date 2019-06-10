#include "doctest.h"
#include "Personagem.h"



TEST_CASE("Testando o construtor de personagem") {
  Personagem personagem ("alan turing");
  personagem.set_life(200);
  CHECK_EQ(personagem.get_name(), "alan turing");
  CHECK_EQ(personagem.get_life(), 200);
}

TEST_CASE("Testando o construtor de personagem") {
  
}