#pragma once
#include <iostream>
#include <string>
using namespace std;

class Calculator {
private:
    string expresie;
    string rezultat;

public:
    Calculator();

    Calculator(string expresie);

    bool operator!();

    int operator[](int index);

    void setExpresie(string expresie);
    
    string getExpresie();

    void calculeaza();

    string getRezultat();

    friend istream& operator>>(istream& in, Calculator& c);

    friend ostream& operator << (ostream& out, Calculator& c);    
};