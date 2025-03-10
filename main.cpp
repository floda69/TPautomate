#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(123*4+789)+2");

   Lexer l(chaine);
   Automate* a = new Automate(&l);
   a->compute();

   delete a;
   return 0;
}

