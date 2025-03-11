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
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        a->setEnd(true);
        break;
    }
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
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        a->setEnd(true);
        break;
    }
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
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        a->setEnd(true);
        break;
    }
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
        delete a->getPileSymboles().top();
        a->getPileSymboles().pop();
        a->reduction(1, newSymbole);
        break;
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        a->setEnd(true);
        break;
    }
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
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    }
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
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        a->setEnd(true);
        break;
    }
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
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        a->setEnd(true);
        break;
    }
}

void State7::transition(Automate * a, Symbole * s) {
    Expression* e1 ;
    Expression* e2 ;
    Symbole* op ;
    switch (s -> getId())
    {
    case PLUS:       
    case CLOSEPAR:
    case FIN:
        e1 = dynamic_cast<Expression*>(a->getPileSymboles().top());
        a->getPileSymboles().pop();//on ne delete pas tout de suite les symboles car on les utilise pour calculer la nouvelle expression
        op = a->getPileSymboles().top();
        a->getPileSymboles().pop();
        e2 = dynamic_cast<Expression*>(a->getPileSymboles().top());
        a->getPileSymboles().pop();
        e1->eval(*e2, *op);
        delete e2;
        delete op;
        a->reduction(3, e1);
        break;
    case MULT:
        a->decalage(s, new State5(5));
        break;
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        
        a->setEnd(true);
        break;
    }
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
            a->getPileSymboles().pop();//on ne delete pas tout de suite les symboles car on les utilise pour calculer la nouvelle expression
            op = a->getPileSymboles().top();
            a->getPileSymboles().pop();
            e2 = dynamic_cast<Expression*>(a->getPileSymboles().top());
            a->getPileSymboles().pop();
            newSymbole->setResult(e1->eval(*e2, *op));
            delete e1;
            delete e2;
            delete op;
            a->reduction(3, newSymbole);
            break;
        case ERREUR:
            cout << "Erreur : Symbole inconnu au caractere ";
            cout << a->getLexerHead();
            cout << ";" << endl;
            a->setEnd(true);
            break;
        default:
            cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
            cout << a->getLexerHead();
            cout << ";" << endl;
            a->setEnd(true);
            break;
        }

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
        delete a->getPileSymboles().top();
        a->getPileSymboles().pop();
        e = dynamic_cast<Expression*>(a->getPileSymboles().top());
        newSymbole->setResult(e->getResult());
        delete a->getPileSymboles().top();
        a->getPileSymboles().pop();
        delete a->getPileSymboles().top();
        a->getPileSymboles().pop();
        a->reduction(3, newSymbole);
        break;
    case ERREUR:
        cout << "Erreur : Symbole inconnu au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;
        a->setEnd(true);
        break;
    default:
        cout << "Erreur : " << Etiquettes[s->getId()] << " incorrecte au caractere ";
        cout << a->getLexerHead();
        cout << ";" << endl;        
        a->setEnd(true);
        break;
    }
}