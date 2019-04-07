#include "Osoba.hpp"
#include <string>
#include <string.h>

Osoba::Osoba (const std::string& imie, const std::string& nazwisko, int _rok_ur)
    :imie(imie), nazwisko(nazwisko), rok_ur(rok_ur) {}

void Osoba::ustawImie(const std::string &im) {
    this -> imie = im;
}

std::string Osoba::pobierzImie() const {
    return this -> imie;
}

std::ostream& operator <<(std::ostream& str, const Osoba &osoba){
    return str << osoba.imie << " " << osoba.nazwisko << " " << osoba.rok_ur;
}

bool Osoba::zapisz(std::ostream &os) const {
    os << *this;
    if(os)
        return true;
    else
        return false;
}

bool Osoba::wczytaj(std::istream &is) {
    std::string stream;
    std::cin.clear();
    getline(is, stream);

    std::string imie_;
    std::string nazwisko_;
    std::string rok_;
    int k = 0;
    int pocz = 0;

    for(int i = 0; i < stream.size(); i++){
        if(stream[i] == ' ' && k == 0){
            imie_ = stream.substr(pocz, i-pocz);
            k++;
            pocz = i+1;
        }
        else
        if(stream[i] == ' ' && k == 1){
            nazwisko_ = stream.substr(pocz, i-pocz);
            k++;
            pocz = i+1;
        }
        else
        if(i == stream.size()-1 && k == 2){
            rok_ = stream.substr(pocz, i-pocz+1);
        }
    }

    std::istringstream imie(imie_);
    std::istringstream nazwisko(nazwisko_);
    std::istringstream rok_ur(rok_);

    int rok_ur1;
    rok_ur >> rok_ur1;

    imie >> this -> imie;
    nazwisko >> this -> nazwisko;
    this -> rok_ur = rok_ur1;

    return 0;
}