#include <fstream>
#include <iostream>
#include <string>
#include "telefonkonyv.h"
#include "ugyfel.h"
#include "magan.h"
#include "ceg.h"
#include "memtrace.h"

//masolo konstruktor
Telefonkonyv::Telefonkonyv(const Telefonkonyv& t){
    meret = t.meret;
    data = new Ugyfel*[meret];
    data = t.data;
}

//ertekado operator
Telefonkonyv& Telefonkonyv::operator=(const Telefonkonyv& t){
    meret = t.meret;
    data = t.data;
    return *this;
}

//destruktor
Telefonkonyv::~Telefonkonyv(){
    for(size_t i = 0; i < meret; ++i){
        delete data[i];
    }
    delete [] data;
}

//hozzaad uj elemeket
void Telefonkonyv::add(Ugyfel *uj){
    Ugyfel **temp = new Ugyfel*[meret + 1];
    for (size_t i = 0; i < meret; ++i)
        temp[i] = data[i];
    temp[meret] = uj;
    delete [] data;
    data = temp;
    ++meret;
}

//indexeles operator
Ugyfel* Telefonkonyv::operator[](size_t i){
    return data[i];
}

Ugyfel* const& Telefonkonyv::operator[](size_t i) const{
    return data[i];
}

void Telefonkonyv::torol(size_t idx){
    delete data[idx];
    for (size_t i = idx; i < meret-1; ++i)
        data[i] = data[i+1];
    meret--;
}

void Telefonkonyv::print(){
    for (size_t i = 0; i < meret; ++i){
        std::cout << i <<" ";
        data[i]->print();
    }
}

void Telefonkonyv::read(const char* f){
    std::ifstream fajl;
    fajl.open(f, std::ios::in);


    std::string prefix, name, address, adoszam;
    int telnumber, maganszam, osztalyok_szama;
    bool rejtett;
    while (fajl >> prefix){
        if (prefix == "m"){
            fajl >> name;
            fajl >> address;
            fajl >> telnumber;
            fajl >> maganszam;
            fajl >> rejtett;
            Magan *m = new Magan(maganszam, rejtett, name, address, telnumber);
            add(m);
        }
        else if (prefix == "c"){
            fajl >> name;
            fajl >> address;
            fajl >> telnumber;
            fajl >> adoszam;
            fajl >> osztalyok_szama;
            Ceg *c = new Ceg(adoszam, osztalyok_szama, name, address, telnumber);
            add(c);
        }
    }

    fajl.close();
}

void Telefonkonyv::save(const char* f){
    std::ofstream uj;
    uj.open("telefonkonyv.txt");

    for (size_t i = 0; i < meret; ++i)
        data[i]->f_print(uj);

    uj.close();
}
