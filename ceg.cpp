
#include <string>
#include <iostream>
#include "ugyfel.h"
#include "telefonkonyv.h"
#include "ceg.h"
#include "memtrace.h"

    void Ceg::print(){
           std::cout << name << " "
            << address << " "
            << telnumber << " "
            << adoszam << " "
            << osztalyok_szama << std::endl;}

    void Ceg::f_print(std::ostream& os){
            os << "c "
            << name << " "
            << address << " "
            << telnumber << " "
            << adoszam << " "
            << osztalyok_szama << std::endl;}


