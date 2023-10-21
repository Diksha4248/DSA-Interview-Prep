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

node* insert_BST(node * root, int val){
    if(root==NULL)
        return new node(val);
    if(val < root->data){
        root->left= insert_BST(root->left,val);
    } 

    else{
        root->right =  insert_BST(root->right,val);
    }   
    return root;
}

// 1st Approach
vector <int> v;
int visited = 0;

void inorder(node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    v.push_back(root->data);
    inorder(root->right);
}

// 2nd approach , uses space : O(1) instead of 
void Kthlargest(node * root, int k, int &cnt)   // Writing &cnt is important
{
    if(root == NULL || cnt >= k)
        return ;

    Kthlargest(root->right,k,cnt);
    cnt++;
    if(cnt==k){
        cout<<"Kth largest element : "<<root->data<<endl;
        return ;
    }
    Kthlargest(root->left,k,cnt);
    
}

int main()
{
   // Creating a new node by using dynamic allocation.
    int arr[] = {20,8,22,4,12,10,14};
    int n = sizeof(arr)/sizeof(int);

    node *root = NULL;
    for(int i=0;i<n;i++){
        root = insert_BST(root,arr[i]);
    }

    cout<<"Inorder traversal : "<<endl;
    inorder(root);

    int k;
    cout<<"Enter k :";
    cin>>k;
    // int n1 = v.size();
    // if(k <= n && k!=0){
    // cout<<v[n1-k];
    // }
    int cnt = 0;
    Kthlargest(root,k,cnt);
    return 0;
}