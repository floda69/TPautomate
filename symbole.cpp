#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

double Expression::eval(Expression e, Symbole op) {
   if(op==PLUS) {
      result = result + e.result;
   } else if(op==MULT) {
      result = result * e.result;
   }
   return result;
}