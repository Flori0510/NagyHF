#ifndef MAGAN_H_INCLUDED
#define MAGAN_H_INCLUDED

#include <string>
#include <iostream>
#include "ugyfel.h"
#include "telefonkonyv.h"
#include "magan.h"
#include "memtrace.h"

    void Magan::print(){
         if (rejtett)
            { std::cout << "Rejtett adat";}
        else{
            std::cout << name << " "
            << address << " "
            << telnumber << " "
            << maganszam << std::endl;}
        }

    void Magan::f_print(std::ostream& os){

            os << "m "
            << name << " "
            << address << " "
            << telnumber << " "
            << maganszam << " "
            << rejtett << std::endl;}
#endif // MAGAN_H_INCLUDED
