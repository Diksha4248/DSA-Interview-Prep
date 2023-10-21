#include <bits/stdc++.h>
using namespace std;


// this includes intro to tree and traversal trees: inorder, preorder, postorder
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

void preorder(node *root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
   // Creating a new node by using dynamic allocation.
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);

    cout<<"Inorder traversal : "<<endl;
    inorder(root);

    cout<<"\nPreorder traversal : "<<endl;
    preorder(root);

    cout<<"\nPostorder traversal : "<<endl;
    postorder(root);

    return 0;
}