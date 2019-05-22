#ifndef MAGAN_H_INCLUDED
#define MAGAN_H_INCLUDED

#include <string>
#include <iostream>
#include "ugyfel.h"

class Magan : public Ugyfel{

    int maganszam;

    bool rejtett;

public:

    Magan(int maganszam, bool rejtett, std::string name, std::string address, int telnumber)
            : Ugyfel(name,  address, telnumber), maganszam(maganszam), rejtett(rejtett){}

    Magan() : maganszam(), rejtett() {}

    void print(){
         if (rejtett)
            { std::cout << "Rejtett adat";}
        else{
            std::cout << name << " "
            << address << " "
            << telnumber << " "
            << maganszam << std::endl;}
        }


    void f_print(std::ostream& os){

            os << "m "
            << name << " "
            << address << " "
            << telnumber << " "
            << maganszam << " "
            << rejtett << std::endl;}

        void UjMagan();

        ~Magan() {}
};
#endif // MAGAN_H_INCLUDED
