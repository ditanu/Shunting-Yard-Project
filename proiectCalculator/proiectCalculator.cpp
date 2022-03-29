#include <iostream>
#include <string>
#include "Stack.h"
#include "Shunting_Yard.h";
#include "Calculator.h"
using namespace std;

// Tot ce face acest cod este sa calculeze RPN-ul (Reverse Polish Notation)
// Proiect realizat cu ajutorul algoritmului Shunting-yard => link : https://en.wikipedia.org/wiki/Shunting-yard_algorithm  //

ostream& operator << (ostream& out, Stack& s)
{
    out << "Lungimea: " << s.nrLungime << endl;

    for (int i = 0; i < s.nrLungime; i++)
    {
        out << s.array[i] << " ";
    }

    out << endl;
    return out;
}

istream& operator>>(istream& in, Stack& s) {
    cout << "Lungime: ";
    int nr;
    in >> nr;
    cout << endl;

    char* arrayCitire = new char[s.nrLungime];
    for (int i = 0; i < s.nrLungime; i++) {
        cout << "array[" << i << "]=";
        in >> arrayCitire[i];
    }

    s.setArray(arrayCitire, nr);
    delete[] arrayCitire;
    return in;

}

ostream& operator << (ostream& out, Shunting_Yard& sy) {
    out << "Expresia: " << sy.getExpresie() << endl;
    out << "Rezultat: " << sy.rezultat;
    out << endl;
    return out;
}

istream& operator>>(istream& in, Shunting_Yard& sy) {
    cout << "Expresia: ";
    in >> sy.expresie;
    return in;
}

ostream& operator << (ostream& out, Calculator& c)
{
    out << "Expresie: " << c.getExpresie() <<endl;
    c.calculeaza();
    out << "Rezultat: " << c.getRezultat() << endl;
    out << endl;
    return out;
}

istream& operator>>(istream& in, Calculator& c) {
    cout << "Expresia: ";
    in >> c.expresie;
    return in;
}


int main()
{
    Calculator c;
    cin >> c;
    cout << c; 
}
