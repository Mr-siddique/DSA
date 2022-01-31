// #include <iostream>
// #include <algorithm>
// #include <climits>
// #include <vector>
// #include<cmath>
#include <bits/stdc++.h>
using namespace std;
//sort using user defined comparator
struct point
{
    int x, y;
};
bool myComparator(point p, point q)
{
    return (p.x < q.x);
}
//for calling comparator;
// void useComparator(vector<vector<int>>arr){
// sort(arr.begin(),arr.end(),myComparator);
// for(auto i : arr){
//     cout<<i.x<<" "<<i.y<<endl;
// }
// }
void bubbleSort(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
//optimizeed bubble sort takes thetha(n) time if the array is already sorted or after getting the sorted array
void OptimizedBubbleSort(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arr.size() - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (swapped == false)
            break;
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

//selection sort:- less memory writes;
void selectionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int mid_ind = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[mid_ind] > arr[j])
                mid_ind = j;
        }
        swap(arr[mid_ind], arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
//insertions Sort:-
void insertionSort(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

//mergeSort
vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> sorted_res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
            sorted_res.push_back(a[i++]);
        else
            sorted_res.push_back(b[j++]);
    }
    for (; i < a.size(); i++)
        sorted_res.push_back(a[i]);
    for (; j < b.size(); j++)
        sorted_res.push_back(b[j]);
    return sorted_res;
}
// void mergeSort(vector<int>arr){
//     int low,high,mid;
//     low=0;high=arr.size();mid=(low+high)/2;
//     high=mid+1;
//     while(low<=mid&&high<arr.size()){
//         if(arr[low]<=arr[high])
//         cout<<arr[low++]<<" ";
//         else
//         cout<<arr[high++]<<" ";
//     }
//     for(;low<=mid;low++)
//     cout<<arr[low]<<" ";
//     for(;high<arr.size();high++)
//     cout<<arr[high]<<" ";
// }
void MerGe(int arr[], int low, int high, int mid)
{
    int n1, n2;
    n1 = mid - low + 1;
    n2 = high - mid;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];
    int i, j, k;
    i = j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}
void mergeSortAlgorithm(int arr[], int l, int h)
{
    if (h > l)
    {
        int mid = l + (h - l) / 2;
        mergeSortAlgorithm(arr, l, mid);
        mergeSortAlgorithm(arr, mid + 1, h);
        MerGe(arr, l, h, mid);
    }
}
void InterSectionOfTwoSortedArrays(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            int num = a[i];
            while (a[i] == num)
                i++;
            while (b[j] == num)
                j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
}
void unionOfTwoSortedArrays(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (j > 0 && a[j] == a[j - 1])
        {
            j++;
            continue;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < a.size())
    {
        if (i > 0 && a[i] != a[i - 1])
        {
            cout << a[i] << " ";
            i++;
        }
    }
    while (j < b.size())
    {
        if (j > 0 && b[j] != b[j - 1])
        {
            cout << b[j] << " ";
            j++;
        }
    }
}
int countInversionMerge(int arr[], int low, int mid, int high)
{
    int n1, n2, count;
    n1 = mid - low + 1;
    n2 = high - mid;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];
    int i, j, k;
    i = j = count = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            // count+=n1-k;
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            count = count + (n1 - i);
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
    return count;
}
// 8,11,2,5
int countInversion(int arr[], int low, int high)
{
    int res = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        res += countInversion(arr, low, mid);
        res += countInversion(arr, mid + 1, high);
        res += countInversionMerge(arr, low, mid, high);
    }
    return res;
}
//PARTITION
void naivePartion(int arr[], int low, int high, int index)
{
    int *temp = new int(high);
    int j = 0;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= arr[index])
            temp[j++] = arr[i];
    }
    for (int i = low; i < high; i++)
    {
        if (arr[i] > arr[index])
            temp[j++] = arr[i];
    }
    for (int i = low; i < high; i++)
    {
        if (arr[i] > arr[index])
            arr[i] = temp[i];
    }
}
int lomutoPartition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    //returning index of pivot after partition
    return i + 1;
}

