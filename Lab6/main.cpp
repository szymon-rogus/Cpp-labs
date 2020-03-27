#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#include "Animal.hpp"

using namespace std;

Animal animalGen () { return Animal();}

vector<Animal> generate(){
    vector<Animal> Zoo (15);

    generate(Zoo.begin(), Zoo.end(), animalGen);

    /*for(int i = 0; i < 15; i++){
        cout<<Zoo[i]<<endl;
    }*/
    return Zoo;
}

void maxElement(const vector<Animal> Zoo){
    Animal animal = *min_element(Zoo.begin(), Zoo.end(), Animal::ByAge());
    cout<<animal<<endl;
}

void for_each(vector<Animal> & Zoo){

    for_each(Zoo.begin(), Zoo.end(), [](Animal &animal){
        int age = animal.getAge();
        animal.setAge(age+1);
    });
}

void remove_if(vector<Animal> & Zoo){
    auto it = remove_if(Zoo.begin(), Zoo.end(), [](Animal &animal){
        return animal.getAge() > 10;
    });
}

int count_if(vector<Animal> & Zoo, string species){

    int counter = count_if(Zoo.begin(), Zoo.end(), [&species](Animal &animal){
       return animal.getSpecies() == species;
    });
    return counter;
}

int main(void) {
    srand(time(NULL));

    vector<Animal> Zoo = generate();

    cout<<"----------------------------------------------"<<endl;

    maxElement(Zoo);  //ok
    cout<<count_if(Zoo, "kot")<<endl;  //ok
    remove_if(Zoo);  //ok
    for_each(Zoo); //ok

    cout<<"-------------------------------------------"<<endl;

    set<Animal> ZooSet;

    for(auto &animal : Zoo){
        if(!ZooSet.insert(animal).second)
            cout<<animal<<endl;
    }

    cout<<"-------------------------------------------"<<endl;

    map<string,Animal> ZooMap;

    for(int i = 0; i < 10; i++){
        Animal animal = Animal();
        string key = animal.getKey();
        ZooMap.insert(pair<string, Animal>(key, animal));
        cout<<animal<<endl;
    }
}