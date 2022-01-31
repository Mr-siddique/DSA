#include<bits/stdc++.h>
using namespace std;
class dequeue{
public:
int *arr,capacity,size;
dequeue(int c)
{
    arr=new int[c];
    capacity=c;
    size=0;
}
bool isFull(){return size==capacity;}
bool isEmpty(){return size==0;}
void insertRear(int data){
    if(isFull())
    return;
    arr[size]=data;
    size++;
}
void deleterear(){
    if(isEmpty()==0)
    return;
    size--;
}
int getrear(){
    if(isEmpty())
    return -1;
    return size-1;
}
void insertFront(int data)
{
    if(isFull())
    return;
    for(int i=size-1;i>=0;i--)
    arr[i+1]=arr[i];
    arr[0]=data;
    size++;
}
void deleteFront(){
    if(isEmpty())
    return;
    for(int i=1;i<size;i++)
    arr[i-1]=arr[i];
    size--;
}
int getFront(){
    if(isEmpty())
    return -1;
    return arr[0];
}
};
class dequ{
    private:
    int *arr,size,capacity,front;
    public: 
    dequ(int cap){capacity=cap;size=0;front=0;arr=new int[capacity];} //rear==front+size-1%capacity && front=front-1+capacity%capacity
    bool isEmpty(){return size==0;}
    bool isFull(){return size==capacity;}
    int getRear(){return isEmpty()?-1:(front+size-1)%capacity;}
    void insertRear(int data){
     if(isFull())
     return;
     int rear=getRear();
     rear=(rear+1)%capacity;
     arr[rear]=data;
     size++;
    }
    void deleteRear(){
     if(isEmpty())
     return;
    size--;
    }
    void insertFront(int data){
    if(isFull())
    return;
    front=(front+capacity-1)%capacity;
    arr[front]=data;
    size++;
    }
    void deleteFront(){
     if(isEmpty())
     return;
     front=(front+1)%capacity;    
     size--;    
    }
    int getFront(){return isEmpty()?-1:front;}
};
class myDs{
public:
deque<int>dq;
void insert_min(int data){dq.push_front(data);}
void insert_max(int data){dq.push_back(data);}
int get_min(){return dq.front();}
int get_max(){return dq.back();}
void extract_min(){ dq.pop_front();}
void extract_max(){ dq.pop_back();}
};
void maxofAll(vector<int>arr,int k){
    for(int i=0;i<=arr.size()-k;i++)
        cout<<*max_element(arr.begin()+i,arr.begin()+i+k)<<" ";
    cout<<endl;
}
void maxOfAllEff(vector<int>arr,int k){
    deque<int>dq;
    for(int i=0;i<k;i++){
        while(!dq.empty()&&arr[dq.back()]<arr[i])
        dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<arr.size();i++){
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty()&&dq.front()<=i-k)
        dq.pop_front();
        while(!dq.empty()&&arr[dq.back()]<arr[i])
        dq.pop_back();
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<endl;
}
int circularTour(vector<int>petrol,vector<int>distance){
    deque<int>dq;
    int curr_petrol=0;
    for(int i=0;i<petrol.size();i++){
     dq.push(i);
     curr_petrol=curr_petrol+(petrol[i]-distance[i]);
     while(curr_petrol<0){
         int index=dq.front();
         dq.pop_front();
         curr_petrol=curr_petrol-(petrol[index]-distance[index]);
     }
    }
    return curr_petrol>=0?dq.front():-1;
}
int circularTourEff(vector<int>petrol,vector<int>distance){
    int curr_petrol=0,prev_petrol=0,start=0;
    for(int i=0;i<petrol.size();i++){
      curr_petrol+=(petrol[i]-distance[i]);
      if(curr_petrol<0){
          prev_petrol+=curr_petrol;
          start=i+1;
          curr_petrol==0;
      }
    }
    return curr_petrol+prev_petrol>=0?start+1:-1;
}
main()
{
vector<int>arr={10,8,5,12,15,7,6};
maxofAll(arr,3);
maxOfAllEff(arr,3);
}