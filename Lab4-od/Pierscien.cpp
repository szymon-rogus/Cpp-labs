//
// Created by szymon on 09.04.19.
//

#include "Pierscien.hpp"

namespace lab4 {
    Pierscien::Pierscien(Punkt srodek, std::string etykieta, float promien, float promien_wew)
            : Kolo(srodek, etykieta, promien), promien_wew(promien_wew) {}

    void Pierscien::setEtykieta (std::string et){
        this -> etykieta = et;
    }

    std::string Pierscien::opis() const{
        std::stringstream buffer;
        std:: stringstream buffer2;
        buffer << srodek;
        buffer2 << promien << " " << promien_wew;
        std::string opis = "Srodek: " + buffer.str() + ", Etykieta: " + etykieta + "Promień: " + buffer2.str();
        return opis;
    }

    float Pierscien::pole(){
        return promien*3.14*3.14 - promien_wew*3.14*3.14;
    }

    bool Pierscien::zapisz(std::ostream &os) {
        os << srodek << " " << etykieta << " " << promien << " " << promien_wew;
        if(os)
            return true;
        return false;
    }

    bool Pierscien::wczytaj(std::istream &is) {
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        if(!stream.empty())
            return true;
        return false;
    }
}

