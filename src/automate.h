#pragma once

#include <stack>
#include "symbole.h"
#include "state.h"

class State;

class Automate {
    public:
        void decalage(Symbole * s, State * state);
        void reduction(Symbole * s, State * state);
    protected:
        std::stack<State*> pile;
};