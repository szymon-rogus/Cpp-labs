#include "data.hpp"

Data::Data()
    :h(12), m(0), s(0) {}

int Data::suma = 0;

Data::Data(int h, int m, int s) :h(h), m(m), s(s){

    if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59){
        this -> h = 12;
        this -> m = 0;
        this -> s = 0;
    }
    suma+=this -> s;
}

void Data::addSecond(){
     ++s;

}

bool Data::ifequal(Data czas){
    if(this -> h != czas.h || this -> m != czas.m || this -> s != czas.s)
        return false;
    return true;
}

void Data::getTime(){
    stringstream ss;
    if(this -> h >9)
        ss << this -> h << ":";
    else
        ss << 0 << this -> h << ":";
    if(this -> m >9)
        ss << this -> m << ":";
    else
        ss << 0 << this -> m << ":";
    if(this -> s >9)
        ss << this -> s << ":";
    else
        ss << 0 << this -> s;
    string str = ss.str();
    cout<<str<<endl;
}

void Data::save(ostream& os){
    os << this -> h << ":" << this -> m << ":" <<this -> s;
}

void Data::load(istream& is){
    string stream;
    is >> stream;

    string hour = stream.substr(0,2);
    string minute = stream.substr(3,2);
    string second = stream.substr(6,2);

    istringstream h1(hour);
    istringstream m1(minute);
    istringstream s1(second);

    h1 >> this -> h;
    m1 >> this -> m;
    s1 >> this -> s;
}
