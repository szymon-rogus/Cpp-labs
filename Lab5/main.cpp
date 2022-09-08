#include <iostream>
#include "List.hpp"
#include <string.h>

using namespace std;

template <typename T>
T minimum(T a, T b, T c){
    T min;
    min = (a < b) ? a : b;
    return (c < min) ? c : min;
}

template <>
const char* minimum<const char*>(const char* a, const char* b, const char *c){
    double i = strlen(a);
    double j = strlen(b);
    double k = strlen(c);

    if(i <= j && i <= k)
        return a;
    if(j <= i && j <= k)
        return b;
    return c;
}

int main(void) {
    List<double>lista;

    try{
        lista.add(15);
        lista.add(4);
        lista.add(3);
        cout<<lista<<endl;

        cout<<"------------------"<<endl;

        lista.removeFromEnd();
        lista.removeFromEnd();
        lista.removeFromEnd();
        lista.removeFromEnd();
        cout<<lista<<endl;
    }
    catch (List<double>::EmptyList &e){
        cout<<"Exeption caught!"<<endl;
    }

    const char * alicja = "alicja";
    const char * szymon = "szymon";
    const char * konstantyna = "konstantyna";

    std::cout<<minimum<int>(5, 8, 9)<<endl;
    std::cout<<minimum<const char *>(alicja, szymon, konstantyna)<<endl;
}