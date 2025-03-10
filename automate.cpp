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
        delete pileEtats.top();
        pileEtats.pop();
    }
    pileSymboles.push(s);
    etatCourant = (pileEtats.top());
    cout<<"---Reduction---"<<endl;
    etatCourant->transition(this, s);
    cout<<"---------------"<<endl;
}

void Automate::transitionSimple(Symbole * s, State * e) {
    pileEtats.push(e);
    etatCourant = (pileEtats.top());
}

void Automate::compute(){
    Symbole * s;
    while(!end) {
        s=lexer->Consulter();
        s->Affiche();
        cout << " - state : " << getCurrentState() ->getID() << endl;
        getCurrentState() -> transition(this,s);
     }
     cout << "L'expression est correcte." << endl;
     cout << "Resultat : " << dynamic_cast<Expression*>(getPileSymboles().top())->getResult() << endl;
}