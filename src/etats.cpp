#include "etats.h"

#include <unistd.h>

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

    case EXPR:
      automate.decalage(s, new E1);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
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

    case FIN:  // Accepter
      cout << "Fin" << std::endl;
      return true;
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
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

    case EXPR:
      automate.decalage(s, new E6);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
  }
  return false;
}

bool E3::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    Entier* e1;
    Expr* exp;

    // règle 5 : E -> val
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
      e1 = automate.popSymbol();
      exp = new Expr(e1->getValeur());
      automate.reduction(exp, 1);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
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

    case EXPR:
      automate.decalage(s, new E7);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
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

    case EXPR:
      automate.decalage(s, new E8);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
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

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
  }
  return false;
}

bool E7::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    Entier* e1;
    Entier* e2;
    Expr* exp;

    // Règle 2 : E -> E + E
    case PLUS:
    case CLOSEPAR:
    case FIN:
      e1 = automate.popSymbol();       // E de droite
      automate.popAndDestroySymbol();  // +
      e2 = automate.popSymbol();       // E de gauche
      exp = new Expr(e2->getValeur() + e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;

    case MULT:
      automate.decalage(s, new E5);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
  }
  return false;
}

bool E8::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    Entier* e1;
    Entier* e2;
    Expr* exp;

    // Règle 3 : E -> E * E
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
      e1 = automate.popSymbol();       // E de droite
      automate.popAndDestroySymbol();  // *
      e2 = automate.popSymbol();       // E de gauche
      exp = new Expr(e2->getValeur() * e1->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
  }
  return false;
}

bool E9::transition(Automate& automate, Symbole* s) {
  switch (*s) {
    Entier* e;
    Expr* exp;

    // Règle 4 : E -> ( E )
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
      automate.popAndDestroySymbol();  // )
      e = automate.popSymbol();        // E
      automate.popAndDestroySymbol();  // (
      exp = new Expr(e->getValeur());
      automate.reduction(exp, 3 /* 3 symboles à dépiler */);
      break;

    default:
      automate.decalage(new Symbole(ERREUR, false), nullptr);
      return true;
  }
  return false;
}
