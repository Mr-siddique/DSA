#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};
Node* insertAtBegin(Node *head,int data)
{
    Node *temp=new Node(data);
    temp->next=head;
    if(head!=NULL)
    head->prev=temp;
    return temp;
}
void displayList(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* InsertAtEnd(Node *head,int data)
{
    Node *temp;
    if(head==NULL){
    head=new Node(data);
    return head;
    }
    temp=head;
    while(temp->next)
    temp=temp->next;
    temp->next=new Node(data);
    temp->next->prev=temp;
    return head;

}
Node* reversedll(Node *head)
{
    if(head==NULL||head->next==NULL)
    return head;
    Node *curr=head,*prev=NULL;
    while(curr!=NULL)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}
Node* deleteFirstNode(Node *head)
{
    if(head==NULL)
    return head;
    Node *temp=head->next;
    delete head;
    if(temp!=NULL)
    temp->prev=NULL;
    return temp;
}
Node * deleteLastNode(Node *head)
{
    if(head==NULL)
    return NULL;
    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *p;
   p=head;
   while(p->next)
       p=p->next;
   p->prev->next=NULL;
   delete p;
   return head;
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->prev=head;
    head->next->next=new Node(30);
    head->next->next->prev=head->next;
    displayList(head);
    head=insertAtBegin(head,5);
    displayList(head);
    head=InsertAtEnd(head,40);
    displayList(head);
    head=reversedll(head);
    displayList(head);
    head=deleteFirstNode(head);
    displayList(head);
    head=deleteLastNode(head);
    displayList(head);
}