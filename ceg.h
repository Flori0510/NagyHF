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

    void print();
    void f_print(std::ostream& os);
        void UjCeg();

        ~Ceg() {}
};

