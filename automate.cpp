#include "automate.h"

Automate::Automate(Lexer * l) {
    lexer = l;
    etatInitial = new State0(0); // initialisation de l'automate avec l'état 0
    pileEtats.push(etatInitial);
    etatCourant = pileEtats.top();
    end = false;
}

Automate::~Automate() { //on vide les piles de l'automate (i.e., l'état initial et final et l'expression résultat)
    // libération de la mémoire allouée pour les états
    while (pileEtats.size() > 0) {
        delete pileEtats.top();
        pileEtats.pop();
    }
    // libération de la mémoire allouée pour les symboles
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
        s=lexer->Consulter(); // on regarde le prochain symbole de la tête de lecture
        getCurrentState() -> transition(this,s); // on effectue la transition de l'état en haut de la pile
    }
    if (getCurrentState() ->getID() == 1 && lexer->Consulter()->getId()==FIN) //on vérifie que l'expression ait été correctement lue
    {
        // récupération du résultat de l'expression en haut de la pile des symboles
        cout << "Resultat : " << dynamic_cast<Expression*>(getPileSymboles().top())->getResult() << endl;
    }
    else cerr << "Terminaison anormale du programme;" << endl;
}
