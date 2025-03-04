#pragma once
#include "lexer.h"
#include "Etat.h"
#include <stack>

typedef stack<State*> Etats;
typedef stack<Symbole*> Symboles;

class Automate {
    public:
        Automate(Lexer * l);
        virtual ~Automate();
        void decalage(Symbole * s, State * e);
        void reduction(int n, Symbole * e);
        void transitionSimple(Symbole * s, State * e);
        Symboles& getPileSymboles() { return pileSymboles; }
        State* getCurrentState() {return etatCourant;}
        void compute();
        void setEnd(bool b) {end = b;}
    
    protected:
        Etats pileEtats;
        Symboles pileSymboles;
        State* etatInitial;
        State* etatFinal;
        State* etatCourant;
        Symbole * symboleCourant;
        Lexer * lexer;
        bool end;
};