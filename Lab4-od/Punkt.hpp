//
// Created by szymon on 09.04.19.
//

#ifndef LAB4_OD_PUNKT_HPP
#define LAB4_OD_PUNKT_HPP

#include <string>
#include <iostream>
#include <sstream>

namespace lab4 {
    class Punkt
    {
    private:
        float x;
        float y;
    public:
        void setX(float x) {
            Punkt::x = x;
        }

    public:
        float getX() const {
            return x;
        }

    public:
        void setY(float y) {
            Punkt::y = y;
        }

    public:
        float getY() const {
            return y;
        }

        Punkt () = delete;
        Punkt (float x, float y);
        bool zapisz(std::ostream & os) const; /// zapisuje atrybuty do strumienia
        bool wczytaj(std::istream & is); /// wczytuje atrybuty ze strumienia
        friend std::ostream& operator <<(std::ostream& str, const Punkt &punkt);
    };
}

#endif //LAB4_OD_PUNKT_HPP
