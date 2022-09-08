//
// Created by szymon on 09.04.19.
//

#ifndef LAB4_OD_TROJKAT_HPP
#define LAB4_OD_TROJKAT_HPP

#include <string>
#include <iostream>
#include <sstream>

#include "Punkt.hpp"
#include "Figura.hpp"

namespace lab4 {
    class Trojkat : public Figura{
    protected:
        Punkt P1;
        Punkt P2;
        Punkt P3;

    public:
        Trojkat() = delete;
        Trojkat(Punkt srodek, std::string etykieta, Punkt P1, Punkt P2, Punkt P3);
        void setEtykieta (std::string et) override ;
        std::string opis() const override ;
        float pole() override ;
        bool zapisz(std::ostream & os) override ; /// zapisuje atrybuty do strumienia
        bool wczytaj(std::istream & is) override ; /// wczytuje atrybuty ze strumieni
    };
}

#endif //LAB4_OD_TROJKAT_HPP
