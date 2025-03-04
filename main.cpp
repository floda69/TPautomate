#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);
   Automate* a = new Automate(&l);
   a->compute();

   delete a;
   return 0;
}

