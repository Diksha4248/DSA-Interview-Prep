// Check if a Singly Linked List is Palindrome by Reversing the Linked List:

#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    char data;
    node *next;

    node(char val){
        data = val;
        next = NULL;
    }   

};

void insert_node(node* &head,char val){
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

int length(node *&head){
    node * temp = head;
    int cnt = 0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }

    return cnt;
}


// Ex : m->a->d->a->m->NULL
// one way is to have two pointers from start and end and then check if they point to same values, if not , then not a palindrome
// but we can't traverse back in a linkedlist , coz the next pointers link in one way,so that task is to:
// get this  (start)m->a->d<-a<-m (end) from m->a->d->a->m->NULL [traversal from end will be possible using this] , so the task is to reverse half the linkedlist and then use two pointers 
// to check for palindrome

// Get the mid node
// Reverse from mid to end
// Two pointers from start and end to check for palindrome
bool palindrome(node *head){


    if(head==NULL) return false;
    int n = length(head); // length of linked list
    node * temp = head;

    int i = 0;     
    while(i<n/2){
        temp = temp->next;  
        i++;
    }

    node *prev = temp; // this temp will be the mid node
    node *nxt = NULL;
    node *curr = prev->next;

    while(curr!=NULL){     //reversing half the linkedlist 
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    node *start =head;
    node * end = prev;

    while(start != end){   // using two pointers to check for palindrome
        if(start->data != end->data){
            return false;
        }

        start = start->next;
        end = end->next;
    }

     return true; 
}
int main()
{
    node *head = NULL;

    // insert_node(head,'m');
    // insert_node(head,'a');
    // insert_node(head,'d');
    // insert_node(head,'a');    
    // insert_node(head,'m');

    insert_node(head,'c');
    insert_node(head,'a');
    insert_node(head,'r');
    display(head);

    bool ans = palindrome(head);
    if(ans) cout<<"Its a palindrome";
    else cout<<"Its not a palindrome"<<endl;
    return 0;
}

// Time Complexity: O(N),  
// Auxiliary Space: O(1)