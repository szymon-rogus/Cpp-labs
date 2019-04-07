#include <iostream>
#include <utility>

using namespace std;

class Point{
private:
    float x,y;

public:
    Point();
    Point(float x, float y);

    void set_x(float x){
        this -> x = x;
    }

    float get_x() const{
        return this -> x;
    }

    void set_y(float y){
        this -> y = y;
    }

    float get_y() const{
        return this -> y;
    }
};

// Just a next class

class Polygon{
private:
    int rozmiar;
    int licznik;
    Point *tablica;

public:
    Polygon();
    Polygon(int rozmiar);
    Polygon(const Polygon &polygon);
    Polygon(Polygon &&);

    void set_tablica(Point *tablica){
        this -> tablica = tablica;
    }

    Point* get_tablica() const{
        return this -> tablica;
    }

    int get_rozmiar() const{
        return this -> rozmiar;
    }

    int get_licznik() const{
        return this -> licznik;
    }


    Polygon& operator =(const Polygon &polygon);
    Polygon& operator =(Polygon &&polygon);
    void add(const Point &point);

    ~Polygon();

    class Overflow{
    public:
        int licznik;

        Overflow(int licznik) :licznik(licznik){
            cout<<"The memory here is full! "<< licznik << " is out of range"<<endl;
        }
    };

    class Bad_Index{
    public:
        int index;

        Bad_Index(int index) :index(index){
            cout<<"Incorrecrt size of table, must by >0!"<<endl;
            cout<<index;
        }
    };
};





