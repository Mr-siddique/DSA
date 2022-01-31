#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *left,*right;
int lcount;
Node(int d)
{
    data=d;
    left=NULL;
    right=NULL;
    lcount=0;
}
};
Node* insert(Node *root,int data)
{
    if(root==NULL)
    return new Node(data);
    else if(data>root->data)
    root->right=insert(root->right,data);
    else 
    {
        root->left=insert(root->left,data);
        root->lcount++;
    }
    return root;
}
int kthSmallesEl(Node *root,int k)
{
   if(root->lcount+1==k)
   return root->data;
   else if(root->lcount+1>k)
   return kthSmallesEl(root->left,k);
   else{
       k=k-root->lcount-1;
       return kthSmallesEl(root->right,k);
   }
}
void traverseTree(Node *root)
{
    if(root)
    {
        traverseTree(root->left);
        cout<<root->data<<" ";
        traverseTree(root->right);
    }
}
main()
{
    vector<int>arr={11,15,99,4,2,19,28,23,1};
    Node *root=NULL;
    for(int i=0;i<arr.size();i++)
        root=insert(root,arr[i]);
    traverseTree(root);
    cout<<endl;
    cout<<kthSmallesEl(root,4)<<endl;
}