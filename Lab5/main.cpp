#include <iostream>
#include "List.hpp"

using namespace std;

template <typename T>
T minimum(T a, T b, T c){
    T min;
    min = (a < b) ? a : b;
    return (c < min) ? c : min;
}

template <>
const char* minimum<const char*>(const char* a, const char* b, const char *c){
    double i = sizeof(a)/ sizeof(a[0]);
    double j = sizeof(b)/ sizeof(b[0]);
    double k = sizeof(c)/ sizeof(c[0]);

    cout<<i<<" "<<j<<" "<<k;

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
        //lista.removeFromEnd();
        cout<<lista<<endl;
    }
    catch (List<double>::EmptyList &e){
        cout<<"Exeption caught!"<<endl;
    }



    std::cout<<minimum<int>(5, 8, 9)<<endl;
}