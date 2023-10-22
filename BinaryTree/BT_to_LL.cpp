#include <bits/stdc++.h>
using namespace std;


class node{

    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
   // Creating a new node by using dynamic allocation.
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(9);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->left->right->left = new node(5);
    root->left->right->right = new node(8);

    cout<<"Inorder traversal : "<<endl;
    inorder(root);

    return 0;
}