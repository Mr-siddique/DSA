#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left, *right;

    Node(int data)
    {
        key = data;
        left = right = NULL;
    }
};
void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
void preOrder(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}
int heightOfTree(Node *head)
{
    if (head == NULL)
        return 0;
    return max(heightOfTree(head->left), heightOfTree(head->right)) + 1;
}
void distanceK(Node *head, int k)
{
    if (head == NULL)
        return;
    if (k == 0)
        cout << head->key << " ";
    else
    {
        distanceK(head->left, k - 1);
        distanceK(head->right, k - 1);
    }
}
void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();
        cout << temp->key << " ";
        if (temp->left)
            que.push(temp->left);
        if (temp->right)
            que.push(temp->right);
    }
}
void levelOrderLineByLine(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = que.front();
            que.pop();
            cout << temp->key << " ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
        cout << endl;
    }
}
void levelOrderLineByLineaAno(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> que;
    que.push(root);
    que.push(NULL);
    while (que.size() > 1)
    {
        Node *temp = que.front();
        que.pop();
        if (temp == NULL)
        {
            cout << endl;
            que.push(NULL);
            continue;
        }
        cout << temp->key << " ";
        if (temp->left)
            que.push(temp->left);
        if (temp->right)
            que.push(temp->right);
    }
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int maxValue(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(maxValue(root->left), maxValue(root->right)));
}
void leftMost(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *temp = que.front();
        cout << temp->key << " ";
        int count = que.size();
        for (int i = 0; i < count; i++)
        {
            temp = que.front();
            que.pop();
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
}
void leftMostRecursive(Node *root, int lev, int &maxLev)
{
    if (root)
    {
        if (lev > maxLev)
        {
            cout << root->key << " ";
            maxLev = lev;
        }
        leftMostRecursive(root->left, lev + 1, maxLev);
        leftMostRecursive(root->right, lev + 1, maxLev);
    }
}
string childrenSumProperty(Node *root)
{
    if (root == NULL)
        return "YES";
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();
        int d = 0;
        if (temp->left || temp->right)
        {
            if (temp->left)
            {
                d += temp->left->key;
                que.push(temp->left);
            }
            if (temp->right)
            {
                d += temp->right->key;
                que.push(temp->right);
            }
            if (d != temp->key)
                return "NO";
        }
    }
    return "YES";
}
bool childSumPropertyRecursive(Node *root)
{
    if (root == NULL)
        return true;
    if (!root->left && !root->right)
        return true;
    int d = 0;
    if (root->left)
        d += root->left->key;
    if (root->right)
        d += root->right->key;
    return d == root->key && childSumPropertyRecursive(root->left) && childSumPropertyRecursive(root->right);
}
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    return abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
int checkBalanced(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = checkBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = checkBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}
int maxWidth(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int mx = 0;
    while (!q.empty())
    {
        int s = q.size();
        mx = max(s, mx);
        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return mx;
}
Node *BSTtoDLL(Node *root, Node *prev)
{
    if (root == NULL)
        return NULL;
    Node *head = BSTtoDLL(root->left, prev);
    if (prev == NULL)
        head = root;
    else
    {
        root->left == prev;
        prev->right == root;
    }
    prev = root;
    BSTtoDLL(root->right, prev);
    return head;
}
Node *constructTree(vector<int> inOrder, vector<int> preOrder, int inStart, int inEnd, int &preIndex)
{
    if (inStart > inEnd)
        return NULL;
    Node *head = new Node(preOrder[preIndex++]);
    int inIndex;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inOrder[i] == head->key)
        {
            inIndex = i;
            break;
        }
    }
    head->left = constructTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    head->right = constructTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);
    return head;
}
void spiralTraversal(Node *head)
{
    if (head == NULL)
        return;
    queue<Node *> que;
    int count = 1;
    que.push(head);
    while (!que.empty())
    {
        vector<int> v;
        int count = que.size();
        for (int i = 1; i <= count; i++)
        {
            Node *temp = que.front();
            que.pop();
            v.push_back(temp->key);
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
        if (count % 2 == 1)
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
        }
        else
        {
            for (int i = v.size() - 1; i >= 0; i--)
                cout << v[i] << " ";
        }
    }
    cout << endl;
}
void spiralTraversalEff(Node *head)
{
    if (head == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(head);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->key << " ";
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->key << " ";
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}
int diameterOfTree(Node *head)
{
    if (head == NULL)
        return 0;
    int leftHeight = heightOfTree(head->left);
    int rightHeight = heightOfTree(head->right);
    return max(1 + leftHeight + rightHeight, max(diameterOfTree(head->left), diameterOfTree(head->right)));
}
int diameter(Node *head, int &res)
{
    if (head == NULL)
        return 0;
    int leftHeight = diameter(head->left, res);
    int rightHeight = diameter(head->right, res);
    res = max(res, 1 + leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
bool builtPath(Node *head, vector<Node *> &path, int a)
{
    if (head == NULL)
        return false;
    path.push_back(head);
    if (head->key == a)
        return true;
    if (builtPath(head->left, path, a) || builtPath(head->right, path, a))
        return true;
    path.pop_back();
    return false;
}
Node *LCA(Node *head, int x, int y)
{
    vector<Node *> path1, path2;
    if (builtPath(head, path1, x) == false || builtPath(head, path2, y) == false)
        return NULL;
    for (int i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i + 1] != path2[i + 1])
            return path1[i];
    }
    return NULL;
}
Node *LCAeffic(Node *head, int n1, int n2)
{
    if (head == NULL)
        return NULL;
    if (head->key == n1 || head->key == n2)
        return head;
    Node *lca1 = LCAeffic(head->left, n1, n2);
    Node *lca2 = LCAeffic(head->right, n1, n2);
    if (lca1 && lca2)
        return head;
    if (lca1)
        return lca1;
    else
        return lca2;
}
int burnTree(Node *head,int leaf,int &dist,int &res){
   if(head==NULL)
   return 0;
   if(head->key==leaf)
   {dist=0;return 1;}
   int ldist=-1,rdist=-1;
   int lh=burnTree(head->left,leaf,ldist,res);
   int rh=burnTree(head->right,leaf,rdist,res);
   if(ldist!=-1){dist=ldist+1;res=max(res,dist+rh);}
   if(rdist!=-1){dist=rdist+1;res=max(res,dist+lh);}
   return max(lh,rh)+1;
}
int countNodesOfCompleteBT(Node *head)
{
    int leftCount=0;
    int rightCount=0;
    Node *curr=head;
    while(curr)
    {
        curr=curr->left;
        leftCount++;
    }
    curr=head;
    while(curr)
    {
        curr=curr->right;
        rightCount++;
    }
    if(leftCount==rightCount)
    return pow(2,leftCount)-1;
    else
    return countNodesOfCompleteBT(head->left)+countNodesOfCompleteBT(head->right)+1; 
}
//serialization & deserialization of tree
void serialization(Node* head,vector<int>& arr)
{
    if(head==NULL)
    {
        arr.push_back(-1);return;
    }
    arr.push_back(head->key);
    serialization(head->left,arr);
    serialization(head->right,arr);
}
Node *deserialization(vector<int>arr,int &index)
{
    if(index==arr.size())
    return NULL;
    int val=arr[index++];
    if(val==-1)
    return NULL;
    Node *head=new Node(val);
    head->left=deserialization(arr,index);
    head->right=deserialization(arr,index);
    return head;
}
//iterative inorder
void iterativeInorder(Node *head)
{
  stack<Node*>stk;
  Node *curr=head;
  while(curr || !stk.empty())
  {
    while(curr)
    {
        stk.push(curr);
        curr=curr->left;
    } 
    curr=stk.top();stk.pop(); 
    cout<<curr->key<<" ";
    curr=curr->right;
  }
}
void iterativePreorder(Node *head){
 if(head==NULL)
 return;
 stack<Node*>stk;
 stk.push(head);
 while(!stk.empty())
 {
     Node *temp=stk.top();
     cout<<stk.top()->key<<" ";
     stk.pop();
     if(temp->right)
     stk.push(temp->right);
     if(temp->left)
     stk.push(temp->left);
 }
}
main()
{
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    inOrder(head);
    cout << endl;
    preOrder(head);
    cout << endl;
    postOrder(head);
    cout << endl;
    cout << heightOfTree(head) << endl;
    distanceK(head, 1);
    cout << endl;
    levelOrder(head);
    cout << endl;
    levelOrderLineByLine(head);
    // cout<<endl;
    levelOrderLineByLineaAno(head);

    cout << endl;
    cout << countNodes(head) << endl;
    cout << maxValue(head) << endl;
    leftMost(head);
    cout << endl;
    int maxLev = 0;
    leftMostRecursive(head, 1, maxLev);
    cout << endl;
    cout << childrenSumProperty(head) << endl;
    cout << childSumPropertyRecursive(head) << endl;
    cout << isBalanced(head) << endl;
    cout << checkBalanced(head) << endl;
    cout << maxWidth(head) << endl;
    // int index=0;
    // Node *temp=constructTree({})
    spiralTraversal(head);
    spiralTraversalEff(head);
    int res = 0;
    cout << endl
         << diameter(head, res) << endl;
    cout << res << endl;
    cout << LCA(head, 20, 30)->key << endl;
    cout << LCAeffic(head, 20, 30)->key << endl;
    iterativeInorder(head);
    cout<<endl;
    iterativePreorder(head);
    cout<<endl;
    vector<int>temp;
    serialization(head,temp);
    int index=0;
    Node *t=deserialization(temp,index);
    preOrder(t);
}