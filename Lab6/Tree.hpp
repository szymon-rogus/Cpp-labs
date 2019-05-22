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

static string Types[7] = {"Dąb", "Buk", "Sosna", "Wierzba", "Brzoza", "Lipa", "Świerk"};

class Tree{
private:
    string species;
    double diameter;
    int age;

public:
    Tree();
    ~Tree() = default;
    bool isEqual(const Tree & tree);
    int getKey();
    friend bool operator< (const Tree &left, const Tree &right);
    friend ostream& operator<<(std::ostream& o, const Tree &right);

    string getSpecies(){
        return this->species;
    }

    double getDiameter(){
        return this->diameter;
    }

    void setDiameter(double d){
        this->diameter = d;
    }

    int getAge(){
        return this->age;
    }
};

Tree::Tree() {
    species = Types[rand()%7];
    diameter = (double)(rand()%( 19 ) + 1) / 10;
    age = rand()%(100) + 1;
}

int Tree::getKey() {
    int key = 0;
    for(int i = 0; i < this->species.length(); i++){
        key += this->species[i];
    }

    key += this -> age;
    return key;
}

bool Tree::isEqual(const Tree & tree) {
    if(this->age == tree.age && this->species == tree.species)
        return true;
    return false;
}

bool operator< (const Tree &left, const Tree &right){
    return left.age + atoi(left.species.c_str()) < right.age + atoi(right.species.c_str());
}

ostream& operator<<(std::ostream& o, const Tree &right){
    o <<right.species<<" "<<right.age<<" "<<right.diameter;
    return o;
}

#endif //LAB6_TREE_HPP
