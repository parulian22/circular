#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;
    node* prev;

    //fungsi membuat element
    node(int value, node* n = 0, node* p = 0)
    : info(value), next(n), prev(p){};
};

//deklarasi first dan last
node* first = NULL;
node* last = NULL;

void insertEmpty(node* n){
    first = n;
    n->next = first;
    n->prev = first;
    last = n;
}

void deleteLastElement(){
    node* n = first;
    n->next = NULL;
    n->prev = NULL;
    first = NULL;
    last = NULL;
    delete n;
}
//insert first
void insertf(int value){
    node* n = new node(value);
    if (first != NULL && last != NULL){
        n->next = first;
        n->prev = last;
        last->next = n;
        first->prev = n;
        first = n;
    } else { insertEmpty(n);}
}

//insert last
void insertl(int value){
    node* n = new node(value);
    if (first != NULL && last != NULL){
        n->next = first;
        n->prev = last;
        last->next = n;
        first->prev = n;
        last = n;
    } else { insertEmpty(n);}
}

//insert before
void insertbf(int value , node* pos){
    node* n = new node(value);
    n->next = pos;
    pos->prev->next = n;
    pos->prev = n;
}

//insert after
void insertaf(int value, node* pos){
    node* n = new node(value);
    n->next = pos->next;
    pos->next->prev = n;
    pos->next = n;
}

//delete first
void delf(){
    if (first != NULL && last != NULL){
        node* temp = first;
        first = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        first->prev = last;
        last->next = first;
        delete temp;
    } else {deleteLastElement();}
}

//delete last
void dell(){
    if (first != NULL && last != NULL){
        node* temp = last;
        last = last->prev;
        temp->next = NULL;
        temp->prev = NULL;
        first->prev = last;
        last->next = first;
        delete temp;
    } else {deleteLastElement();}
}

//delete after
void delaf(node* pos){
    node* temp = pos->next;
    pos->next = temp->next;
    temp->next->prev = pos;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}

//search sequential
int search(int key){
    node* p = first;
    int i = 1;
    while (p->info != key){
        p = p->next;
        i++;
    }
    return i;
}

//print data
void print(node* pos){
    while(pos->next != first){
        cout << pos->info << " ";
        pos = pos->next;
    }
    cout << pos->info << " "; 
    cout << endl;
}

int main(){
    insertf(10);//insertion first
    print(first);
    insertf(21);
    print(first);
    insertl(2);//insertion last
    print(first);
    insertl(7);
    print(first);
    insertbf(25 , first->next);//insertion before
    print(first);
    insertaf(60 , first->next);//insertion after
    print(first);
    delf();//deletion first
    print(first);
    dell();//deletion last
    print(first);
    delaf(first);//deletion after
    print(first);
    int key;//key search
    cout << "input data yang ingin di cari: ";
    cin >> key;
    cout << "data "<< key <<" ditemukan di urutan ke-" << search(key);//search

    return 0;
}
