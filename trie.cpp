#include<bits/stdc++.h>
using namespace std;
struct trieNode{
    trieNode *child[26];
    bool isEnd;
    trieNode(){
        for(int i=0;i<26;i++)
        child[i]=NULL;
        isEnd=false;
    }
};
void insert(string str,trieNode *root){
    trieNode *temp=root;
    for(int i=0;i<str.length();i++){
     int index=str[i]-'a';
     if(temp->child[index]==NULL)
     temp->child[index]=new trieNode();
     temp=temp->child[index];
    }
    temp->isEnd=true;
}
int search(string str,trieNode *root){
    trieNode *temp=root;
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        if(temp->child[index]==NULL)
        return false;
        temp=temp->child[index];
    }
    return temp->isEnd;
}
bool isEmpty(trieNode *root){
    for(int i=0;i<26;i++){
        if(root->child[i]!=NULL)
        return false; 
    }
    return true;
}
trieNode* deleteWord(string word,int i,trieNode *root) {
    if(root==NULL)
    return root;
    if(i==word.length())
    {
        root->isEnd = false;
        if(isEmpty(root)==true)
        {
            delete root; root=NULL;
        }
        return root;
    }
    int index=word[i]-'a';
    root->child[index]=deleteWord(word,i+1,root->child[index]);
    if(isEmpty(root)==true&&root->isEnd==false){
        delete root; root=NULL;
    }
    return root;
}
struct trie{
    trie *child[2];
    trie(){
        child[0]=NULL;child[1]=NULL;
    }
};
bool insert(vector<int> arr,trie *root){
    int m=arr.size(); 
    trie *curr=root;
    bool flag=false;
    for(int i=0;i<m;i++){
        int index=arr[i];
        if(curr->child[index]==NULL){
            curr->child[index]=new trie();
            flag=true;
        }
            curr=curr->child[index];
    }
    return flag;
}
int countDistinct(vector<vector<int>>arr){
    int n=arr.size();
    trie *root=new trie();
    int count=0;
    for(int i=0;i<n;i++){
        if(insert(arr[i],root)==true) 
        count++;  
    }
    return count;
}
main(){
  trieNode *root=new trieNode();
  vector<string>keys = {"bad", "bat", "geek", "geeks", "cat", "cut"}; 
  for(int i=0;i<keys.size();i++)
  insert(keys[i],root);
  cout<<search("bat",root)<<endl;

  cout<<search("ca",root)<<endl;
  cout<<deleteWord("geek",0,root)<<endl;
  cout<<search("geek",root)<<endl;
  cout<<countDistinct({{1,0,0},{1,1,1},{1,0,0},{1,0,0}})<<endl;
}