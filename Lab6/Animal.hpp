//
// Created by szymon on 22.05.19.
//

#ifndef LAB6_ANIMAL_HPP
#define LAB6_ANIMAL_HPP

#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <sstream>

using namespace std;

static string Types[2] = {"kot", "pies"};
static string Name[5] = {"szary wicher", "duch", "kudłacz", "dama", "nymeria"};

class Animal{
private:
    string name;
    string species;
    int age;

public:
    Animal();
    ~Animal() = default;
    bool isEqual(const Animal & animal);
    string getKey() const;
    friend bool operator< (const Animal &left, const Animal &right);
    friend bool operator == (Animal &left, Animal &right);
    friend ostream& operator<<(std::ostream& o, const Animal &animal);

    string getSpecies(){
        return this -> species;
    }

    string getName(){
        return this -> name;
    }

    int getAge(){
        return this -> age;
    }

    void setAge(int age){
        this->age = age;
    }

    struct ByAge{
        bool operator()(const Animal &animal, const Animal &animal2) const{
            return animal.age > animal2.age;
        }
    };
};

Animal::Animal() {
    species = Types[rand()%2];
    name = Name[rand()%5];
    age = rand()%(20) + 1;
}

string Animal::getKey() const{
    string key = this -> species + this -> name;
    return key;
}

bool operator< (const Animal &left, const Animal &right){
    return left.age < right.age;
}

bool operator == (Animal &left, Animal &right){
    return left.getKey() == right.getKey();
}

ostream& operator<<(std::ostream& o, const Animal &right){
    o <<right.name<<" "<<right.species<<" "<<right.age;
    return o;
}

#endif //LAB6_ANIMAL_HPP
