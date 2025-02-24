#include "Etat.h"
#include "automate.h"

using namespace std;

void State0::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case INT:
        a->decalage(s, new State3(3));
        break;
    case OPENPAR:
        a->decalage(s, new State2(2));
        break;
    case 7:
        a->transitionSimple(s, new State1(1));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State1::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case PLUS:
        a->decalage(s, new State4(4));
        break;
    case MULT:
        a->decalage(s, new State5(5));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State2::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case INT:
        a->decalage(s, new State3(3));
        break;
    case OPENPAR:
        a->decalage(s, new State2(2));
        break;
    case 7:
        a->transitionSimple(s, new State6(6));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State3::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case PLUS:
        Expression* newSymbole = new Expression();
        Entier * val = (Entier *)(a->getPileSymboles().top());
        a->getPileSymboles().pop();
        newSymbole->setResult(val->getValeur());
        a->reduction(1, newSymbole);
        break;
    case MULT:
        Expression* newSymbole = new Expression();
        Entier * val = (Entier *)(a->getPileSymboles().top());
        a->getPileSymboles().pop();
        newSymbole->setResult(val->getValeur());
        a->reduction(1, newSymbole);
        break;
    case CLOSEPAR:
        Expression* newSymbole = new Expression();
        Entier * val = (Entier *)(a->getPileSymboles().top());
        a->getPileSymboles().pop();
        newSymbole->setResult(val->getValeur());
        a->reduction(1, newSymbole);
        break;
    case FIN:
        Expression* newSymbole = new Expression();
        Entier * val = (Entier *)(a->getPileSymboles().top());
        a->getPileSymboles().pop();
        newSymbole->setResult(val->getValeur());
        a->reduction(1, newSymbole);
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State4::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case INT:
        a->decalage(s, new State3(3));
        break;
    case OPENPAR:
        a->decalage(s, new State2(2));
        break;
    case 7:
        a->transitionSimple(s, new State7(7));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State5::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {   
    case INT:
        a->decalage(s, new State3(3));
        break;
    case OPENPAR:
        a->decalage(s, new State2(2));
        break;
    case 7:
        a->transitionSimple(s, new State8(8));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State6::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case PLUS:
        a->decalage(s, new State4(4));
        break;
    case MULT:
        a->decalage(s, new State5(5));
        break;
    case CLOSEPAR:
        a->decalage(s, new State9(9));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}

void State7::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case PLUS:
        //reduction
    case MULT:
        a->decalage(s, new State5(5));
        break;
    case CLOSEPAR:
        //reduction
    case FIN:
        //reduction
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}


void State8::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case PLUS:
        //reduction
    
    cout<<"Transition de l'etat "<<id<<endl;
}
}

void State9::transition(Automate * a, Symbole * s) {
    switch (s -> getId())
    {
    case PLUS:
        a->getPileSymboles().pop();
        Expression* newSymbole = new Expression();
        Expression e = (Expression)(a->getPileSymboles().top())
        newSymbole->setResult(.getResult());
        a->getPileSymboles().pop();
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    case MULT:
        a->getPileSymboles().pop();
        Symbole* newSymbole = new Symbole(7);
        newSymbole->setresult(a->getPileSymboles().top().getresult());
        a->getPileSymboles().pop();
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    case CLOSEPAR:
        a->getPileSymboles().pop();
        Symbole* newSymbole = new Symbole(7);
        newSymbole->setresult(a->getPileSymboles().top().getresult());
        a->getPileSymboles().pop();
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    case FIN:
        a->getPileSymboles().pop();
        Symbole* newSymbole = new Symbole(7);
        newSymbole->setresult(a->getPileSymboles().top().getresult());
        a->getPileSymboles().pop();
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat "<<id<<endl;
}