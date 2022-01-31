#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

bool searchInBST(Node *root, int key)
{
    if (root == NULL)
        return false;
    else if (root->data == key)
        return true;
    else if (key > root->data)
        return searchInBST(root->right, key);
    else
        return searchInBST(root->left, key);
}
bool iterativeSearch(Node *root, int key)
{
    while (root)
    {
        if (root->data == key)
            return true;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}
Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);
    else if (data > root->data)
        root->right = insertInBST(root->right, data);
    else if (data < root->data)
        root->left = insertInBST(root->left, data);
    return root;
}
Node *iterativeInsert(Node *root, int data)
{
    Node *curr = root;
    Node *prev = NULL;
    Node *newNode = new Node(data);
    while (curr)
    {
        prev = curr;
        if (data > curr->data)
            curr = curr->right;
        else if (data < curr->data)
            curr = curr->left;
        else
            return root;
    }
    if (prev == NULL)
        return newNode;
    else if (prev->data > data)
        prev->left = newNode;
    else
        prev->right = newNode;
    return root;
    return root;
}
Node *getSucessor(Node *root)
{
    root = root->right;
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}
Node *deleteInBst(Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data > root->data)
        root->right = deleteInBst(root->right, data);
    else if (data < root->data)
        root->left = deleteInBst(root->left, data);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = getSucessor(root);
            root->data = temp->data;
            root->right = deleteInBst(root->right, temp->data);
        }
    }
    return root;
}
void traverseTree(Node *root)
{
    if (root)
    {
        traverseTree(root->left);
        cout << root->data << " ";
        traverseTree(root->right);
    }
}
Node *findFloor(Node *root, int data)
{
    Node *res = NULL;
    while (root)
    {
        if (root->data == data)
            return root;
        else if (data < root->data)
            root = root->left;
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}
Node *findCeil(Node *root, int data)
{
    Node *res = NULL;
    while (root)
    {
        if (root->data == data)
            return root;
        else if (root->data > data)
        {
            res = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return res;
}
void findCeilforEachEl(vector<int> arr)
{
    cout << -1 << " ";
    set<int> s;
    s.insert(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        auto it = s.lower_bound(arr[i]);
        if (it != s.end())
            cout << *it << " ";
        else
            cout << -1 << " ";
        s.insert(arr[i]);
    }
    cout << endl;
}
bool checkForBST(Node *root, int range_a, int range_b)
{
    if (root == NULL)
        return true;
    return root->data > range_a && root->data < range_b && checkForBST(root->left, range_a, root->data) && checkForBST(root->right, root->data, range_b);
}
bool isBST(Node *root, int &prev)
{
    if (root == NULL)
        return true;
    if (isBST(root->left, prev) == false)
        return false;
    if (root->data <= prev)
        return false;
    prev = root->data;
    return isBST(root->right, prev);
}
void singleSwapToSort(vector<int> arr)
{
    int first, second, prev;
    prev = INT_MIN;
    first = -1;
    second = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < prev)
        {
            if (first == -1)
                first = prev;
            second = arr[i];
        }
        prev = arr[i];
    }
    swap(first, second);
}
// Node *prev=NULL, *first=NULL, *second=NULL;
void singleSwapToMakeBST(Node* root,Node *prev,Node* first,Node* second)
{
    if (root == NULL)
        return;
    singleSwapToMakeBST(root->left,prev,first,second);
    {
    if (prev != NULL && prev->data > root->data)
        if (first == NULL)
            first = prev;
        second = root;
    }
    prev = root;
    singleSwapToMakeBST(root->right,prev,first,second);
}
void makeBST(Node *root)
{
    Node *first,*prev,*second;
    first=prev=second=NULL;
    singleSwapToMakeBST(root,prev,first,second);
    int data = first->data;
    first->data = second->data;
    second->data = data;
}
         
bool findPairInBST(Node *root,int sum,unordered_set<int>&s)
{
    if(root==NULL)
    return false;
    if(findPairInBST(root->left,sum,s)==true)
    return true;
    if(s.find(sum-root->data)!=s.end())
    return true;
    else 
    s.insert(root->data);
    return findPairInBST(root->right,sum,s);
}
void verticalSumInBst(Node *root,int horizontal_distance,map<int,int>&mp){
    if(root==NULL)
    return;
    verticalSumInBst(root->left,horizontal_distance-1,mp);
    mp[horizontal_distance]+=root->data;
    verticalSumInBst(root->right,horizontal_distance+1,mp);
}
void printVerticalSum(Node *root)
{
    map<int,int>mp;
    verticalSumInBst(root,0,mp);
    for(auto it:mp)
    cout<<it.second<<" ";
    cout<<endl;
}
void verticallyTraverseBst(Node *root)
{
    if(root==NULL)
    return;
    queue<pair<Node*,int>>q;
    map<int,vector<int>>mp;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int>p;
        p=q.front();q.pop();
        Node *temp=p.first;
        int hd=p.second;
        mp[hd].push_back(temp->data);
        if(temp->left)
        q.push({temp->left,hd-1});
        if(temp->right)
        q.push({temp->right,hd+1});
    }
    for(auto it:mp){
        vector<int>v=it.second;
        for(auto i:v)
        cout<<i<<" ";
        cout<<endl;
    }
}
void topViewOfBt(Node *root)
{
    if(root==NULL)
    return;
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int>p;
        p=q.front();q.pop();
        Node *temp=p.first;
        int hd=p.second;
        if(mp.find(hd)==mp.end())
        mp[hd]=temp->data;
        if(temp->left)
        q.push({temp->left,hd-1});
        if(temp->right)
        q.push({temp->right,hd+1});
    }
    for(auto it:mp){
      cout<<it.second<<" ";
    }
    cout<<endl;
}
void bottomViewOfBt(Node *root)
{
     if(root==NULL)
    return;
    queue<pair<Node*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node*,int>p;
        p=q.front();q.pop();
        Node *temp=p.first;
        int hd=p.second;
        mp[hd]=temp->data;
        if(temp->left)
        q.push({temp->left,hd-1});
        if(temp->right)
        q.push({temp->right,hd+1});
    }
    for(auto it:mp){
      cout<<it.second<<" ";
    }
    cout<<endl;
}
main()
{
    vector<int> treeData = {10, 31, 9, 56, 12, 11, 19};
    Node *root = NULL;
    for (int i = 0; i < treeData.size(); i++)
        root = insertInBST(root, treeData[i]);
    traverseTree(root);
    cout << endl;
    // root = deleteInBst(root, 31);
    // traverseTree(root);
    cout << endl;
    findCeilforEachEl({2, 8, 30, 15, 25, 12});
    unordered_set<int>s;
    cout<<findPairInBST(root,23,s)<<endl;
    cout<<endl;
    verticallyTraverseBst(root);
    topViewOfBt(root);
    bottomViewOfBt(root);
}