#include "automate.h"

Automate::Automate(Lexer * l) {
    lexer = l;
    etatInitial = new State0(0);
    pileEtats.push(etatInitial);
    etatCourant = etatInitial;
    etatFinal = new State1(1);
    end = false;
}

Automate::~Automate() {
    delete (etatInitial);
    delete (etatFinal);
}

void Automate::decalage(Symbole * s, State * e) {
    pileSymboles.push(s);
    pileEtats.push(e);
    lexer->Avancer();
    etatCourant = (pileEtats.top());
}

void Automate::reduction(int n, Symbole * s) {
    for(int i=0; i<n; i++) {
        pileEtats.pop();
    }
    pileSymboles.push(s);
    etatCourant = (pileEtats.top());
    etatCourant->transition(this, s);
}

void Automate::transitionSimple(Symbole * s, State * e) {
    pileEtats.push(e);
    etatCourant = (pileEtats.top());
}

void Automate::compute(){
    Symbole * s;
    while(!end) {
        s=lexer->Consulter();
        getCurrentState() -> transition(this,s);
    }
    if (getCurrentState() ->getID() == 1 && lexer->Consulter()->getId()==FIN)
    {
        cout << "Resultat : " << dynamic_cast<Expression*>(getPileSymboles().top())->getResult() << endl;
    }
    else cout << "Terminaison anormale du programme;" << endl;
}