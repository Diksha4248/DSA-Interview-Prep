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

bool check_BST(node *root, long long minVal, long long maxVal) {
    if (root == NULL)
        return true;
    if (root->data >= maxVal || root->data <= minVal)
        return false;
    // Adjust the range for the left and right subtrees
    return check_BST(root->left, minVal, root->data) && check_BST(root->right, root->data, maxVal);
}

bool checkBST(node *root) {
    // Use long long as sentinel values to handle INT_MIN and INT_MAX
    return check_BST(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->right->left = new node(9);
    // root->left->left = new node(4);
    // root->left->right = new node(6);
    // root->left->right->left = new node(5);
    // root->left->right->right = new node(8);

    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(22);

    cout<<"Inorder traversal : "<<endl;
    inorder(root);

    int ans = checkBST(root);
    if(ans) cout<<"\nThe Given tree is a BST :) "<<endl;
    else cout<<"\nThe given tree is not a BST "<<endl;

    return 0;
}