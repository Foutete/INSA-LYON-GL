#include <iostream>
#include "state.h"
#include "automate.h"
#include "symbole.h"

class E0 : public State {
    public:
        E0();
        bool transition(Automate & automate, Symbole * s);
};

class E1 : public State {
    public:
        E1();
        bool transition(Automate & automate, Symbole * s);
};

class E2 : public State {
    public:
        E2();
        bool transition(Automate & automate, Symbole * s);
};

class E3 : public State {
    public:
        E3();
        bool transition(Automate & automate, Symbole * s);
};

class E4 : public State {
    public:
        E4();
        bool transition(Automate & automate, Symbole * s);
};

class E5 : public State {
    public:
        E5();
        bool transition(Automate & automate, Symbole * s);
};

class E6 : public State {
    public:
        E6();
        bool transition(Automate & automate, Symbole * s);
};

class E7 : public State {
    public:
        E7();
        bool transition(Automate & automate, Symbole * s);
};

class E8 : public State {
    public:
        E8();
        bool transition(Automate & automate, Symbole * s);
};

class E9 : public State {
    public:
        E9();
        bool transition(Automate & automate, Symbole * s);
};

E0::E0() : State("E0"){}
E1::E1() : State("E1"){}
E2::E2() : State("E2"){}
E3::E3() : State("E3"){}
E4::E4() : State("E4"){}
E5::E5() : State("E5"){}
E6::E6() : State("E6"){}
E7::E7() : State("E7"){}
E8::E8() : State("E8"){}
E9::E9() : State("E9"){}


bool E0::transition(Automate & automate, Symbole * s) {
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

bool E1::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case FIN:
            cout<<"Fin";
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
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

bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.reduction(s, new E5);
            break;
        case MULT:
            automate.reduction(s, new E5);
            break;
        case CLOSEPAR:
            automate.reduction(s, new E5);
            break;
        case FIN:
            automate.reduction(s, new E5);
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
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

bool E5::transition(Automate & automate, Symbole * s) {
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

bool E6::transition(Automate & automate, Symbole * s) {
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

bool E7::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.reduction(s, new E2);
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.reduction(s, new E2);
            break;
        case FIN:
            automate.reduction(s, new E2);
            break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.reduction(s, new E3);
            break;
        case MULT:
            automate.reduction(s, new E3);
            break;
        case CLOSEPAR:
            automate.reduction(s, new E3);
            break;
        case FIN:
            automate.reduction(s, new E3);
            break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.reduction(s, new E4);
            break;
        case MULT:
            automate.reduction(s, new E4);
            break;
        case CLOSEPAR:
            automate.reduction(s, new E4);
            break;
        case FIN:
            automate.reduction(s, new E4);
            break;
    }
    return false;
}
