#include <bits/stdc++.h>
using namespace std;
//queue using array
class Queue
{
public:
    vector<int> Q;
    int top = -1;
   
    void enqueue(int data)
    {
        if (top == -1)
            top++;
        Q.push_back(data);
    }
    int dequeue()
    {
        if (top == -1)
            return -1;
        int d = Q[top];
        Q.erase(Q.begin(), Q.begin() + 1);
        return d;
    }
    int size()
    {
        return Q.size();
    }
    int getFront()
    {
        if (Q.size() > 0)
            return Q[top];
        return -1;
    }
    int getRear()
    {
        if (Q.size() > 0)
            return Q.back();
        return -1;
    }
    bool isEmpty()
    {
        return Q.size() == 0;
    }
    void displayQueue()
    {
        for (int i = 0; i < Q.size(); i++)
            cout << Q[i] << " ";
        cout << endl;
    }
};
//queue using circular array
class circularQueue
{
public:
    int *arr, front, capacity, size;
    circularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    int getFront()
    {
        if (!isEmpty())
            return arr[front];
        return -1;
    }
    int getRear()
    {
        if (!isEmpty())
            return arr[front + size - 1] % capacity;
        return -1;
    }
    void enqueue(int data)
    {
        if (isFull())
            return;
        int rear = (front + size - 1) % capacity;
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }
    int dequeue()
    {
        if (isEmpty() == 0)
            return -1;
        int data = arr[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }
};
//queue using linked Node
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
class queuelist
{
public:
    Node *front, *rear;
    int size;
    queuelist()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getFront()
    {
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }
    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if (front == NULL)
        {
            front = temp;
            rear = front;
        }
        rear->next = temp;
        rear = rear->next;
        size++;
    }
    int dequeue()
    {
        if (size == 0)
            return -1;
        Node *temp = front;
        front = front->next;
        int d = temp->data;
        delete temp;
        size--;
        if(size==0)
        rear=NULL;
        return d;
    }
    int getSize()
    {
        return size;
    }
};
//stack using quueue
class stack{
queue<int>q1,q2;
public:
void push(int data)
{
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(data);
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}
int pop(){
    if(q1.empty())
    return -1;
    int d=q1.front();
    q1.pop();
    return d;
}
};
void reverseQueue(queue<int>&q)
{
    if(q.empty())
    return;
    int d=q.front();
    q.pop();
    reverseQueue(q);
    q.push(d);
}
void generateTillN(int n)
{
    queue<string>q;
    string a=to_string(5);string b=to_string(6);
    q.push(a);
    q.push(b);
    for(int i=0;i<n;i++)
    {
        string temp=q.front();
        q.pop();
        cout<<temp<<" ";
        q.push(temp+'5');
        q.push(temp+'6');
    }
cout<<endl;
}
main()
{
    queuelist q;
    q.enqueue(22);
    q.enqueue(33);
    q.enqueue(33);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.dequeue() << endl;
    cout << q.getFront() << endl;
    cout<<q.getSize()<<endl;
    queue<int>que;
    que.push(10);que.push(20);que.push(30);que.push(40);que.push(50);
    reverseQueue(que);
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
    cout<<endl;
    generateTillN(10);
}