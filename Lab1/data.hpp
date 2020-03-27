#ifndef data_hpp
#define data_hpp
#include <iostream>
#include <sstream>
using namespace std;

class Data{
private:
    int h,m,s;
    static int suma;
public:
    Data();

    Data(int h, int m, int s);

    int getHour(){
        return this -> h;
    }

    void setHour(int h){
        this -> h = h;
    }

    int getMinute(){
        return this -> m;
    }

    void setMinute(int m){
        this -> m = m;
    }

    int getSecond(){
        return this -> s;
    }

    void setSecond(int s){
        this -> s = s;
    }

    static int getSuma(){
        return suma;
    }

    void addSecond();
    bool ifequal(Data czas);
    void getTime();
    void save(ostream& os);
    void load(istream& is);
};

#endif
