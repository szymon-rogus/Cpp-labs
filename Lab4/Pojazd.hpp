#ifndef LAB4_POJAZD_HPP
#define LAB4_POJAZD_HPP

#include <string>
#include <iostream>

#include "Osoba.hpp"

class Pojazd
{
protected:
    Osoba wlasciciel;
    int przebieg;
public:
    Pojazd() = delete;
    Pojazd(const Osoba& _wlasciciel, int _przebieg);
    ~Pojazd();
    std::string opis() const; /// zwraca napis z wszystkimi atrybutami (np. "wlasciciel: Jan Kowalski 1970, przebieg: 120000")
    float mocKW() const;
    bool zapisz(std::ostream & os) const;
    bool wczytaj(std::istream & is);
};

#endif //LAB4_POJAZD_HPP
