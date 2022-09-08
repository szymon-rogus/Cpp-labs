//
// Created by szymon on 09.04.19.
//

#include "Punkt.hpp"

namespace lab4 {
    Punkt::Punkt (float x, float y)
        : x(x), y(y) {}

    std::ostream& operator <<(std::ostream& str, const Punkt &punkt){
        return str << punkt.getX() << " " << punkt.getY();
    }

    bool Punkt::zapisz(std::ostream &os) const {
        os << *this;
        if(os)
            return true;
        return false;
    }

    bool Punkt::wczytaj(std::istream &is) {
        if(!Punkt::wczytaj(is)) return false;
        std::string stream;
        std::cin.clear();
        getline(is, stream);
        return true;
    }
}

