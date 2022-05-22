#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;

    node(int value, node* pos = 0)
    : info(value), next(pos){};
};

//deklarasi node awalan ssl;
node* first = NULL;

void insertEmpty(node* n){
    first = n;
    n->next = first;
}

void deleteLastElement(){
    node* n = first;
    n->next = NULL;
    first = NULL;
    delete n;
}

//insert first
void insertf(int value){
    node* q = first;
    node* n = new node(value);
    if (first != NULL){
        while(q->next != first){
            q = q->next;
        }
        n->next = first;
        q->next = n;
        first = n;
    } else {insertEmpty(n);}
    
    
}

//insert last
void insertl(int value){
    node* q = first;
    node* n = new node(value);
    if (first != NULL){
        while(q->next != first){
            q = q->next;
        }
        n->next = first;
        q->next = n;
    } else {insertEmpty(n);}
}

//insert before
void insertbf(int value , node* pos){
    if (first != pos){
        node* temp;
        node* p = first;
        
        while(p != pos){
            temp = p;
            p = p->next;
        }
        
        node* n = new node(value);
        n->next = temp->next;
        temp->next = n;

    } else {
        node* n = new node(value);
        n->next = first;
        first = n;
    }
}

//insert before
void insertaf(int value, node* pos){
    node* temp;
    node* p = first;
    
    while(p != pos){
        p = p->next;
    }
    
    node* n = new node(value);
    n->next = p->next;
    p->next = n;
}

//delete first
void delf(){
    node* q = first;
    if (first != NULL){
        while(q->next != first){
            q = q->next;
        }
        node* n = first;
        first = n->next;
        n->next = NULL;
        q->next = first;
        delete n;
    } else {deleteLastElement();}
}

//delete last
void dell(){
    node* q = first;
    while(q->next->next != first){
        q = q->next;
    }
    node* n = q->next;
    q->next = first;
    n->next = NULL;
    delete n;
}

//delete after
void delaf(node* pos){
    node* p = first;
    
    while(p != pos){
        p = p->next;
    }
    node* del = p->next;
    pos->next = p->next->next;
    delete del;

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
    insertf(24);
    insertf(59);
    print(first);
    insertl(2);//insertion last
    print(first);
    insertbf(25 , first->next->next->next);//insertion before
    print(first);
    insertaf(60 , first->next);//insertion after
    print(first);
    delf();//deletion first
    print(first);
    dell();//deletion last
    print(first);
    delaf(first);//deletion after
    print(first);
    int key;
    cout << "input data yang ingin di cari: ";
    cin >> key;
    cout << "data "<< key <<" ditemukan di urutan ke-" << search(key);//search
    return 0;
}
