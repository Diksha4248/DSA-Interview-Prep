#include <bits/stdc++.h>
using namespace std;

// Striver : https://www.youtube.com/watch?v=KV4mRzTjlAk

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

// Right view = last node of each level
// Traversal = reverse preorder (Root Right Left) because we need right node first
int level = 0;
vector <int> v;
void right_view(node *root, int level){
    if(root == NULL)
        return;

    if(level == v.size()) v.push_back(root->data)  ;
    right_view(root->right,level + 1);
    right_view(root->left, level + 1);  
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

    right_view(root,level);
    cout<<"The right view of Tree is : "<<endl;
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}