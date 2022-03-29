#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack() {
    array = nullptr;
    nrLungime = 0;
}

Stack::Stack(char* array, int nrLungime) {
    if (array != nullptr)
    {
        this->array = new char[nrLungime];
        for (int i = 0; i < nrLungime; i++)
        {
            this->array[i] = array[i];
        }
    }

    this->nrLungime = nrLungime;
}

//destructor
    Stack::~Stack() {
        if (array != nullptr)
        {
            delete[] array;
            array = nullptr;
        }
    }

  //constructoru de copiere

    Stack::Stack(const Stack& s) {
        if (s.array != nullptr && s.nrLungime > 0) {
            nrLungime = s.nrLungime;
            array = new char[nrLungime];
            for (int i = 0; i < nrLungime; i++)
            {
                array[i] = s.array[i];
            }
        }
        else {
            array = nullptr;
            nrLungime = 0;
        }
    }

    //operatorul = 
    Stack& Stack::operator=(const Stack& s)
    {
        if (this != &s)
        {
            if (array != nullptr)
            {
                delete[] array;
                array = nullptr;
            }

           
            if (s.array != nullptr && s.nrLungime > 0)
            {
                for (int i = 0; i < nrLungime; i++)
                {
                    array[i] = s.array[i];
                }
                nrLungime = s.nrLungime;
            }
        }
        return *this;
    }

    // operator "+"
    Stack Stack::operator+(const Stack& s) {
        Stack copie = *this;
        copie.nrLungime = copie.nrLungime + s.nrLungime;
        return copie;
    }

   void Stack::push(int element) {
        char* temp = new char[this->nrLungime];
        for (int i = 0; i < nrLungime; i++)
        {
            temp[i] = this->array[i];
        }
        delete[] this->array;

        this->nrLungime++;
        array = new char[nrLungime];
        for (int i = 0; i < nrLungime; i++)
        {
            this->array[i] = temp[i];
        }
        delete[] temp;

        array[nrLungime - 1] = element;
    }

   void Stack::pop() {
       if (this->isEmpty() == false)
       {
           char* temp = new char[this->nrLungime];
           for (int i = 0; i < nrLungime; i++)
           {
               temp[i] = this->array[i];
           }
           delete[] this->array;

           this->nrLungime--;
           array = new char[nrLungime];

           for (int i = 0; i < nrLungime; i++)
           {
               this->array[i] = temp[i];
           }
           delete[] temp;
       }
   }

   bool Stack::isEmpty() {
       if (nrLungime == 0) {
           return true;
       }
       else {
           return false;
       }
   }

   void Stack::getArray() {
       if (nrLungime != 0) {
           cout << nrLungime << endl << endl;
           for (int i = 0; i < nrLungime; i++)
           {
               cout << array[i] << " " << endl;
           }
       }
       else {
           cout << "Array-ul nu contine elemente!" << endl;
       }
   }

   char Stack::getLastElement() {
       if (nrLungime > 0) {
           return this->array[nrLungime - 1];
       }
       else {
           return '\0';
       }
   }

   void Stack::setArray(char* array, int nrLungime) {
       if (array != nullptr && nrLungime > 0) {
           if (this->array != nullptr) {
               delete[] this->array;
           }

           this->array = new char[nrLungime];
           this->nrLungime = nrLungime;
           for (int i = 0; i < nrLungime; i++) {
               this->array[i] = array[i];
           }
       }
   }
