#pragma once
#include "lexer.h"
#include "Etat.h"
#include <stack>


typedef stack<State*> Etats; // Pile d'états
typedef stack<Symbole*> Symboles; // Pile de symboles

class Automate {
    public:
       
        /**
         * Constructeur de la classe.
         *
         * @param l pointeur vers un objet de type `Lexer` qui sera utilisé pour
         *     analyser la chaîne d'entrée.
         */
        Automate(Lexer * l);

        /**
         * Destructeur de la classe.
         */
        virtual ~Automate();

        /**
         * Setter qui permet de définir la valeur de l'attribut `end`.
         */
        void setEnd(bool b) {end = b;}

        /**
         * Getter qui permet de récupérer la pile d'états.
         * 
         * @return la pile d'états.
         */
        Symboles& getPileSymboles() { return pileSymboles; }

        /**
         * Getter qui permet de récupérer l'état courant.
         * 
         * @return l'état courant.
         */
        State* getCurrentState() {return etatCourant;}

        /**
         * Getter qui permet de récupérer la tete du lexer
         * 
         * @return l'entier correspondant à la dernière lecture.
         */
        int getLexerHead() {return lexer->getTete();} 

        /**
         * Méthode qui permet de faire le décalage d'état de l'automate.
         * Ajoute le symbole `s` à la pile de symboles, l'état `e` à la pile d'états
         * et fait avancer le lexer pour la prochaine lecture.
         * 
         * @param s pointeur vers un objet de type `Symbole` qui sera ajouté à la pile de symboles.
         * @param e pointeur vers un objet de type `State` qui sera ajouté à la pile d'états.
         */
        void decalage(Symbole * s, State * e);

        /**
         * Méthode qui permet de faire la réduction d'état de l'automate.
         * Supprime `n` états de la pile d'états, ajoute le symbole `s` à la pile de symboles
         * et effectue la prochaine transition.
         * 
         * @param n nombre d'états à supprimer de la pile d'états.
         * @param e pointeur vers un objet de type `Symbole` qui sera ajouté à la pile de symboles.
         */
        void reduction(int n, Symbole * e);

        /**
         * Méthode qui permet de faire une transition simple de l'automate.
         * Ajoute l'état `e` à la pile d'états.
         * 
         * @param s pointeur vers un objet de type `Symbole` (non utilisé).
         * @param e pointeur vers un objet de type `State` qui sera ajouté à la pile d'états.
         */
        void transitionSimple(Symbole * s, State * e);

        /**
         * Méthode qui gère les cycles de l'automate.
         * Lecture tant que l'automate n'a pas atteint un état final.
         * Affiche le résultat si l'automate a atteint l'état final.
         * Affiche un message d'erreur si l'automate a terminé de manière anormale.
         */
        void compute();
    
    protected:

        /**
         * Attributs de la classe.
         */
        Etats pileEtats;
        Symboles pileSymboles;
        State* etatInitial; 
        State* etatFinal;
        State* etatCourant;
        Symbole * symboleCourant;
        Lexer * lexer;
        bool end;
};