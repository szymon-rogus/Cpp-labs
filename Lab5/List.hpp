//
// Created by szymon on 28.04.19.
//

#ifndef LAB5_LIST_HPP
#define LAB5_LIST_HPP

using namespace std;

template <typename T>
class List{
private:
    struct Node{
        T value;
        Node *next;
    };
    Node *head;
    mutable Node *start;

public:
    List();
    List(const List & list) = delete;
    ~List();
    void add(T new_value);
    void removeFromEnd();
    bool see();
    List & operator= (List & list) = delete;

    template <typename U>
    friend ostream& operator<<(std::ostream& o, const List<U>&);

    class EmptyList{
    public:
        EmptyList(){
            cout<<"Cannot remove from empty list!"<<endl;
        }
    };
};

template <typename T>
List<T>::List(){
    head = nullptr;
}

template <typename T>
List<T>::~List() {
    if(head){
        while(head -> next){
            Node *pom = head;
            head = head -> next;
            delete(pom);
        }
        delete(head);
    }
}

template <typename T>
void List<T>::add(T new_value) {

    Node *tmp, *pom;
    pom = new Node;
    pom -> next = nullptr;
    pom ->value = new_value;
    tmp = head;

    if(tmp){
        while(tmp -> next)
            tmp = tmp -> next;
        tmp -> next = pom;
    }
    else{
        head = pom;
        start = pom;
    }
}

template <typename T>
void List<T>::removeFromEnd(){

    Node *tmp = head;

    if(tmp){
        if(tmp -> next){
            while(tmp -> next -> next)
                tmp = tmp -> next;
            delete tmp -> next;
            tmp -> next = nullptr;
        }
        else{
            delete tmp;
            head = nullptr;
            start = nullptr;
        }
    }
    else{
        throw EmptyList();
    }
}

template <typename U>
ostream& operator<<(std::ostream& os, const List<U> & lista){

    while(lista.start){
        os << lista.start -> value << " ";
        lista.start = lista.start -> next;
    }
    lista.start = lista.head;
    return os;
}

template <typename T>
bool List<T>::see() {

    if(head == nullptr){
        cout<<"Lista jest pusta!"<<endl;
        return false;
    }
    Node *tmp = head;

    while(tmp != nullptr){
        cout<< tmp -> value<<endl;
        tmp = tmp -> next;
    }

    return true;
}

#endif //LAB5_LIST_HPP
