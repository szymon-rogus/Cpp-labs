//
// Created by szymon on 09.04.19.
//

#include "Figura.hpp"
#include "Punkt.hpp"

namespace lab4 {
    Figura::Figura(Punkt srodek, std::string etykieta)
        : srodek(srodek), etykieta(etykieta) {}

    void Figura::setEtykieta (std::string et){
        this -> etykieta = et;
    }

    std::string Figura::opis() const{
        std::stringstream buffer;
        buffer << srodek;
        std::string opis = "Srodek: " + buffer.str() + ", Etykieta: " + etykieta;
        return opis;
    }

    float Figura::pole(){
        return 0;
    }

    bool Figura::zapisz(std::ostream &os)  {
        os << srodek << " " << etykieta;
        if(os)
            return true;
        return false;
    }

    bool Figura::wczytaj(std::istream &is) {
        if(!Figura::wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        return true;
    }
}

