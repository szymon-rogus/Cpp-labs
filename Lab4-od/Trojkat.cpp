//
// Created by szymon on 09.04.19.
//

#include "Trojkat.hpp"
#include "Punkt.hpp"

namespace lab4 {
    Trojkat::Trojkat(Punkt srodek, std::string etykieta, Punkt P1, Punkt P2, Punkt P3)
            : Figura(srodek, etykieta), P1(P1), P2(P2), P3(P3) {}

    void Trojkat::setEtykieta (std::string et){
        this -> etykieta = et;
    }

    std::string Trojkat::opis() const{
        std::stringstream buffer;
        std::stringstream buffer1;
        buffer << srodek;
        buffer1 << P1.getX() << "," << P1.getY() << " " << P2.getX() << "," << P2.getY()<< " " << P3.getX() << "," << P3.getY();
        std::string opis = "Srodek: " + buffer.str() + ", Etykieta: " + etykieta + " Punkty: " + buffer1.str();
        return opis;
    }

    float Trojkat::pole(){
        return 0;
    }

    bool Trojkat::zapisz(std::ostream &os) {
        if(os)
            return true;
        return false;
    }

    bool Trojkat::wczytaj(std::istream &is) {
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        if(!stream.empty())
            return true;
        return false;;
    }
}

