#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <ostream>
#include <istream>
#include <stdio.h>
#include <string.h>

#include "class.hpp"

using namespace std;

int main(void){

    Polygon polygon1(3);

    Point point1(3.5,4.5);
    Point point2(2.5,-4.5);
    Point point3(5,4);
    Point point4(0,1);

    polygon1.add(point1);
    polygon1.add(point2);
    polygon1.add(point3);
    polygon1.add(point4);

    Polygon polygon2(polygon1);
    Polygon polygon3 = polygon1;
    Polygon polygon4(move(polygon1));
    Polygon polygon5 = move(polygon1);

    cout<<polygon1.get_tablica()<<endl;
    cout<<polygon2.get_tablica()<<endl;
    cout<<polygon3.get_tablica()<<endl;
    cout<<polygon4.get_tablica()<<endl;
    cout<<polygon5.get_tablica()<<endl;
}
