#include <bits/stdc++.h>
using namespace std;

// Striver : https://www.youtube.com/watch?v=Rezetez59Nk

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


// Approach 1
int maxi = 0;
// diameter = maximum distance between any two nodes
// TC = O(N^2)
int diameter(node * root){
    if(root == NULL)
        return 0 ;
    int lh = height(root->left);  
    int rh = height(root->right);

    maxi = max(lh+rh,maxi);
    diameter(root->left);
    diameter(root->right);
    return maxi;
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

    cout<<"Diameter of the given tree is : "<<diameter(root)<<endl; 
    return 0;
}