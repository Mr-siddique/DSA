#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    Node()
    {
        data = -1;
        next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void traverseLisstrecursively(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    traverseLisstrecursively(head->next);
}
Node *insertInTheBegining(int data, Node *head)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}
Node *insertAtTheEnd(int data, Node *head)
{
    if (head == NULL)
        head = new Node(data);
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node(data);
    }
    return head;
}
Node *deletefromBegining(Node *head)
{
    if (!head)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteAtTheend(Node *head)
{
    if (!head)
        return head;
    else if (!head->next)
    {
        delete head;
        return head;
    }
    else
    {
        Node *p = head, *q = NULL;
        while (p->next)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        delete p;
        return head;
    }
}
Node *InserAtAgivenPos(Node *head, int data, int position)
{
    Node *p = head, *q = NULL;
    if (position < 1 || head == NULL && position > 1)
        return head;
    else if (head == NULL)
        head = new Node(data);
    else
    {
        if (position == 1)
        {
            q = new Node(data);
            q->next = head;
            //   delete head;
            return q;
        }
        else
        {
            while (p)
            {
                /* code */
                q = p;
                p = p->next;
                position -= 1;
                if (position == 1)
                    break;
            }
            if (position == 1)
            {
                q->next = new Node(data);
                q->next->next = p;
            }
        }
    }
    return head;
}
Node *insertAtPos(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
        curr = curr->next;
    if (curr == NULL)
        return head;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int searchElement(Node *head, int data)
{
    int count = 1;
    while (head)
    {
        if (head->data == data)
            return count;
        head = head->next;
        count++;
    }
    return -1;
}
int searchElementRecursively(Node *head, int data)
{
    if (head == NULL)
        return -1;
    else if (head->data == data)
        return 1;
    else
    {
        int x = searchElementRecursively(head->next, data);
        if (x == -1)
            return -1;
        else
            return x + 1;
    }
}
Node *sortedInsert(Node *head, int data)
{
    Node *temp = new Node(data);
    if (!head)
        return temp;
    Node *curr = head, *t = NULL;
    while (curr && curr->data < data)
    {
        t = curr;
        curr = curr->next;
    }
    if (curr == head)
    {
        temp->next = head;
        return temp;
    }
    temp->next = curr;
    t->next = temp;
    return head;
}
void MiddleNodeNaive(Node *head)
{
    int count = 0;
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    count /= 2;
    // count++;
    temp = head;
    while (count--)
    {
        temp = temp->next;
    }
    cout << temp->data << endl;
}
void middleNodeEff(Node *head)
{
    if (head == NULL)
        return;
    Node *slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}
void findnthNodelast(Node *head, int n)
{
    if (head == NULL)
        return;
    Node *fast = head, *slow = head;
    while (n--)
    {
        if (fast == NULL)
            return;
        fast = fast->next;
    }
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << slow->data << endl;
}
Node *reverseList(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}
Node *reverseListRecursively(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = reverseListRecursively(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
Node *reverseListRecursively2(Node *head, Node *prev)
{
    if (head == NULL)
        return prev;
    Node *res_tail = head->next;
    head->next = prev;
    return reverseListRecursively2(res_tail, head);
}
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
            curr = curr->next;
    }
    return head;
}
Node *reverseListInwindow(Node *head, int k)
{
    int count = 0;
    Node *p = head;
    Node *q = NULL;
    Node *r;
    while (p && count < k)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
        count++;
    }
    if (p != NULL)
        head->next = reverseListInwindow(p, k);
    return q;
}
Node *reverseListInwindowIteratively(Node *head, int k)
{
    Node *p, *prevHead = NULL;
    bool isFirstPass = true;
    p = head;
    while (p != NULL)
    {
        Node *first = p, *q = NULL, *r;
        int count = 0;
        while (p != NULL && count < k)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            count++;
        }
        if (isFirstPass)
        {
            head = q;
            isFirstPass = false;
        }
        else
        {
            prevHead->next = q;
        }
        prevHead = first;
    }
    return head;
}
//destroyes the list
bool isLoop(Node *head)
{
    Node *temp = new Node;
    Node *curr = head;
    while (curr)
    {
        if (curr->next == NULL)
            return true;
        if (curr->next == temp)
            return false;
        Node *next = curr->next;
        curr->next = temp;
        curr = next;
    }
    return false;
}
//using hashing
bool is_Loop(Node *head)
{
    unordered_set<Node *> s;
    Node *curr = head;
    while (curr)
    {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return true;
}
//floydcycle
bool detectLoop(Node *head)
{
    Node *p = head, *q = head;
    while (p != NULL && p->next != NULL)
    {
        q = q->next;
        p = p->next->next;
        if (p == q)
            return true;
    }
    return false;
}
void detectAndRemoveLoop(Node *head)
{
    Node *p = head, *q = head;
    while (p != NULL && p->next != NULL)
    {
        q = q->next;
        p = p->next->next;
        if (p == q)
            break;
    }
    if (p != q)
        return;
    q = head;
    while (q->next != p->next)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
}
void deleteNodeRandomly(Node *deleteThis)
{
    Node *temp = deleteThis->next;
    deleteThis->data = temp->data;
    deleteThis->next = temp->next;
    delete temp;
}
Node *evenOdd(Node *head)
{
    Node *evenStart, *evenEnd, *oddStart, *oddEnd;
    evenStart = evenEnd = oddStart = oddEnd = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        int d = curr->data;
        if (d % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = curr;
                evenEnd = curr;
            }
            else
            {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = curr;
                oddEnd = curr;
            }
            else
            {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
    }
    if (evenStart == NULL || oddStart == NULL)
        return head;
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}
// using hashing
int interSectionPoint(Node *head1, Node *head2)
{
    unordered_set<Node *> s;
    while (head1)
    {
        s.insert(head1);
        head1 = head1->next;
    }
    while (head2)
    {
        if (s.find(head2) != s.end())
            return head2->data;
        head2 = head2->next;
    }
    return -1;
}
int interSection_point(Node *head1, Node *head2)
{
    int countHead1 = 0, countHead2 = 0;
    Node *curr = head1;
    while (curr)
    {
        countHead1++;
        curr = curr->next;
    }
    curr = head2;
    while (curr)
    {
        countHead2++;
        curr = curr->next;
    }
    curr = countHead1 > countHead2 ? head1 : curr = head2;
    Node *temp = curr == head1 ? head2 : head1;
    int absolute_count = abs(countHead1 - countHead2);
    for (int i = 1; i <= absolute_count; i++)
        curr = curr->next;
    while (temp && curr)
    {
        if (curr == temp)
            return curr->data;
        curr = curr->next;
        temp = temp->next;
    }
    return -1;
}
Node *pairwiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *first = head, *second = head->next;
    int d;
    if (second->next == NULL)
    {
        d = second->data;
        second->data = first->data;
        first->data = d;
    }
    while (second->next)
    {
        d = first->data;
        first->data = second->data;
        second->data = d;
        first = first->next->next;
        if (first->next == NULL)
            return head;
        second = second->next->next;
    }
    d = first->data;
    first->data = second->data;
    second->data = d;
    return head;
}
//changing pointerlinks
Node *swapPairwise(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr && curr->next)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = prev;
        curr = next;
    }
    prev->next = curr;
    return head;
}
Node *random(Node *head)
{
    // for (Node *curr = head; curr != NULL; curr = curr->next)
    // {
    //     Node *next = curr->next;
    //     curr->next = new Node(curr->data);
    //     curr->next->next = next;
    //     curr = next;
    // }
    // for (Node *curr = head; curr != NULL; curr = curr->next->next)
    //     curr->next->random = curr->next->random == NULL ? NULL : curr->random->next;
}
Node *mergeSortedList(Node *head1,Node *head2)
{
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    Node *p,*q,*head,*tail;
    p=head1;
    q=head2;
    if(p->data<q->data)
    {
        head=p;p=p->next;
    }else{
        head=q;
        q=q->next;
    }
    tail=head;
    while(p&&q)
    {
       if(p->data<q->data){
       tail->next=p;
       tail=tail->next;
       p=p->next;
       }
       else{
       tail->next=q;
       tail=tail->next;
       q=q->next;
       }
    }
    if(p!=NULL)
    tail->next=p;
    else 
    tail->next=q;
    return head;
}
bool palindromeList(Node *head)
{
    if(head==NULL)
    return true;
    Node *fast,*slow;
    fast=slow=head;
    // fast=fast->next;
    while(fast->next&&fast->next->next)
    {
        slow=slow->next;fast=fast->next->next;
    }
    Node *rev=reverseList(slow->next);
    Node *curr=head;
    while(rev)
    {
        if(rev->data!=curr->data)
        return false;
        rev=rev->next;curr=curr->next;
    }
    return true;
}
main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    cout << endl;
    traverseLisstrecursively(head);
    cout << endl;
    head = insertInTheBegining(5, head);
    printList(head);
    head = NULL;
    head = insertAtTheEnd(5, head);
    head = insertAtTheEnd(10, head);
    head = insertAtTheEnd(15, head);
    head = insertAtTheEnd(20, head);
    cout << endl;
    printList(head);
    cout << endl;
    head = deletefromBegining(head);
    printList(head);
    cout << endl;
    head = deleteAtTheend(head);
    printList(head);
    cout << endl;

    // head=InserAtAgivenPos(head,18,3);
    // printList(head);
    cout << endl;
    head = insertAtPos(head, 3, 3);
    printList(head);
    cout << endl;
    cout << searchElement(head, 10) << endl;
    cout << searchElementRecursively(head, 10) << endl;
    vector<int> insertSorted = {1, 2, 3, 4, 5, 6, 7};
    Node *temp = NULL;
    for (int i = 0; i < insertSorted.size(); i++)
        temp = sortedInsert(temp, insertSorted[i]);
    printList(temp);
    cout << endl;
    MiddleNodeNaive(temp);
    findnthNodelast(temp, 5);
    temp = reverseList(temp);
    printList(temp);
    cout << endl;
    temp = reverseListRecursively(temp);
    printList(temp);
    cout << endl;
    temp = reverseListRecursively2(temp, NULL);
    printList(temp);
    cout << endl;
    temp = removeDuplicates(temp);
    printList(temp);
    cout << endl;
    temp = reverseListInwindowIteratively(temp, 3);
    printList(temp);
    cout << endl;
    temp = evenOdd(temp);
    printList(temp);
    cout << endl;
    temp = pairwiseSwap(temp);
    printList(temp);
    cout << endl;
    temp = swapPairwise(temp);
    printList(temp);
    cout << endl;
    Node* h1,*h2;
    h1=h2=NULL;
    vector<int>v1{10,20,30,40};
    vector<int>v2{5,15,17,18,35};
    for(int i=0;i<v1.size();i++)
    h1=insertAtTheEnd(v1[i],h1);
    for(int i=0;i<v2.size();i++)
    h2=insertAtTheEnd(v2[i],h2);

    Node *h=mergeSortedList(h1,h2);
    printList(h);
}