//
// Created by szymon on 22.05.19.
//

#ifndef LAB6_TREE_HPP
#define LAB6_TREE_HPP

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
    string getKey();
    friend bool operator< (const Animal &left, const Animal &right);
    friend bool operator== (const Animal &left, const Animal &right);
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
};

Animal::Animal() {
    species = Types[rand()%2];
    name = Name[rand()%5];
    age = rand()%(20) + 1;
}

string Animal::getKey() {
    string key = this -> species + this -> name;
    return key;
}

bool Animal::isEqual(const Tree & tree) {
    if(this->age == tree.age && this->species == tree.species)
        return true;
    return false;
}

bool operator< (const Tree &left, const Tree &right){
    return left.age + atoi(left.species.c_str()) < right.age + atoi(right.species.c_str());
}

bool operator== (const Tree &left, const Tree &right){
    return left.age + atoi(left.species.c_str()) == right.age + atoi(right.species.c_str());
}

ostream& operator<<(std::ostream& o, const Tree &right){
    o <<right.species<<" "<<right.age<<" "<<right.diameter;
    return o;
}

#endif //LAB6_TREE_HPP
