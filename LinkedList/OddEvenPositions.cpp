
// Put even position nodes after odd position nodes 
// Time Complexity : O(N)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *next;
    int flag; //for approach 2

    node(int val){
        data = val;
        next = NULL;
        flag = 0;
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

void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = odd->next;
    node* evenStart = even;
    while(odd->next!=NULL && even->next !=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if(odd->next == NULL){
         even->next = NULL;   //kyuki last mein even elements hone chahiye,
                              //so that should be null
    }
     
}

int main(){
    node * head = NULL;
    insert_at_start(head,5);
    insert_at_start(head,4);
    insert_at_start(head,3);
    insert_at_start(head,2);
    insert_at_start(head,1);
    
    display(head);

    evenAfterOdd(head);
    display(head);
    return 0;
}