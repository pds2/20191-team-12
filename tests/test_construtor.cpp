#include "doctest.h"
#include "Personagem.h"


TEST_CASE("Testando o construtor de personagem") {
  Personagem personagem ("alan turing");
  CHECK_EQ(get_name(), "alan turing");
}

