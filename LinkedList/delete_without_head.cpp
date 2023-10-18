// Delete a Node from linked list without head pointer

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

// Time complexity: O(1) since performing constant operations and modifying only a single pointer to delete node
// Auxiliary Space: O(1)

void delete_without_head(node *curr){
    node *nxt = curr->next;
    curr->data = nxt->data;
    curr->next = nxt->next;
    free(nxt);
}

int main(){

    node *head = NULL;
    Insert_at_start(head,400);
    Insert_at_start(head,30);
    Insert_at_start(head,250);
    Insert_at_start(head,100);
    display(head); 

    delete_without_head(head->next->next);
    display(head);
    return 0;
}

// Why conventional deletion method would fail here?
// It would be a simple deletion problem from the singly linked list if the head pointer was given because for deletion you must know 
// the previous node and you can easily reach there by traversing from the head pointer. Conventional deletion is impossible without 
// knowledge of the previous node of a node that needs to be deleted. 

// How to delete the node when you dont have the head pointer?
// The trick here is we can copy the data of the next node to the data field of the current node to be deleted. 
// Then we can move one step forward. Now our next has become the current node and the current has become the previous node. 
// Now we can easily delete the current node by conventional deletion methods. 