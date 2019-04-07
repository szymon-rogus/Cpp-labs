#include "class.hpp"
#include <string>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <stdexcept>

using namespace std;

Point::Point()
    :x(0.0), y(0.0) {}

Point::Point(float x, float y)
    :x(x), y(y) {}

Polygon::Polygon()
    :rozmiar(3), licznik(0), tablica(new Point[rozmiar]) {}

Polygon::Polygon(int rozmiar)
    :rozmiar(rozmiar), licznik(0)
{
    if(rozmiar < 1)
        throw Bad_Index(rozmiar);
    else
        tablica = new Point[rozmiar];
}

// copying constructor
Polygon::Polygon(const Polygon &polygon)
    :rozmiar(polygon.rozmiar), licznik(polygon.licznik)
{
    tablica = new Point[polygon.rozmiar];

    for(int i = 0; i < licznik; i++){
        tablica[i] = polygon.tablica[i];
    }
}

// moving constructor
Polygon::Polygon(Polygon &&polygon)
    :rozmiar((polygon.rozmiar)), licznik((polygon.licznik))
{
    tablica = polygon.tablica;
    polygon.tablica = nullptr;
}

// = for copying
Polygon& Polygon::operator =(const Polygon &polygon){

    if(&polygon == this)
        return *this;

    delete [] tablica;

    tablica = new Point[polygon.rozmiar];

    for(int i = 0; i < polygon.licznik; i++){
        tablica[i] = polygon.tablica[i];
    }

    licznik = polygon.licznik;
    return *this;
}

// = for moving
Polygon& Polygon::operator =(Polygon &&polygon){

    if(&polygon == this)
        return *this;

    delete [] tablica;

    tablica = polygon.tablica;
    polygon.tablica = nullptr;
    licznik = polygon.licznik;

    return *this;
}

void Polygon::add(const Point &point){

    if(licznik < rozmiar){
        tablica[licznik] = point;
        licznik++;
    }
    else
        throw Overflow(licznik);

}

Polygon::~Polygon(){

    if(tablica)
        delete [] tablica;
}
