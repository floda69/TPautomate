#pragma once
#include <iostream>
#include "symbole.h"
class Automate;

using namespace std;

class State {
    public:
        State() { }
        State(int id) : id(id) { }
        ~State() { }
        virtual void transition(Automate * a, Symbole * s) = 0;
        int getID() { return id; }
    
    protected:
        int id;
};

class State0 : public State {
    public:
        State0(int id) : State(id) { }
        ~State0() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State1 : public State {
    public:
        State1(int id) : State(id) { }
        ~State1() { }
        void transition(Automate * a, Symbole * s) override;
    };
    
class State2 : public State {
    public:
        State2(int id) : State(id) { }
        ~State2() { }
        void transition(Automate * a, Symbole * s) override;
    };       

class State3 : public State {
    public:
        State3(int id) : State(id) { }
        ~State3() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State4 : public State {
    public:
        State4(int id) : State(id) { }
        ~State4() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State5 : public State {
    public:
        State5(int id) : State(id) { }
        ~State5() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State6 : public State {
    public:
        State6(int id) : State(id) { }
        ~State6() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State7 : public State {
    public:
        State7(int id) : State(id) { }
        ~State7() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State8 : public State {
    public:
        State8(int id) : State(id) { }
        ~State8() { }
        void transition(Automate * a, Symbole * s) override;
    };

class State9 : public State {
    public:
        State9(int id) : State(id) { }
        ~State9() { }
        void transition(Automate * a, Symbole * s) override;
    };
