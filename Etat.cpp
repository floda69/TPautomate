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
    case FIN:
        a->setEnd(true);
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat 1"<<endl;
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
    cout<<"Transition de l'etat 2" <<endl;
}

void State3::transition(Automate * a, Symbole * s) {
    Expression* newSymbole = new Expression();
    Entier * val = dynamic_cast<Entier*>(a->getPileSymboles().top());
    switch (s -> getId())
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        newSymbole->setResult(val->getValeur());
        a->getPileSymboles().pop();
        a->reduction(1, newSymbole);
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat 3"<<endl;
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
    cout<<"Transition de l'etat 4"<<endl;
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
    cout<<"Transition de l'etat 5"<<endl;
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
    cout<<"Transition de l'etat 6"<<endl;
}

void State7::transition(Automate * a, Symbole * s) {
    Expression* e1 ;
    Expression* e2 ;
    Symbole* op ;
    Expression* newSymbole = new Expression();
    switch (s -> getId())
    {
    case PLUS:       
    case CLOSEPAR:
    case FIN:
        e1 = dynamic_cast<Expression*>(a->getPileSymboles().top());
        a->getPileSymboles().pop();
        op = a->getPileSymboles().top();
        a->getPileSymboles().pop();
        e2 = dynamic_cast<Expression*>(a->getPileSymboles().top());
        newSymbole->setResult(e1->eval(*e2, *op));
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    case MULT:
        a->decalage(s, new State5(5));
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat 7"<<endl;
}


void State8::transition(Automate * a, Symbole * s) {
    Expression* e1 ;
    Expression* e2 ;
    Symbole* op ;
    Expression* newSymbole = new Expression();
    switch (s -> getId())
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            e1 = dynamic_cast<Expression*>(a->getPileSymboles().top());
            a->getPileSymboles().pop();
            op = a->getPileSymboles().top();
            a->getPileSymboles().pop();
            e2 = dynamic_cast<Expression*>(a->getPileSymboles().top());
            newSymbole->setResult(e1->eval(*e2, *op));
            a->getPileSymboles().pop();
            a->reduction(3, newSymbole);
            break;
        default:
            break;
        }
    cout<<"Transition de l'etat 8"<<endl;

}

void State9::transition(Automate * a, Symbole * s) {
    Expression* e ;
    Expression* newSymbole = new Expression();
    switch (s -> getId())
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        a->getPileSymboles().pop();
        e = dynamic_cast<Expression*>(a->getPileSymboles().top());
        cout << "mamama" << endl;
        cout << Etiquettes[a->getPileSymboles().top()->getId()];
        newSymbole->setResult(e->getResult());
        cout << "ma" << endl;
        a->getPileSymboles().pop();
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    default:
        break;
    }
    cout<<"Transition de l'etat 9"<<endl;
}