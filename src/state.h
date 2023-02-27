#pragma once

#include <string>

#include "automate.h"
#include "symbole.h"

class State {
 public:
  State(std::string name);
  virtual ~State();
  void print() const;
  virtual bool transition(Automate& automate, Symbole* s) = 0;

 protected:
  std::string name;
};
