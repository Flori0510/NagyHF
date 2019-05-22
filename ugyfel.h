#ifndef UGYFEL_H
#define UGYFEL_H

#include <string>
#include <iostream>

class Ugyfel {
protected:

    std::string name, address;

    int telnumber;

public:

    Ugyfel(std::string name, std::string address, int telnumber) : name(name), address(address), telnumber(telnumber) {}

    Ugyfel() :name(), address(), telnumber() {}

    virtual void print() = 0;

    virtual void f_print(std::ostream& os) = 0;

    virtual ~Ugyfel() {};
};

#endif // UGYFEL_H#define UGYFEL_H

