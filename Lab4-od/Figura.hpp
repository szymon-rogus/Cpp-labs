//
// Created by szymon on 09.04.19.
//

#ifndef LAB4_OD_FIGURA_HPP
#define LAB4_OD_FIGURA_HPP

#include <string>
#include <iostream>
#include <sstream>

#include "Punkt.hpp"

namespace lab4 {
    class Figura{
    protected:
        Punkt srodek;
        std::string etykieta;

    public:
        Figura() = delete;
        Figura(Punkt srodek, std::string etykieta);
        virtual ~Figura() {delete &srodek;}
        virtual void setEtykieta (std::string et);
        virtual std::string opis() const;
        virtual float pole();
        virtual bool zapisz(std::ostream & os); /// zapisuje atrybuty do strumienia
        virtual bool wczytaj(std::istream & is); /// wczytuje atrybuty ze strumienia
    };
}

#endif //LAB4_OD_FIGURA_HPP
