#include "Matrix.hpp"
#include "Point.hpp"

//konstuktory
Wektor::Wektor()
    :x(0.0), y(0.0) {}

Wektor::Wektor(int x, int y)
    :x(x), y(y) {}

Matrix::Matrix()
    :mxx(0), mxy(0), myx(0), myy(0) {}

Matrix::Matrix(int mxx, int mxy, int myx, int myy)
    : mxx(mxx), mxy(mxy), myx(myx), myy(myy) {}

ostream& operator <<(ostream& str, const Matrix &macierz){
    return str<<macierz.mxx<<" "<<macierz.mxy<<endl<<macierz.myx<<" "<<macierz.myy;
}

ostream& operator <<(ostream& str, const Wektor &wektor){
    return str<<wektor.x<<" "<<wektor.y;
}

Matrix Matrix::operator +( const Matrix &macierz){
    return Matrix (
        getmxx() + macierz.mxx,
        getmxy() + macierz.mxy,
        getmyx() + macierz.myx,
        getmyy() + macierz.myy);
}

Matrix Matrix::operator +=(const Matrix &macierz){
    this -> mxx += macierz.mxx;
    this -> mxy += macierz.mxy;
    this -> myx += macierz.myx;
    this -> myy += macierz.myy;

    return *this;
}

Wektor operator *(const Wektor &wektor , int liczba){
    return Wektor(wektor.x*liczba, wektor.y*liczba);
}

Wektor operator *(int liczba, const Wektor &wektor){
    return Wektor(wektor.x*liczba, wektor.y*liczba);
}

const Wektor Wektor::operator *(Matrix &macierz) const{
    return Wektor(macierz.getmxx()*x + macierz.getmxy()*y,
    macierz.getmyx()*x + macierz.getmyy()*y);
}

Matrix Matrix::operator --(){
    mxx--;
    mxy--;
    myx--;
    myy--;
    return *this;
}

Matrix Matrix::operator --(int){
    Matrix temp = *this;
   --*this;
   return temp;
}

Wektor Wektor::operator -(){
    return Wektor ((-1)*getx(), (-1)*gety());
}

double Wektor::operator[](char i) const{
    if(i == 'x')  return x;
    if(i == 'y') return y;
    return 0;
}

bool Wektor::operator ==(const Wektor &wektor) const{
    return ((x == wektor.x) && (y == wektor.y));
}

bool Wektor::operator !=(const Wektor &wektor) const{
    return ((x != wektor.x) || (y != wektor.y));
}

Wektor:: operator int(){
    return (x*x+y*y);
}



