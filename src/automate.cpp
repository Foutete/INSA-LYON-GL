#include "automate.h"

#include <iostream>

#include "etats.h"
#include "state.h"

Automate::Automate(Lexer* lexer) { this->lexer = lexer; }

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
  pileEtats.back()->transition(*this, s);
}

void Automate::run() {
  bool syntaxe = true;
  Symbole* s;
  pileEtats.push_back(new E0());  // Initialisation du premier état
  while (syntaxe) {
    if (*s != FIN) {
      s = lexer->Consulter();
      lexer->Avancer();
    }
    syntaxe = pileEtats.back()->transition(*this, s);
  }
  if (*pileSymboles.back() == ERREUR) {
    std::cout << "Erreur syntaxique" << std::endl;
  } else {
    std::cout << "Résultat : " << pileSymboles.front()->getValeur()
              << std::endl;
  }
}

void Automate::popAndDestroySymbol() {
  delete (pileSymboles.back());
  pileSymboles.pop_back();
}

Entier* Automate::popSymbol() {
  Entier* entier = (Entier*)pileSymboles.back();
  pileSymboles.pop_back();
  return entier;
}
