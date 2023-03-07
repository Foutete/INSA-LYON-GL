#include <iostream>

#include "automate.h"
#include "lexer.h"

int main(void) {
  string chaine;
  cout << "Entrez l'expression à calculer : " << endl;
  cin >> chaine;

  Lexer l(chaine);

  Automate* automate = new Automate(&l);
  automate->run();

  return 0;
}
