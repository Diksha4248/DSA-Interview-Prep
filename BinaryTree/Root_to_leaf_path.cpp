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

bool getPath(node *root, vector<int> &v, int x){
    if(!root)
        return false;
   
    v.push_back(root->data);    
    if(root->data == x)
        return true;

    if(getPath(root->left,v,x) || getPath(root->right,v,x));
        return true;
    
    v.pop_back();
    return false;    
}

vector <int> solve(node * root, int ele){
    vector <int> v;
    if( root == NULL){
        return v;
    }

    getPath(root,v,ele);
    return v;
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

    cout<<"\nThe path of node 8 from root is as follows : ";
    vector <int> v = solve(root,8);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}