#include <iostream>

#include "lexer.h"
#include "automate.h"

int main(void) {
  string chaine;
  cout << "Entrez l'expression à calculer : " << endl;
  cin >> chaine;

  Lexer l(chaine);

  Symbole* s;
  while (*(s = l.Consulter()) != FIN) {
    s->Affiche();
    cout << endl;
    l.Avancer();
  }

  Automate * automate = new Automate(&l);
  automate->run();

  return 0;
}
