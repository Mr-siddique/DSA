#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int activitySelection(vector<pair<int, int>> interval)
{
    if (interval.size() == 1)
        return 1;
    sort(interval.begin(), interval.end(), comp);
    int count = 1;
    int prev = 0;
    for (int i = 1; i < interval.size(); i++)
    {
        if (interval[i].first >= interval[prev].second)
        {
            count++;
            prev = i;
        }
    }
    return count;
}
struct items
{
    int weight;
    int value;
    double ratio;
    items(int w, int v)
    {
        weight = w;
        value = v;
        ratio = (v / w);
    }
};
bool my_comp(items a, items b)
{
    return a.ratio > b.ratio;
}
int fractionalKnapsack(vector<items> itm, int capacity)
{
    int n = itm.size();
    sort(itm.begin(), itm.end(), my_comp);
    for (int i = 0; i < n; i++)
        cout << itm[i].weight << " " << itm[i].value << " " << itm[i].ratio << endl;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (itm[i].weight <= capacity)
        {
            res += itm[i].value;
            capacity -= itm[i].weight;
        }
        else
        {
            res += itm[i].value * ((double)capacity / itm[i].weight);
            break;
        }
    }
    return res;
}
bool myComp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second < p2.second;
}
int jobSequencing(vector<pair<int, int>> jobs)
{
    int profit = 0;
    sort(jobs.begin(), jobs.end(), myComp);
    int timer = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        if (timer < jobs[i].second)
        {
            profit += jobs[i].first;
            timer++;
        }
    }
    return profit;
}
struct Node
{
    /* data */
    char data;
    int freq;
    Node *left, *right;
    Node(int f, char d)
    {
        data = d;
        freq = f;
        left = right = NULL;
    }
};
struct nodeComp{
bool operator()(Node *a,Node *b){
    return a->freq>b->freq;
}
};
Node* createTree(vector<pair<int, char>> seq)
{
    priority_queue<Node*,vector<Node*>,nodeComp> pq;
    for (int i = 0; i < seq.size(); i++)
        pq.push(new Node(seq[i].first, seq[i].second));
    
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *newNode=new Node(left->freq+right->freq,'$');
        newNode->left=left;
        newNode->right=right;
        pq.push(newNode);
    }
    return pq.top();
}
void printCodes(Node *root,string str){
    if(root==NULL)
    return;
    if(root->data!='$')
    cout<<root->data<<" "<<str<<endl;
    printCodes(root->left,str+'0');
    printCodes(root->right,str+'1');
    // cout<<root->data<<" "<<root->freq<<" ";
    // printCodes(root->left,str);
    // printCodes(root->right,str);
}
int main()
{
    // vector<pair<int,int>>interval={{2,3},{1,4},{5,8},{6,10}};
    vector<pair<int, int>> interval = {{1, 3}, {2, 4}, {3, 8}, {10, 11}};
    cout << activitySelection(interval) << endl;
    vector<items> itm;
    vector<int> weight = {50, 20, 30};
    vector<int> value = {600, 500, 400};
    for (int i = 0; i < weight.size(); i++)
    {
        items it(weight[i], value[i]);
        itm.push_back(it);
    }
    cout << fractionalKnapsack(itm, 70) << endl;
    vector<pair<int, int>> jobs = {{50, 4}, {5, 1}, {20, 1}, {10, 5}, {80, 5}};
    cout << jobSequencing(jobs) << endl;
    vector<pair<int,char>>data={{100,'a'},{50,'d'},{20,'b'},{40,'e'},{80,'f'}};
    Node *root=createTree(data);
    printCodes(root,"");
    return 0;
}
