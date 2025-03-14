#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      int getId() { return ident; }
   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur() { return valeur; }
   protected:
      int valeur;
};

//Classe pour le symbole non terminal d'id 7 qui correspond à une expression comprenant son résultat
class Expression : public Symbole {
   public:
      Expression() : Symbole(7), result(0) { }
      ~Expression() { }
      double eval(Expression, Symbole);
      double getResult() { return result; }
      void setResult(double r) { result = r; }
   protected:
      double result;
};

