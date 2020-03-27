#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <ostream>
#include <istream>
#include <stdio.h>
#include <string.h>
#include "data.hpp"

using namespace std;

int main(){
    Data czas1 = Data(13,59,13);
    czas1.addSecond();
    cout<<czas1.getSecond()<<endl;

    Data czas2 = Data(12,0,10);
    cout<<czas1.ifequal(czas2)<<endl;

    czas1.getTime();
    czas2.getTime();
    cout<<czas1.getSuma()<<endl;

    Data czas3;
    czas3.load(cin);
    czas3.save(cout);
}
