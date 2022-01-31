#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node *prev;
 Node *next;
 Node(int x)
 {
     data=x;
     prev=NULL;
     next=NULL;
 }
};
Node* insertbegin(Node *head,int data)
{
    if(head==NULL)
    {
        head=new Node(data);
        head->prev=head;head->next=head;
        return head;
    }
Node *temp=new Node(data);
temp->prev=head->prev;
temp->next=head;
head->prev->next=temp;
head->prev=temp;
return temp;
}
Node *insertEnd(Node *head,int data)
{
        if(head==NULL)
    {
        head=new Node(data);
        head->prev=head;head->next=head;
        return head;
    }
Node *temp=new Node(data);
temp->prev=head->prev;
temp->next=head;
head->prev->next=temp;
head->prev=temp;
return head;
}
main()
{
    vector<int>insert_at_begin={10,20,30,40,50};
}