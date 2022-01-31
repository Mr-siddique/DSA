#include <bits/stdc++.h>
using namespace std;
// left=2i+1;
// right=2i+2;
// parent=(i-1)/2
class minHeap
{
private:
    int *arr;
    int capacity;
    int size;

public:
    minHeap(int c)
    {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    void traverseHeap()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void insert(int data)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = data;
        int i = size - 1;
        while (arr[parent(i)] > arr[i] && i != 0)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    {
        int lt = left(i), rt = right(i), min_index = i;
        while (lt < size && arr[lt] < arr[min_index] || rt < size && arr[rt] < arr[min_index])
        {
            if (lt < size && arr[lt] < arr[min_index])
                min_index = lt;
            if (rt < size && arr[rt] < arr[min_index])
                min_index = rt;
            if (min_index == i)
                break;
            swap(arr[min_index], arr[i]);
            lt = left(min_index);
            rt = right(min_index);
        }
    }
    void min_heapify(int i)
    {
        int lt = left(i), rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[i])
            smallest = lt;
        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            min_heapify(smallest);
        }
    }
    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        else if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        min_heapify(0);
        return arr[size];
    }
    void decreaseKey(int index, int data)
    {
        arr[index] = data;
        while (arr[parent(index)] > arr[index] && index != 0)
        {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }
    void deleteKey(int index)
    {
        decreaseKey(index, INT_MIN);
        extractMin();
    }
    void builtHeap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
            min_heapify(i);
    }
};
void maxHeapify(int arr[], int n, int index)
{
    int left, right, largest = index;
    left = (2 * index + 1);
    right = 2 * index + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        maxHeapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0);
    }
}
//using user defined comparator fundtion for user defined data types
struct person
{
    /* data */
    int age;
    int height;
    person(int a, int h)
    {
        age = a;
        height = h;
    }
};
// struct myComp
// {
//    bool operator()(struct person const &p1,struct person const &p2 )
//    {
//        return p1.height<p2.height;
//    }
// };
void k_SortedArray(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i <= k; i++)
        pq.push(arr[i]);
    int index = 0;
    for (int i = k + 1; i < arr.size(); i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}
int buyMaxItems(vector<int> arr, int sum)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int count = 0;
    int temp = 0;
    while (!pq.empty())
    {
        temp += pq.top();
        pq.pop();
        if (temp > sum)
            return count;
        count++;
    }
    return count;
}
void k_largetElements(vector<int> arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k - 1);
    for (int i = k; i < arr.size(); i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
void k_ClosetElement(vector<int> arr, int k, int x)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({abs(x - arr[i]), i});
    }
    for (int i = k; i < arr.size(); i++)
    {
        if (abs(arr[i] - x) < pq.top().first)
        {
            pq.pop();
            pq.push({abs(arr[i] - x), i});
        }
    }
    while (!pq.empty())
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}
struct array_sturucture
{
    /* data */
    int value;
    int arrIndex;
    int elIndex;
    array_sturucture(int val, int index_a, int index_b)
    {
        value = val;
        arrIndex = index_a;
        elIndex = index_b;
    }
};
struct myComp
{
    bool operator()(struct array_sturucture const &p1, struct array_sturucture const &p2)
    {
        return p1.value > p2.value;
    }
};
void mergeK_sortedArrays(vector<vector<int>> arr)
{
    priority_queue<array_sturucture, vector<array_sturucture>, myComp> pq;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        array_sturucture a(arr[i][0], i, 0);
        pq.push(a);
    }
    while (!pq.empty())
    {
        array_sturucture a = pq.top();
        pq.pop();
        res.push_back(a.value);
        int arrIndex = a.arrIndex;
        int elIndex = a.elIndex;
        elIndex++;
        if (elIndex < arr[arrIndex].size())
            pq.push(array_sturucture(arr[arrIndex][elIndex], arrIndex, elIndex));
    }
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    cout<<endl;
}
void medianOfStream(vector<int>arr)
{
  cout<<arr[0]<<" "<<(arr[1]+arr[0])/2<<" ";
//   sort(arr.begin(),arr.end());
  for(int i=2;i<arr.size();i++)
  {
      sort(arr.begin(),arr.begin()+i+1);
      if(i%2==0)
      cout<<arr[(i+1)/2]<<" ";
      else
      cout<<((double)arr[i/2]+arr[i/2+1])/2<<" ";  
  }
  cout<<endl;
}
void median_of_stream(vector<int>arr)
{
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int>>g;
    s.push(arr[0]);
     cout<<arr[0]<<" ";
    for(int i=1;i<arr.size();i++)
    {
    //   int num=arr[i];
      if(s.size()>g.size())
      {
          if(s.top()>arr[i]){
           g.push(s.top());
           s.pop();
           s.push(arr[i]);
          }else{
          g.push(arr[i]);
          }
          cout<<(s.top()+g.top())/2.0<<" ";
      }else{
          if(arr[i]<=s.top())
          s.push(arr[i]);
          else{
              g.push(arr[i]);
              s.push(g.top());
              g.pop();
          }
          cout<<s.top()<<" ";
      }
    }
    cout<<endl;
}
main()
{
    // minHeap syntax priority_queue<int,vector<int>,greater<int>>pq;
    // maxHeap syntax priority_queue<int>pq;
    // pushing whole array to the priority queue priority_queue<int>pq(arr,arr+n);
    int arr[] = {10, 20, 15, 40, 50, 100, 25, 45};
    minHeap h(10);
    for (int i = 0; i < 8; i++)
        h.insert(arr[i]);
    h.traverseHeap();
    h.insert(12);
    h.traverseHeap();
    cout << h.extractMin() << endl;
    h.traverseHeap();
    int a[] = {10, 5, 20, 2, 4, 8};
    heapSort(a, 6);
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    cout << endl;
    vector<int> v = {9, 8, 7, 19, 18};
    k_SortedArray(v, 2);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    cout << buyMaxItems({1, 12, 5, 111, 200}, 10) << endl;
    k_largetElements(v, 3);
    k_ClosetElement({30, 40, 32, 33, 36, 37}, 3, 38);
    cout<<endl;
    mergeK_sortedArrays({{10, 20}, {5, 15}, {4, 9, 11}});
    medianOfStream({25,7,10,15,20});
    median_of_stream({12,15,10,5,8,7,11});
}