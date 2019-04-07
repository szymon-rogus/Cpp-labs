#include <iostream>

using namespace std;

class Matrix{
private:
    int mxx, mxy, myx, myy;
public:
    //Konstruktory
    Matrix();
    Matrix(int mxx, int myy, int mxy, int myx);

    double getmxx(){
        return this -> mxx;
    }

    void setmxx(int mxx){
        mxx = this -> mxx;
    }

    double getmyy(){
        return this -> myy;
    }

    void setmyy(int myy){
        myy = this -> myy;
    }

    double getmxy(){
        return this -> mxy;
    }

    void setmxy(int mxy){
        mxy = this -> mxy;
    }

    double getmyx(){
        return this -> myx;
    }

    void setmyx(int myx){
        mxy = this -> myx;
    }

    //strumień
    friend ostream& operator <<(ostream& str, const Matrix &macierz);

    //dodawanie
    Matrix operator +(const Matrix &macierz);
    Matrix operator +=(const Matrix &macierz);

    //dekrementacja
    Matrix operator --();
    Matrix operator --(int);
};


class Wektor{
private:
    int x,y;
public:
    Wektor();
    Wektor(int x, int y);

    double getx(){
        return this -> x;
    }

    void setx(int x){
        x = this -> x;
    }

    double gety(){
        return this -> y;
    }

    void sety(int y){
        y = this -> y;
    }

    // strumienie
    friend ostream& operator <<(ostream& str, const Wektor &wektor);

    // wektor * liczba, liczb * wektor
    friend Wektor operator *(const Wektor &wektor , int liczba);
    friend Wektor operator *(int liczba, const Wektor &wektor);

    //wektor * macierz
    const Wektor operator *(Matrix &macierz) const;

    // zmiana znaku
    Wektor operator -();

    //porównanie
    bool operator ==(const Wektor &wektor) const;
    bool operator !=(const Wektor &wektor) const;

    //dostęp do pola
    double operator [](char i) const;

    //rzutowanie
    operator int();
};
