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

void insert_node(node * &head, int val)
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

// Detect loop in a linked list using Hashing:

// The idea is to insert the nodes in the hashmap and whenever a node is encountered that is already present in the hashmap then return true.

// Time complexity: O(N), Only one traversal of the loop is needed.
// Auxiliary Space: O(N), N is the space required to store the value in the hashmap.
bool detect_loop(node * &head){
    node * temp = head;
    unordered_set <node*> s;

    while(temp!=NULL){
        
        if(s.find(temp)!=s.end())   // if the node is present in the set already , return true
        {
            return true;
        }
        
        s.insert(temp);
        temp = temp->next;
    }

    return false;
}

// Approach 2
// Detect loop in a linked list by Modification In Node Structure:
// The idea is to modify the node structure by adding flag in it and mark the flag whenever visit the node.

// Time complexity: O(N), Only one traversal of the loop is needed.
// Auxiliary Space: O(1)


bool detect_loop_flag(node * &head){
    node * temp = head;

    while(temp!=NULL){

        if(temp->flag == 1) return true;
        
        temp->flag = 1;
        temp = temp->next;
    }

    return false;
}

//Detect loop in a linked list using Floyd’s Cycle-Finding Algorithm: (Hare - tortoise algo)

// This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. The faster one is called the faster pointer and the other one is called the slow pointer.

// Time complexity: O(N), Only one traversal of the loop is needed.
// Auxiliary Space: O(1). 
bool detect_loop_floyd(node * &head){
    node *slow = head;
    node *fast = head;

    while(fast != NULL)   // if fast pointer reaches NULL, that means end of linked list and there is no loop
    {
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
        slow = slow->next;
    }
    return false;
}

int main()
{
    node *head = NULL;

    insert_node(head,4);
    insert_node(head,3);
    insert_node(head,2);
    insert_node(head,1);    
    display(head);

     /* Create a loop for testing */
    head->next->next->next->next = head;

    // ------- Approach 1 ---------  (Hashing)
    // bool ans = detect_loop(head);

     // ------- Approach 2 ---------  (Modifying Node structure)
    // bool ans = detect_loop_flag(head);

    // ------- Approach 3 ---------  (Floyd's cycle finding algorithm)
    bool ans = detect_loop_floyd(head);
    if(ans) cout<<"Loop Detected"<<endl;
    else cout<<"There is no loop";

    return 0;
}