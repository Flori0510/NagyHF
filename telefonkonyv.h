#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include <iostream>
#include <fstream>
#include "ugyfel.h"

class Telefonkonyv {
    Ugyfel** data;
    size_t meret;
public:
    Telefonkonyv(size_t meret) :data(new Ugyfel* [meret]), meret(meret) {} // konstruktorok

    Telefonkonyv() :data(), meret() {}

    Telefonkonyv(const Telefonkonyv& t);            //masolo konstruktor

    Telefonkonyv& operator=(const Telefonkonyv& t); //ertekado operator

    size_t size() const {                           //méretet adja vissza
        return meret;
    }

    void add(Ugyfel *uj);                     //új adat felvétele

    Ugyfel* operator[](size_t i);                //index operatorok
    Ugyfel* const& operator[](size_t i) const;

    ~Telefonkonyv();                                //destruktor

    void torol(size_t idx);                         //elem törlése

    void print();                                    //adatok kiírása

    void read(const char* f);              //beolvasás

    void save(const char* f);               //adatok kimentése
};
#endif // TELEFONKONYV_H_INCLUDED
