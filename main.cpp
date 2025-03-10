#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine;
   cout<<"Entrez une expression mathematique : \n";
   cin>>chaine;
   
   Lexer * l= new Lexer(chaine);
   Automate* a = new Automate(l);
   a->compute();

   delete a;
   delete l;
   return 0;
}