int hoarePartiton(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
//quick sort using lomutoPartition
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = lomutoPartition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
//quick sort using hoare partition
void quick_sort(int arr[], int low, int high)
{
    // Begin:
    if (low < high)
    {
        int p = hoarePartiton(arr, low, high);
        quick_sort(arr, low, p);
        //tail call elemenation for reduting function call in stack
        //low=p+1;
        //goto Begin;
        quick_sort(arr, p + 1, high);
    }
}
// kth smallest element:naive solution
int naiveKthSmallest(int arr[], int n, int k)
{
    quick_sort(arr, 0, n - 1);
    return arr[k - 1];
}
int KthSmallestUsingPartiton(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int p = lomutoPartition(arr, low, high); //lomuto
        if (p == k - 1)
            return arr[p];
        else if (p > k - 1)
            high = p - 1;
        else
            low = p + 1;
    }
    return -1;
}
int chocolateDistribution(int arr[], int m, int n)
{
    int size = n - m;
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for (int i = 1; i < size; i++)
        res = min(arr[i + m - 1] - arr[i], res);
    return res;
}
//segregate +ve & -ve
void sortAmongTypes(int arr[], int n)
{
    int i = -1, j = n;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < 0);
        do
        {
            j--;
        } while (arr[j] > 0);
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
    }
}
//dutch national flag algorithm(variation of hoare partiton)
void threeWayPartiton(int arr[], int n)
{
    int low, high, mid;
    low = mid = 0;
    high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[high--]);
    }
}

void threeWayPartitoning(int arr[], int n, int pivot)
{
    int low, high, mid;
    low = mid = 0;
    high = n - 1;
    while (mid < high)
    {
        if (arr[mid] < pivot)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] == pivot)
            mid++;
        else
            swap(arr[high--], arr[mid]);
    }
}
void threewayPartitionAroundARange(int arr[], int n, int lower_bound, int higher_bound)
{
    int low, high, mid;
    low = mid = 0;
    high = n - 1;
    while (mid < high)
    {
        if (arr[mid] < lower_bound)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] > higher_bound)
            swap(arr[high--], arr[mid]);
        else
            mid++;
    }
}
bool myComp(vector<int> a, vector<int> b)
{
    return b[0] > a[0];
}

