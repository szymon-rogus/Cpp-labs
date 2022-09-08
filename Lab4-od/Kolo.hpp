//
// Created by szymon on 09.04.19.
//

#ifndef LAB4_OD_KOLO_HPP
#define LAB4_OD_KOLO_HPP

#include <string>
#include <iostream>
#include <sstream>

#include "Figura.hpp"

namespace lab4 {
    class Kolo : public Figura{
    protected:
        float promien;

    public:
        Kolo() = delete;
        Kolo(Punkt srodek, std::string etykieta, float promien);
        void setEtykieta (std::string et) override ;
        std::string opis() const override ;
        float pole() override ;
        bool zapisz(std::ostream & os) override ; /// zapisuje atrybuty do strumienia
        bool wczytaj(std::istream & is) override ; /// wczytuje atrybuty ze strumienia
    };
}

#endif //LAB4_OD_KOLO_HPP
