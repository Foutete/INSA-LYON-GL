#include "automate.h"


Automate::Automate(Lexer * lexer) {
    lexer = lexer;
}

void Automate::decalage(Symbole* s, State* state) {
    pileEtats.push_back(state);
    pileSymboles.push_back(s);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(Symbole* s, State* state) {}
