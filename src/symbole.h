#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS",  "MULT",
                             "INT",     "FIN",      "ERREUR"};

class Symbole {
 public:
  Symbole(int i, bool t) : ident(i), terminal(t) {}
  virtual ~Symbole() {}
  operator int() const { return ident; }
  virtual void Affiche();
  bool isTerminal() { return terminal; }

 protected:
  int ident;
  bool terminal;
};

class Entier : public Symbole {
 public:
  Entier(int v) : Symbole(INT), valeur(v) {}
  ~Entier() {}
  virtual void Affiche();

 protected:
  int valeur;
};
