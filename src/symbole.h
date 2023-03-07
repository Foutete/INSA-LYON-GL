#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, EXPR, ERREUR };

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT",
                             "INT",     "FIN",      "EXPR", "ERREUR"};

class Symbole {
 public:
  Symbole(int i, bool t) : ident(i), terminal(t) {}
  virtual ~Symbole() {}
  operator int() const { return ident; }
  virtual void Affiche();
  bool isTerminal() { return terminal; }
  virtual int getValeur() { return -1; }

 protected:
  int ident;
  bool terminal;
};

class Entier : public Symbole {
 public:
  Entier(int v) : Symbole(INT, true), valeur(v) {}
  ~Entier() {}
  virtual void Affiche();
  int getValeur() override { return valeur; }

 protected:
  int valeur;
};

class Expr : public Symbole {
 public:
  Expr(int v) : Symbole(EXPR, false) { valeur = v; }
  virtual ~Expr() {}
  int getValeur() override { return valeur; }

 protected:
  int valeur;
};
