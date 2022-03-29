#include <iostream>
#include <string>
#include "Shunting_Yard.h"
using namespace std;


Shunting_Yard::Shunting_Yard() {
    expresie = '\0';
    rezultat = '\0';
    operatorStack;
};

Shunting_Yard::Shunting_Yard (string expresie) : Shunting_Yard:: Shunting_Yard() {
    if (expresie.length() > 0)
    {
        this->expresie = expresie;
    }
}

void Shunting_Yard::operator()(string expresie)
{
    if (this->expresie.length() == 0)
    {
        this->expresie = expresie;
    }
}

//explicit Shunting_Yard::operator string() 
//{
//    return expresie;
//}

int Shunting_Yard::validareTip(char op) {

    if (op >= '0' && op <= '9') {
        return 0; // pentru cifre
    }

    else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '#') {
        return 1; // pentru operatori
    }

    else if (op == '(' || op == '[') {
        return 2;
    }

    else if (op == ']' || op == ')') {
        return 3;
    }

    else
        return 10;
}


int Shunting_Yard::prioritate(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }

    else if (op == '*' || op == '/') {
        return 2;
    }

    else if (op == '^' || op == '#') {
        return 3;
    }

    else
        return -1;
}

string Shunting_Yard::calculeaza(string expresie) {
    this->expresie = expresie;
    while (this->expresie.length() > 0) {
        if (validareTip(this->expresie[0]) == 0) {
            rezultat += this->expresie[0];
            this->expresie.erase(0, 1);
        }
        else if (validareTip(this->expresie[0]) == 1) {
            rezultat += " ";
            while (validareTip(operatorStack.getLastElement()) != 2 && prioritate(this->expresie[0]) < prioritate(operatorStack.getLastElement()))
            {
                rezultat += operatorStack.getLastElement();
                rezultat += " ";
                operatorStack.pop();
            }
            operatorStack.push(this->expresie[0]);
            this->expresie.erase(0, 1);
        }
        else if (validareTip(this->expresie[0]) == 2) {
            operatorStack.push(this->expresie[0]);
            this->expresie.erase(0, 1);
        }
        else if (validareTip(this->expresie[0]) == 3) {
            while (validareTip(operatorStack.getLastElement()) != 2) {

                rezultat += operatorStack.getLastElement();
                rezultat += " ";
                operatorStack.pop();

                if (validareTip(operatorStack.getLastElement()) == 2) {
                    operatorStack.pop();
                    break;
                }
            }
            this->expresie.erase(0, 1);
        }
    }

    while (!operatorStack.isEmpty()) {
        if (validareTip(operatorStack.getLastElement()) == 2 || validareTip(operatorStack.getLastElement()) == 3)
        {
            exit(404);
        }
        rezultat += operatorStack.getLastElement();
        rezultat += " ";
        operatorStack.pop();
    }

    return rezultat;

}


string Shunting_Yard::getRezultat() {
    return rezultat;
}

void Shunting_Yard::setExpresie(string expresie) {
    if (expresie.length() > 0) {
        this->expresie = expresie;
    }
}

string Shunting_Yard::getExpresie() {
    return this->expresie;
}