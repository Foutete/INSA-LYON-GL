#pragma once

#include <vector>

#include "symbole.h"
#include "lexer.h"

class State;

class Automate {
 public:
  void decalage(Symbole* s, State* state);
  void reduction(Symbole* s, int n);
  Automate(Lexer * lexer);

 protected:
  std::vector<State*> pileEtats;
  std::vector<Symbole*> pileSymboles;
  Lexer * lexer;
};