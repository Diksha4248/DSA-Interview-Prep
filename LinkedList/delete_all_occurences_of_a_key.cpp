// Delete all occurrences of a given key in a linked list

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

void insert_node(node* &head,int val){
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

// Time complexity: O(n)
// Auxiliary Space: O(1)
void delete_all_key(node * &head,int key){
    node * curr = head;
    node * prev = NULL;

    if(head->data == key){
        head = head->next;
    }

    while(curr!=NULL){
        if(curr->data == key){
            prev->next = curr->next;
        }
        
        prev = curr;
        curr = curr->next;
    }
}


int main()
{
    // node *head = new node(5);
    node * head = NULL;

    insert_node(head,4);
    insert_node(head,3);
    insert_node(head,2);
    insert_node(head,1);    
    insert_node(head,2);
    display(head);

    int key = 2;
    delete_all_key(head,key);
    display(head);
    return 0;
}