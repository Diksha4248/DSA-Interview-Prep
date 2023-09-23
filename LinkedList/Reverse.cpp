// Program to reverse the given linkedlist

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

void Insert_at_start(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void display(node *head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

// Reverse a linked list by Iterative Method:
// Time Complexity: O(N), Traversing over the linked list of size N. 
// Auxiliary Space: O(1)

void reverse_list(node * &head){
    node * prev = NULL;
    node * curr = head;
    node * nxt = NULL;

    while(curr!=NULL){
        
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
      
    }

    head =  prev;
}

// Reverse the linked list pnly till given position 
void reverse_pos(node * &head, int pos)
{
    node * curr = head;
    node * prev, *nxt = NULL;

    int i=1;
    while(i<=pos){
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
        i=i+1;
    }

    head->next = curr;
    head = prev;
}

int main(){

    node *head = NULL;
    Insert_at_start(head,4);
    Insert_at_start(head,3);
    Insert_at_start(head,2);
    Insert_at_start(head,1);
    display(head); 

    reverse_list(head);
    display(head);

    cout<<"Reversing till given position/node : "<<endl;
    reverse_pos(head,4);
    display(head);

    return 0;
}