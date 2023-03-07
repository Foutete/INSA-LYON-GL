#include "automate.h"

#include "state.h"

Automate::Automate(Lexer* lexer) { lexer = lexer; }

void Automate::decalage(Symbole* s, State* state) {
  pileEtats.push_back(state);
  pileSymboles.push_back(s);
  if (s->isTerminal()) {
    lexer->Avancer();
  }
}

void Automate::reduction(Symbole* s, int n) {
  for (int i = 0; i < n; i++) {
    delete (pileEtats.back());
    pileEtats.pop_back();
  }
  pileEtats.back()->transition(*this, s);  // TODO ->transition(*this,s);
}

void Automate::run() {}

void Automate::popAndDestroySymbol() {
  delete (pileSymboles.back());
  pileSymboles.pop_back();
}
