#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#include "Tree.hpp"

using namespace std;

vector<Tree> generate(){
    vector<Tree> BotanicGarden;

    for(int i = 0; i < 25; i++){
        Tree treeBotanic = Tree();
        BotanicGarden.push_back(treeBotanic);
        cout<<BotanicGarden[i]<<endl;
    }

    return BotanicGarden;
}

void minElement(vector<Tree> BotanicGarden){
    Tree tree = BotanicGarden[0];
    for(auto it : BotanicGarden){
        if(it.getDiameter() < tree.getDiameter())
            tree = it;
    }
    cout<<tree<<endl;
}

// for_each
void grow(vector<Tree> & BotanicGarden){
    for(int i = 0; i < BotanicGarden.size(); i++){
        BotanicGarden[i].setDiameter(BotanicGarden[i].getDiameter() + 0.1);
        cout<<BotanicGarden[i]<<endl;
    }
}

//remove_if
void remove(vector<Tree> & BotanicGarden){
    for(auto it = BotanicGarden.begin(); it != BotanicGarden.end(); it++){
        if(it->getDiameter() > 1.0){
            BotanicGarden.erase(it);
            it--;
        }
    }
}

//count_if
void count(vector<Tree> & BotanicGarden){
    string type;
    cout<<"Podaj gatunek:"<<endl;
    cin>>type;

    int counter = 0;
    for(auto it : BotanicGarden){
        if(it.getSpecies() == type){
            counter++;
        }
    }

    cout<<"Ilość drzew z podanego gatunku to: " + to_string(counter)<<endl;
}

int main(void) {
    srand(time(NULL));

    vector<Tree> BotanicGarden = generate();

    cout<<"----------------------------------------------"<<endl;

    //minElement(BotanicGarden);  //ok
    //remove(BotanicGarden);  //ok
    //grow(BotanicGarden);
    //for(int i = 0; i < BotanicGarden.size(); i++){
    //    cout<<BotanicGarden[i]<<endl;
    //}
    //count(BotanicGarden);

    cout<<"-------------------------------------------"<<endl;

    set<Tree> BotanicSet;

    for(const Tree &i: BotanicGarden){
        auto result = BotanicSet.insert(i);
        if(!result.second)
            cout<<i<<endl;
    }

    cout<<"-------------------------------------------"<<endl;

    map<int,Tree> BotanicMap;

    for(int i = 0; i < 10; i++){
        Tree treeMap = Tree();
        int key = treeMap.getKey();
        BotanicMap[key] = treeMap;
        cout<<key<<" "<<treeMap<<endl;
    }
}