#ifndef CEG_H_INCLUDED
#define CEG_H_INCLUDED
#include <string>
#include <iostream>
#include "ugyfel.h"

class Ceg : public Ugyfel{

    std::string adoszam;
    int osztalyok_szama;

public:

    Ceg(std::string adoszam, int osztalyok_szama, std::string name, std::string address, int telnumber)
            : Ugyfel(name,  address, telnumber), adoszam(adoszam), osztalyok_szama(osztalyok_szama) {}

    Ceg() : adoszam(), osztalyok_szama() {}

    void print(){
           std::cout << name << " "
            << address << " "
            << telnumber << " "
            << adoszam << " "
            << osztalyok_szama << std::endl;}

    void f_print(std::ostream& os){
            os << "c "
            << name << " "
            << address << " "
            << telnumber << " "
            << adoszam << " "
            << osztalyok_szama << std::endl;}

        void UjCeg();

        ~Ceg() {}
};
#endif // CEG_H_INCLUDED
