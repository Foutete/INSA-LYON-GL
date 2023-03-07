#include "etats.h"

#include <iostream>

E0::E0() : State("E0") {}
E1::E1() : State("E1") {}
E2::E2() : State("E2") {}
E3::E3() : State("E3") {}
E4::E4() : State("E4") {}
E5::E5() : State("E5") {}
E6::E6() : State("E6") {}
E7::E7() : State("E7") {}
E8::E8() : State("E8") {}
E9::E9() : State("E9") {}

bool E0::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.decalage(s, new E3);
      break;
    case OPENPAR:
      automate.decalage(s, new E2);
      break;
  }
  return false;
}

bool E1::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    case PLUS:
      automate.decalage(s, new E4);
      break;
    case MULT:
      automate.decalage(s, new E5);
      break;
    case FIN:
      cout << "Fin";
  }
  return false;
}

bool E2::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.decalage(s, new E3);
      break;
    case OPENPAR:
      automate.decalage(s, new E2);
      break;
  }
  return false;
}

bool E3::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    // règle 5 : E -> val
    case PLUS:
      Entier * e1 = automate.popSymbol();
      Expr * exp = new Expr(e1->getValeur());
      automate.reduction(exp, 1);
      break;
    case MULT:
      Entier * e1 = automate.popSymbol();
      Expr * exp = new Expr(e1->getValeur());
      automate.reduction(exp, 1);
      break;
    case CLOSEPAR:
      Entier * e1 = automate.popSymbol();
      Expr * exp = new Expr(e1->getValeur());
      automate.reduction(exp, 1);
      break;
    case FIN:
      Entier * e1 = automate.popSymbol();
      Expr * exp = new Expr(e1->getValeur());
      automate.reduction(exp, 1);
      break;
  }
  return false;
}

bool E4::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.decalage(s, new E3);
      break;
    case OPENPAR:
      automate.decalage(s, new E2);
      break;
  }
  return false;
}

bool E5::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    case INT:
      automate.decalage(s, new E3);
      break;
    case OPENPAR:
      automate.decalage(s, new E2);
      break;
  }
  return false;
}

bool E6::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    case PLUS:
      automate.decalage(s, new E4);
      break;
    case MULT:
      automate.decalage(s, new E5);
      break;
    case CLOSEPAR:
      automate.decalage(s, new E9);
      break;
  }
  return false;
}

bool E7::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    // Règle 2 : E -> E + E
    case PLUS:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // +
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() + e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case MULT:
      automate.decalage(s, new E5);
      break;
    case CLOSEPAR:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // +
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() + e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case FIN:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // +
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() + e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
  }
  return false;
}

bool E8::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    // Règle 3 : E -> E * E
    case PLUS:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // *
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() * e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case MULT:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // *
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() * e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);      
      break;
    case CLOSEPAR:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // *
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() * e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case FIN:
      Entier * e1 = automate.popSymbol(); // E de droite
      automate.popAndDestroySymbol();  // *
      Entier * e2 = automate.popSymbol(); // E de gauche
      Expr * exp = new Expr(e2->getValeur() * e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
  }
  return false;
}

bool E9::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    // Règle 4 : E -> ( E )
    case PLUS:
      automate.popAndDestroySymbol();  // )
      Entier * e = automate.popSymbol(); // E
      automate.popAndDestroySymbol();  // (
      Expr * exp = new Expr(e->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case MULT:
      automate.popAndDestroySymbol();  // )
      Entier * e = automate.popSymbol(); // E
      automate.popAndDestroySymbol();  // (
      Expr * exp = new Expr(e->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case CLOSEPAR:
      automate.popAndDestroySymbol();  // )
      Entier * e = automate.popSymbol(); // E
      automate.popAndDestroySymbol();  // (
      Expr * exp = new Expr(e->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
    case FIN:
      automate.popAndDestroySymbol();  // )
      Entier * e = automate.popSymbol(); // E
      automate.popAndDestroySymbol();  // (
      Expr * exp = new Expr(e->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;
  }
  return false;
}
