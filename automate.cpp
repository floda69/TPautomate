#include "automate.h"

Automate::Automate(Lexer * l) {
    lexer = l;
    pileEtats.push(0);
    etatInitial = State0(0);
    etatCourant = etatInitial;
    etatFinal = State1(1);
}

Automate::~Automate() {
}

void Automate::decalage(Symbole * s, State * e) {
    pileSymboles.push(*s);
    pileEtats.push(e->getID());
    lexer->Avancer();
}

void Automate::reduction(int n, Symbole * s) {
    for(int i=0; i<n; i++) {
        pileEtats.pop();
    }
    pileSymboles.push(*s);
    etatCourant = pileEtats.top();
    etatCourant.transition(this, s);
}

void Automate::transitionSimple(Symbole * s, State * e) {
    pileSymboles.push(*s);
    pileEtats.push(e->getID());
}