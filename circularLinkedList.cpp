#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
        return;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
Node *InserBegin(Node *head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        head->next = head;
        return head;
    }
    Node *temp = new Node(data);
    temp->next = head;
    Node *p = head;
    while (p->next != head)
        p = p->next;
    p->next = temp;
    return temp;
}
Node *InserBeginConstant(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int d = head->data;
    head->data = temp->data;
    temp->data = d;
    return head;
}
Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node *curr = head;
    while (curr->next != head)
        curr = curr->next;
    curr->next = temp;
    temp->next = head;
    return head;
}
Node *insertEndeff(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int d = temp->data;
    temp->data = head->data;
    head->data = d;
    return temp;
}
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    else if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != head)
        curr = curr->next;
    curr->next = head->next;
    delete head;
    return curr->next;
}
Node *deleteNodeEffic(Node *head)
{
    if (head == NULL)
        return NULL;
    else if (head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *p = head->next;
    head->data = p->data;
    head->next = p->next;
    delete p;
    return head;
}
Node *deleteAtRandomPos(Node *head, int pos)
{
    if (head == NULL)
        return head;
    else if (pos == 1)
        return deleteNodeEffic(head);
    else if (pos < 1)
        return head;
    Node *temp = head;
    for (int i = 1; i <= pos - 2; i++)
        temp = temp->next;
        Node *p = temp->next;
        temp->next = p->next;
        delete p;
    return head;
}
main()
{
    vector<int> createList{10, 20, 30, 40};
    Node *head = new Node(createList[0]);
    Node *temp = head;
    for (int i = 1; i < createList.size(); i++)
    {
        temp->next = new Node(createList[i]);
        temp = temp->next;
    }
    temp->next = head;
    printList(head);
    head = InserBegin(head, 2);
    head = InserBegin(head, 4);
    printList(head);
    head = InserBeginConstant(head, 22);
    head = InserBeginConstant(head, 32);
    printList(head);
    head = insertEnd(head, 91);
    printList(head);
    head = insertEndeff(head, 79);
    printList(head);
    head = deleteHead(head);
    printList(head);
    head = deleteNodeEffic(head);
    printList(head);
    head = deleteAtRandomPos(head, 5);
    printList(head);
}