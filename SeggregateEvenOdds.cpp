// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all 
// the odd numbers in the modified linked list. Also, keep the order of even and odd numbers the same.

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

void EvenOdds(node *&head){
    node *temp = head;
    vector <int> v;
    while(temp!=NULL){
        if(temp->data%2==0){
            v.push_back(temp->data);
        }
        temp = temp->next;
    }

    temp = head; //set it back again to the start of the head
    while(temp!=NULL){
        if(temp->data%2!=0){
            v.push_back(temp->data);
        }
        temp = temp->next;
    }

    node * head2 = NULL;
    int n = v.size();
    for(int i=n-1;i>=0;i--){
        insert_at_start(head2,v[i]);
    }

    head = head2;
}

// 2nd Approach
// Without using a new vector
void Even_Odd(node * &head){
    node *temp = head;
    node *even = NULL;
    node *odd = NULL;
    node * oddStart = NULL;
    node * evenStart = NULL;
    while(temp!=NULL){
        if(temp->data % 2 ==0){
            if(even == NULL){
                even = temp;
                evenStart = even;
            }
            else{
            even->next = temp;
            even = even->next;
            }
        }

        if(temp->data%2!=0){
            if(odd==NULL){
                odd = temp;
                oddStart= odd;
            }
            else{
            odd->next = temp;
            odd = odd->next;
            }
        }

        temp = temp->next;
    }

    even->next = oddStart;
    odd->next =  NULL;
    if(head->data%2!=0){
        head = evenStart;
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

    // EvenOdds(head);    //using a new vector
    Even_Odd(head);
    display(head);
    return 0;
}