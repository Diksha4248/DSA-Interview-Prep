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

// Time Complexity : O(N)
// Space Complexity : O(N) [Worst case , in case we have a skew tree]
node *lca(node *root,node *p, node *q){
    if(root == NULL || root == p || root == q){
        return root;
    }

    node *left = lca(root->left,p,q);
    node *right = lca(root->right,p,q);


    // while coming back
    if(left == NULL){
        return right;
    }

    else if(right == NULL){
        return left;
    }

    else{ // both left and right are not null, found are result
        return root;
    }
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

    node * lca_node;
    node * p =  root->left->left ;
    node * q =  root->left->right->right;
    lca_node = lca(root,p,q);

    cout<<"\nThe lowest common ancestor is : ";
    cout<<lca_node->data<<endl;
    return 0;
}