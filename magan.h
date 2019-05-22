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

    void print();

    void f_print(std::ostream& os);

        void UjMagan();

        ~Magan() {}
};

