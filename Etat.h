#pragma once
#include <iostream>
#include "symbole.h"
class Automate; //declaration de la classe Automate pour éviter les erreurs de dépendance circulaire

using namespace std;

class State {
    public:

        /**
         * Constructeur par défaut de la classe State
         */
        State() { }

        /**
         * Constructeur de la classe State
         * 
         * @param id l'identifiant de l'état
         */
        State(int id) : id(id) { }

        /**
         * Destructeur de la classe State
         */
        ~State() { }


        /**
         * Getter qui permet de récupérer l'identifiant de l'état.
         * 
         * @return l'identifiant de l'état.
         */
        int getID() { return id; }

        /**
         * Méthode qui permet de faire la transition de l'état courant vers un autre état
         * en fonction du symbole `s`.
         * La méthode est virtuelle pure, elle doit être implémentée par les classes filles.
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        virtual void transition(Automate * a, Symbole * s) = 0;
    
    protected:

        /**
         * Attribut : Identifiant de l'état
         */
        int id;
};

class State0 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 0
         * 
         * @param id l'identifiant de l'état
         */
        State0(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 0
         */
        ~State0() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * INT -> décalage vers l'état 3
         * OPENPAR -> décalage vers l'état 2
         * Symbole non terminal -> transition simple vers l'état 1
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State1 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 1
         *
         * @param id l'identifiant de l'état
         */
        State1(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 1
         */
        ~State1() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * PLUS -> décalage vers l'état 4
         * MULT -> décalage vers l'état 5
         * FIN -> fin de l'automate
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };
    
class State2 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 2
         *  
         * @param id l'identifiant de l'état
         */
        State2(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 2
         */
        ~State2() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * INT -> décalage vers l'état 3
         * OPENPAR -> décalage vers l'état 2
         * Symbole non terminal -> transition simple vers l'état 6
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };       

class State3 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 3
         *  
         * @param id l'identifiant de l'état
         */
        State3(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 3
         */
        ~State3() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * PLUS, MULT, CLOSEPAR, FIN -> réduction de l'expression selon la règle E -> val.
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State4 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 4
         * 
         * @param id l'identifiant de l'état
         */
        State4(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 4
         */
        ~State4() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * INT -> décalage vers l'état 3
         * OPENPAR -> décalage vers l'état 2
         * Symbole non terminal -> transition simple vers l'état 7
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State5 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 5
         *  
         * @param id l'identifiant de l'état
         */
        State5(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 5
         */
        ~State5() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * INT -> décalage vers l'état 3
         * OPENPAR -> décalage vers l'état 2
         * Symbole non terminal -> transition simple vers l'état 8
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State6 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 6
         * 
         * @param id l'identifiant de l'état
         */
        State6(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 6
         */
        ~State6() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * PLUS -> décalage vers l'état 4
         * MULT -> décalage vers l'état 5
         * CLOSEPAR -> décalage vers l'état 9
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State7 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 7
         * 
         * @param id l'identifiant de l'état
         */
        State7(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 7
         */
        ~State7() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * PLUS, CLOSEPAR, FIN -> réduction de l'expression selon la règle E -> E + E.
         * MULT -> décalage vers l'état 5
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State8 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 8
         * 
         * @param id l'identifiant de l'état
         */
        State8(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 8
         */
        ~State8() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * PLUS, MULT, CLOSEPAR, FIN -> réduction de l'expression selon la règle E -> E * E.
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };

class State9 : public State {
    public:

        /**
         * Constructeur de la classe fille pour l'état 9
         * 
         * @param id l'identifiant de l'état
         */
        State9(int id) : State(id) { }

        /**
         * Destructeur de la classe fille pour l'état 9
         */
        ~State9() { }

        /**
         * Surcharge de la méthode transition.
         * Méthode qui permet de faire la transition de l'état courant vers un autre état.
         * PLUS, MULT, CLOSEPAR, FIN -> réduction de l'expression selon la règle E -> (E).
         * autre -> affiche un message d'erreur et met fin à l'automate
         * 
         * @param a pointeur vers un objet de type `Automate` qui sera utilisé pour effectuer la transition.
         * @param s pointeur vers un objet de type `Symbole` qui sera utilisé pour effectuer la transition.
         */
        void transition(Automate * a, Symbole * s) override;
    };
