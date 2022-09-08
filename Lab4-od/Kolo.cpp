//
// Created by szymon on 09.04.19.
//

#include "Kolo.hpp"
#include "Figura.hpp"
#include <string>

namespace lab4 {
    Kolo::Kolo(Punkt srodek, std::string etykieta, float promien)
            : Figura(srodek, etykieta), promien(promien) {}

    void Kolo::setEtykieta (std::string et){
        this -> etykieta = et;
    }

    std::string Kolo::opis() const{
        std::stringstream buffer;
        std:: stringstream buffer2;
        buffer << srodek;
        buffer2 << promien;
        std::string opis = "Srodek: " + buffer.str() + ", Etykieta: " + etykieta + " Promień: " + buffer2.str();
        return opis;
    }

    float Kolo::pole(){
        return promien*3.14*3.14;
    }

    bool Kolo::zapisz(std::ostream &os) {
        os << srodek << " " << etykieta << " " << promien;
        if(os)
            return true;
        return false;
    }

    bool Kolo::wczytaj(std::istream &is) {
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        if(!stream.empty())
            return true;
        return false;
    }
}
