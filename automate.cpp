#include "automate.h"

Automate::Automate(Lexer * l) {
    lexer = l;
    etatInitial = new State0(0);
    pileEtats.push(etatInitial);
    etatCourant = pileEtats.top();
    end = false;
}

Automate::~Automate() {
    while (pileEtats.size() > 0) {
        delete pileEtats.top();
        pileEtats.pop();
    }
    while (pileSymboles.size() > 0) {
        delete pileSymboles.top();
        pileSymboles.pop();
    }
}

void Automate::decalage(Symbole * s, State * e) {
    pileSymboles.push(s);
    pileEtats.push(e);
    lexer->Avancer();
    etatCourant = (pileEtats.top());
}

void Automate::reduction(int n, Symbole * s) {
    for(int i=0; i<n; i++) {
        delete pileEtats.top();
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