#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};
class mystack{
public:
    Node* head;
    Node* tail;
    mystack(){
        head = tail = NULL;
    }
};

mystack* create(){
    mystack* ms = new mystack();
    return ms;
}

void push(int data, mystack* ms){
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = ms->head;

    if (ms->head == NULL){

        ms->tail = newnode;
    }

    ms->head = newnode;
}

int pop(mystack* ms){
    // this function will pop head element
    if (ms->head == NULL){
        cout<<"UNable to pop!"<<"\n";
        return -1;
    }
    Node* temp = ms->head;
    ms->head = ms->head->next;


    int popEle = temp->data;
    delete temp;
    return popEle;
}

void Merge(mystack* ms1, mystack* ms2){
    if (ms1->head == NULL){
        ms1->head = ms2->head;

        ms1->tail = ms2->tail;
        return;
    }
        ms1->tail->next = ms2->head;
        ms1->tail = ms2->tail;


}
void display(mystack * ms1){
    Node* temp = ms1->head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    mystack* ms1 = create();
    mystack* ms2 = create();

    push(6,ms1);

    push(5, ms1);
    push(4, ms1);
    // ms1: 6 5 4
    push(9, ms2);
    push(8, ms2);
    push(7, ms2);
    // ms2: 9 8 7

    Merge(ms1,ms2);
    // 456789
    display(ms1);
    return 0;
}