void mergeIntervals(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end(), myComp);
    int res = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= intervals[res][1])
        {
            intervals[res][1] = max(intervals[i][1], intervals[res][1]);
            intervals[res][0] = min(intervals[i][0], intervals[res][0]);
        }
        else
        {
            res++;
            intervals[res] = intervals[i];
        }
    }
    for (int i = 0; i <= res; i++)
        cout << intervals[i][0] << " " << intervals[i][1] << endl;
}
void meetGuests(vector<int> arr, vector<int> brr)
{
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int i, j, count, res;
    i = count = res = 1;
    j = 0;
    while (i < arr.size() && j < brr.size())
    {
        if (brr[j] >= arr[i])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        res = max(res, count);
    }
    // result=max(result,count);
    cout << res << endl;
}
//cycleSort=>it does minimum memory writes....in place but not stable
void cycleSortDistinct(vector<int> arr)
{
    for (int cs = 0; cs < arr.size() - 1; cs++)
    {
        int item = arr[cs];
        int count = cs;
        for (int i = cs + 1; i < arr.size(); i++)
            if (arr[i] < item)
                count++;
        if (count == cs)
            continue;
        while (item == arr[count])
            count++;
        if (count != cs)
            swap(item, arr[count]);
        while (cs != count)
        {
            count = cs;
            for (int i = cs + 1; i < arr.size(); i++)
            {
                if (arr[i] < item)
                    count++;
            }
            while (item == arr[count])
                count++;
            if (arr[count] != item)
                swap(item, arr[count]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}
void buildHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}
void heapSort(vector<int> arr)
{
    buildHeap(arr);
    for (int i = arr.size() - 1; i >= 1; i--)
    {
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0);
    }
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
//naive counting sort
void countingSort(vector<int> arr, int k)
{
    vector<int> temp(k);
    for (int i = 0; i < arr.size(); i++)
    {
        temp[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < temp[i]; j++)
        {
            arr[index++] = i;
        }
    }
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
//general purpose counting sort
void countSort(vector<int> arr, int k)
{
    vector<int> count(k), temp(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i]]++;
    for (int i = 1; i < arr.size(); i++)
        count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        temp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
}
//radixSort
void cSort(vector<int> &arr, int exp) //this counting sort implementation is for radix sort
{
    vector<int> count(10), temp(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < arr.size(); i++)
        arr[i] = temp[i];
}
void radixSort(vector<int> arr)
{
    int mx = arr[0];
    for (int i = 0; i < arr.size(); i++)
        mx = max(arr[i], mx);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        cSort(arr, exp);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
void bucketSort(vector<int> arr, int k)
{
    vector<int> bucket[k];
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        mx = max(mx, arr[i]);
    mx++;
    for (int i = 0; i < arr.size(); i++)
    {
        int bi = (k * arr[i]) / mx; /*this formulla defines the proper index*/
        bucket[bi].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
        sort(bucket[i].begin(), bucket[i].end());
    int index = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
            cout << arr[--index] << " ";
        }
}
main()
{
    vector<vector<int>> intervals = {{5, 10}, {3, 15}, {18, 30}, {2, 7}};
    vector<int> interval = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};
    // useComparator({{3,10},{2,8},{5,4}});
    bubbleSort({1, 6, 2, 3, 11, 9});
    OptimizedBubbleSort({1, 2, 3, 4, 0});
    selectionSort({1, 6, 2, 3, 11, 9});
    insertionSort({1, 6, 2, 3, 11, 9, 1, 2, 21, 11, 37, 4});
    int arr[] = {10, 5, 30, 15, 7};
    // vector<int> temp(arr.size());
    mergeSortAlgorithm(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    // MerGe(arr,0,0,0);
    cout << endl;
    InterSectionOfTwoSortedArrays({3, 5, 10, 10, 10, 15, 20}, {5, 10, 10, 15, 30});
    cout << endl;
    unionOfTwoSortedArrays({3, 5, 8}, {2, 8, 9, 10, 15});
    int a[] = {2, 4, 1, 3, 5};
    cout << endl
         << "inversionCount"<<countInversion(a, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int b[] = {30, 20, 5, 10, 8};
    // cout<<naiveKthSmallest(b,5,4)<<endl;
    cout << KthSmallestUsingPartiton(b, 5, 4) << endl;
    int c[] = {7, 3, 2, 4, 9, 12, 56};
    cout << chocolateDistribution(c, 3, 7) << endl;
    int d[] = {2, 1, 2, 20, 10, 20, 1};
    // sortAmongTypes(d, 4);
    threeWayPartitoning(d, 7, 2);
    for (int i = 0; i < 7; i++)
        cout << d[i] << " ";
    cout << endl;
    int e[] = {10, 5, 6, 3, 20, 9, 40};
    threewayPartitionAroundARange(e, 7, 5, 10);
    for (int i = 0; i < 7; i++)
        cout << e[i] << " ";
    cout << endl;

    mergeIntervals(intervals);
    cout << endl;
    meetGuests(interval, departure);
    cycleSortDistinct({20, 40, 50, 10, 30, 10});
    vector<int> heap = {10, 50, 4, 15, 20};
    heapSort(heap);
    cout << endl;
    countingSort({1, 4, 4, 1, 0, 1}, 5);
    cout << endl;
    countSort({1, 4, 4, 1, 0, 1}, 5);
    cout << endl;
    radixSort({319, 212, 6, 8, 100, 50});
    cout << endl;
    bucketSort({20, 80, 10, 85, 75, 99, 18}, 5);
}