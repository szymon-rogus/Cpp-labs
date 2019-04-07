#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <ostream>
#include <istream>
#include <stdio.h>
#include <string.h>

#include "Point.hpp"
#include "Matrix.hpp"

using namespace std;

int main(){

    Wektor wektor(2,-4);
    Wektor wektor2 = -wektor;
    Matrix macierz(0,4,-2,5);
    cout<<(wektor)<<endl;
    cout<<wektor['y']<<endl;
    cout<<(-wektor)<<endl<<endl;

    cout<<macierz<<endl<<endl;
    cout<<wektor<<endl;
    cout<<wektor2<<endl;

    cout<<(wektor*2)<<endl;
    cout<<(3*wektor)<<endl<<endl;

    cout<<(--macierz)<<endl<<endl;
    cout<<(macierz--)<<endl<<endl;
    cout<<(int)wektor<<endl;

    return 0;
}
