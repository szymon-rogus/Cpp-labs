//
// Created by szymon on 09.04.19.
//

#ifndef LAB4_OD_PIERSCIEN_HPP
#define LAB4_OD_PIERSCIEN_HPP

#include <string>
#include <iostream>
#include <sstream>

#include "Kolo.hpp"

namespace lab4{
    class Pierscien : public Kolo{
    protected:
        float promien_wew;

    public:
        Pierscien() = delete;
        Pierscien(Punkt srodek, std::string etykieta, float promien, float promien_wew);
        void setEtykieta (std::string et) override ;
        std::string opis() const override ;
        float pole() override ;
        bool zapisz(std::ostream & os) override ; /// zapisuje atrybuty do strumienia
        bool wczytaj(std::istream & is) override ; /// wczytuje atrybuty ze strumieni
    };
}

#endif //LAB4_OD_PIERSCIEN_HPP
