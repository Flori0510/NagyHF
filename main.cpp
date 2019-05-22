#include <string>
#include <iostream>
#include "ceg.h"
#include "telefonkonyv.h"
#include "magan.h"
#include "ugyfel.h"
#include "memtrace.h"


bool menu(Telefonkonyv& t) {
    std::cout << "Milyen muveletet akarsz csinalni?" << std::endl;
    std::cout << "1. Adatok listazasa" << std::endl;
    std::cout << "2. Uj maganszemely hozzadasa" << std::endl;
    std::cout << "3. Uj vallalat hozzaadasa" << std::endl;
    std::cout << "4. Ugyfel torlese" << std::endl;
    std::cout << "5. Kilepes" << std::endl;

    int szam;
    std::cin >> szam;
    bool run = true;
    while (run == true){
        switch(szam){
            case 1:{ // kilistázzal az eltárolt adatokat
                std::cout << "Listazza a nevjegyeket." << std::endl;
                t.print();
                std::cin >> szam;
                break;
                }
            case 2:{ //új magánszemélyt adhozzá az adatokhoz
                std::string name, address;
                bool rejtett;
                int telnumber, maganszam;
                std::cout << "Nev: ";
                std::cin >> name;
                std::cout << "\nCim: ";
                std::cin >> address;
                std::cout << "\nTelefonszam: ";
                std::cin >> telnumber;
                std::cout << "\nMaganszam: ";
                std::cin >> maganszam;
                std::cout << "\nSzámat rejtve szeretné tartani (1/0): ";
                std::cin >> rejtett;
                Magan* m = new Magan(maganszam, rejtett, name, address, telnumber);
                t.add(m);
                std::cin >> szam;
                break;
                }
            case 3:{ // új céget ad hozzá
                std::string name, address, adoszam;
                int telnumber, osztalyok_szama;
                std::cout << "Nev: ";
                std::cin >> name;
                std::cout << "\nCim: ";
                std::cin >> address;
                std::cout << "\nTelefonszam: ";
                std::cin >> telnumber;
                std::cout << "\nAdoszam: ";
                std::cin >> adoszam;
                std::cout << "\nOsztalyok szama: ";
                std::cin >> osztalyok_szama;
                Ceg* c = new Ceg(adoszam, osztalyok_szama, name, address, telnumber);
                t.add(c);
                std::cin >> szam;
                break;
                }
            case 4:{ //kitörli a megadott számó sorszámú ügyfelet
                size_t idx;
                std::cout << "Hanyadik elemet szeretned torolni?" << std::endl;
                std::cin >> idx;
                t.torol(idx);
                std::cin >> szam;
                break;
                }
            case 5:{ // kilép a programból
                std::cout << "Viszlat!" << std::endl;
                run = false;
                break;
                }
            default:{
                std::cout << "Nem letezo menupont" << std::endl;
                run = false;
                break;
            }
            }
    }
    return false;
}

int main()
{
    Telefonkonyv t;

    t.read("telefonkonyv.txt");

    bool run = true;

    while (run == true){
         run = menu(t);
    }

    t.save("telefonkonyv.txt");

    return 0;
}
