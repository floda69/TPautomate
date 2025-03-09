#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine;
   cout<<"Entrez une expression mathematique : \n";
   cin>>chaine;
   
   Lexer l(chaine);
   Automate* a = new Automate(&l);
   a->compute();

   delete a;
   return 0;
}

