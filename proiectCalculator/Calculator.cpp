#include <iostream>
#include <string>
#include "Calculator.h"
#include "Shunting_Yard.h"
using namespace std;

Calculator::Calculator() {
    this->expresie = '\0';
    this->rezultat = '\0';
}

Calculator::Calculator(string expresie) {
    this->expresie = expresie;
    rezultat = '\0';
}

//operator !

bool Calculator::operator!()
{
    bool ok = this->rezultat.length() > 0 ? true : false;
    return ok;
}

int Calculator::operator[](int index)
{
    if (index >= 0 && index < (rezultat.length() - 1))
    {
        return rezultat[index];
    }
    else {
        cout << "Valoarea index-ului este negativa sau mai mare decat lungimea totala a rezultatului!";
    }
}

void Calculator::setExpresie(string expresie) {

    if (expresie.length() > 0)
    this->expresie = expresie;
}

string Calculator::getExpresie() {
    return expresie;
}

void Calculator::calculeaza() {
    
    Shunting_Yard z;
    rezultat = z.calculeaza(expresie);
}

string Calculator::getRezultat() {
    return this->rezultat;
}


