#pragma once
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

class Shunting_Yard {

private:
    string expresie;
    string rezultat;
    Stack operatorStack;
    
public:
    Shunting_Yard();

    Shunting_Yard(string expresie);

    void operator()(string expresie);

    explicit operator string();

    int validareTip(char op);

    int prioritate(char op);

    string calculeaza(string expresie);

    string getRezultat();

    void setExpresie(string expresie);

    string getExpresie();

    friend ostream& operator << (ostream& out, Shunting_Yard& sy);

    friend istream& operator>>(istream& in, Shunting_Yard& sy);
};
