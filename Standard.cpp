#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insert_at_start(node * &head, int val)
{
    node * temp = new node(val);
    temp->next = head;
    head = temp;
}

void display(node * &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

int main(){
    node * head = NULL;
    insert_at_start(head,5);
    insert_at_start(head,4);
    insert_at_start(head,3);
    insert_at_start(head,2);
    insert_at_start(head,1);
    
    display(head);
    return 0;
}