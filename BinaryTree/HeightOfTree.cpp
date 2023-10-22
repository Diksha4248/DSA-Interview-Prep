
// striver : https://www.youtube.com/watch?v=eD3tmO66aBA

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

int height(node *root){
    if(root == NULL) return 0;

    int lh = height(root->left);  //left height
    int rh = height(root->right); // right height 

    return max(lh,rh)+1;
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

    cout<<"\nThe height of tree is : "<<height(root)<<endl;
    // height = number of nodes in the longest path from root to leaf node

    return 0;
}