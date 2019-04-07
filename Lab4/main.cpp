#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Osoba.hpp"
#include "Pojazd.hpp"


int main() {

    Osoba osoba1("Szymon", "Rogus", 1998);
    osoba1.wczytaj(std::cin);
    osoba1.zapisz(std::cout);

    return 0;
}