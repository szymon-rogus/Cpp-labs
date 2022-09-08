#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Punkt.hpp"
#include "Figura.hpp"
#include "Trojkat.hpp"
#include "Kolo.hpp"
#include "Pierscien.hpp"

using namespace lab4;

int main() {
    Figura *tablica[6];
    tablica[0] = new Trojkat(Punkt(0,0), "trojkat", Punkt(1,1), Punkt(1,4), Punkt(2,3));
    tablica[1] = new Trojkat(Punkt(1,2), "trojkat", Punkt(1,1), Punkt(2,4), Punkt(2,-4));
    tablica[2] = new Kolo(Punkt(3,-3), "kolo", 10);
    tablica[3] = new Kolo(Punkt(2,3), "kolo", 3);
    tablica[4] = new Pierscien(Punkt(10,4), "pierscien", 7, 5);
    tablica[5] = new Pierscien(Punkt(2,14), "pierscien", 9, 1);

    std::stringstream s1;
    s1=std::stringstream();
    std::cout<<tablica[0]->opis()<<std::endl;
    std::cout<<tablica[0]->zapisz(s1)<<std::endl;
    std::cout<<tablica[1]->wczytaj(s1)<<std::endl;
    std::cout<<tablica[1]->opis()<<std::endl<<std::endl;

    s1=std::stringstream();
    std::cout<<tablica[2]->opis()<<std::endl;
    std::cout<<tablica[2]->zapisz(s1)<<std::endl;
    std::cout<<tablica[2]->wczytaj(s1)<<std::endl;
    std::cout<<tablica[3]->opis()<<std::endl<<std::endl;

    s1=std::stringstream();
    std::cout<<tablica[4]->opis()<<std::endl;
    std::cout<<tablica[4]->zapisz(s1)<<std::endl;
    std::cout<<tablica[4]->wczytaj(s1)<<std::endl;
    std::cout<<tablica[5]->opis()<<std::endl;
    return 0;
}