#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int binarySearch(vector<int> arr, int elem)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == elem)
            return mid;
        else if (arr[mid] > elem)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
int RbinarySearch(vector<int> arr, int low, int high, int elem)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (arr[mid] == elem)
        return mid;
    if (arr[mid] > elem)
        high = mid - 1;
    else
        low = mid + 1;
    return RbinarySearch(arr, low, high, elem);
}
int firstOccurenseInsortedArray(vector<int> arr, int elem)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == elem)
        {
            if (arr[mid] == arr[mid - 1] && mid != 0)
                j = mid - 1;
            else
                return mid;
        }
        else if (arr[mid] > elem)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
int recursiveFirstOccurenceInSortedArray(vector<int> arr, int low, int high, int elem)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (arr[mid] == elem)
    {
        if (arr[mid] != arr[mid - 1] || mid == 0)
            return mid;
        else
            return recursiveFirstOccurenceInSortedArray(arr, low, mid - 1, elem);
    }
    if (arr[mid] > elem)
        high = mid - 1;
    else
        low = mid + 1;
    return recursiveFirstOccurenceInSortedArray(arr, low, high, elem);
}
int recursiveLastOccInSortedArray(vector<int> arr, int low, int high, int elem)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (arr[mid] == elem)
    {
        if (arr[mid] != arr[mid + 1] || mid == arr.size() - 1)
            return mid;
        else
            return recursiveLastOccInSortedArray(arr, mid + 1, high, elem);
    }
    if (arr[mid] > elem)
        high = mid - 1;
    else
        low = mid + 1;
    return recursiveLastOccInSortedArray(arr, low, high, elem);
}
int lastOccInSortedArray(vector<int> arr, int elem)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == elem)
        {
            if (arr[mid] != arr[mid + 1] || mid == arr.size() - 1)
                return mid;
            else
                i = mid + 1;
        }
        else if (arr[mid] > elem)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
int countOcc(vector<int> arr, int elem)
{
    int i = 0;
    int j = arr.size() - 1;
    int count = 0;

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == elem)
        {
            int temp = mid;
            while (arr[temp] == arr[mid] && temp < arr.size())
            {
                count++;
                temp++;
            }
            temp = mid - 1;
            while (arr[temp] == arr[mid] && temp > -1)
            {
                temp--;
                count++;
            }
            return count;
        }
        else if (arr[mid] > elem)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return count;
}
int count1sinSortedBinaryArray(vector<int> arr)
{
    int first = firstOccurenseInsortedArray(arr, 1);
    if (first == -1)
        return 0;
    return arr.size() - first;
}
int findfloorSqrt(int n)
{
    int i = 1;
    int j = n, ans = -1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        int sqMid = mid * mid;
        if (sqMid == n)
            return mid;
        else if (sqMid > n)
            j = mid - 1;
        else
        {
            i = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int search(int arr[], int elem)
{
    int i = 1;
    if (arr[0] == elem)
        return i;
    while (arr[i] < elem)
        i *= 2;
    if (arr[i] == elem)
        return i;
    int j = i - 1;
    i = j / 2 + 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == elem)
            return mid;
        else if (arr[mid] > elem)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
int searchCircularly(vector<int> arr, int elem)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == elem)
            return mid;
        else if (arr[mid] > arr[i])
        {
            if (elem >= arr[i] && elem < arr[mid])
                j = mid - 1;
            else
                i = mid + 1;
        }
        else
        {
            if (elem <= arr[j] && elem > arr[mid])
                i = mid + 1;
            else
                j = mid - 1;
        }
    }
    return -1;
}
int findPeak(vector<int> arr)
{
    if (arr.size() == 1)
        return arr[0];
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[arr.size() - 1] >= arr[arr.size() - 2])
        return arr.size() - 1;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
    return -1;
}
int findPeekAgain(vector<int> arr)
{
    int i = 0, j = arr.size() - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (mid == 0 || arr[mid - 1] <= arr[mid] && mid == arr.size() - 1 || arr[mid + 1] <= arr[mid])
            return mid;
        else if (mid > 0 && arr[mid] <= arr[mid - 1])
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
//two pointers
bool findPair(vector<int> arr, int data)
{
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == data)
            return true;
        else if (sum > data)
            j--;
        else
            i++;
    }
    return false;
}
bool findTriplet(vector<int> arr, int data)
{
    int i = 0, temp = 1, j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j] + arr[temp];
        if (sum == data)
            return true;
        else if (sum > data)
            j--;
        else
            temp++;
        if (temp == j)
        {
            i++;
            temp = i + 1;
            j = arr.size() - 1;
        }
    }
    return false;
}
void merge(vector<int> arr1, vector<int> arr2, vector<int> &res)
{
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
            res.push_back(arr1[i++]);
        else
        {
            res.push_back(arr2[j++]);
        }
    }
    for (; i < arr1.size(); i++)
        res.push_back(arr1[i]);

    for (; j < arr2.size(); j++)
        res.push_back(arr2[j]);
}
float mergeandFind(vector<int> arr1, vector<int> arr2)
{
    vector<int> res;
    merge(arr1, arr2, res);
    return res.size() % 2 == 0 ? (float)((res[res.size() / 2 - 1]) + (res[res.size() / 2])) / 2 : res[res.size() / 2];
}
double getMedian(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size(), n2 = arr2.size(), begin1, end1, min1, min2, max1, max2;
    begin1 = 0;
    end1 = n1;
    while (begin1 <= end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;
        min2 = (i2 == n2) ? INT_MAX : arr2[i2];
        min1 = (i1 == n1) ? INT_MAX : arr1[i1];
        max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
        max2 = (i2 == 0) ? INT_MAX : arr2[i2 - 1];
        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return (double)(max(min1, min2) + min(max1, max2)) / 2;
            else
                return max(max1, max2);
        }
        else if (max1 > min2)
            end1 = i1 - 1;
        else
            begin1 = i1 + 1;
    }
    return -1;
}
int getMajority(vector<int> arr)
{
    vector<int> res(1000);
    for (int i = 0; i < arr.size(); i++)
    {
        res[arr[i]]++;
        if (res[arr[i]] > arr.size() / 2)
            return i;
    }
    return -1;
}

//mures voting algo (works in two phase)
int findMajority(vector<int> arr)
{
    int res = 0;
    int count = 1;
    //first phase find the elemnt who  can be majority
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    //second phase confirm the element is majority or not;
    count = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == arr[res])
            count++;

    return count > arr.size() / 2 ? count : -1;
}
int repeatingElements(vector<int> arr)
{
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (fast != slow);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }
    return slow;
}
int countOnes(vector<int> arr)
{
    int count = 0;
    int low, high;
    low = 0;
    high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == 1)
        {
            if (mid == 0 || arr[mid - 1] == 0)
                return arr.size() - mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return 0;
}
int mysqrt(int n)
{
    int low = 1, high = n, res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sqrt = mid * mid;
        if (sqrt == n)
            return mid;
        else if (sqrt > n)
            high = mid - 1;
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
int sortedRotated(vector<int> arr, int find)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == find)
            return mid;
        else if (arr[low] < arr[mid])
        {
            if (arr[low] <= find && arr[mid] >= find)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= find && arr[high >= find])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
// bool findPair(vector<int> arr, int sum)
// {
//     int i = 0, j = arr.size() - 1;
//     while (i < j)
//     {
//         if (arr[i] + arr[j] == sum)
//             return true;
//         else if (arr[i] + arr[j] < sum)
//             i++;
//         else
//             j--;
//     }
//     return false;
// }
bool findTriple(vector<int> arr, int sum)
{
    int i = 0, j = arr.size() - 1;
    int k = 1;
    while (i < j)
    {
        if (arr[i] + arr[j] + arr[k] == sum)
            return true;
        else if (arr[i] + arr[j] + arr[k] < sum)
        {
            k++;
            if (k == j)
            {
                i++;
                k = i + 1;
            }
        }
        else
            j--;
    }
    return false;
}

int coutPairs(vector<int> arr, int sum)
{
    int left = 0, right = arr.size() - 1;
    int count = 0;
    while (left < right)
    {
        if (arr[left] + arr[right] == sum)
            count++;
        else if (arr[left] + arr[right] > sum)
            right--;
        else
            left++;
    }
    return count;
}
//pythagoras chacha
bool pythagoreanTriplet(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        arr[i] *= arr[i];
    sort(arr.begin(), arr.end());
    int low, high, mid;
    for (int mid = arr.size() - 1; mid >= 2; mid--)
    {
        low = 0;
        high = mid - 1;
        while (low < high)
        {
            if (arr[low] + arr[high] == arr[mid])
                return true;
            else if (arr[low] + arr[high] < arr[mid])
                low++;
            else
                high--;
        }
    }
    return false;
}
// int majority(vector<int> arr)
// {
//     int elem = 0, count = 1;
//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (arr[i] == arr[elem])
//             count++;
//         else
//             count--;
//         if (count == 0)
//         {
//             count = 1;
//             elem = i;
//         }
//     }
//     return elem;
// }
int findSum(vector<int> arr, int a, int b)
{
    int sum = 0;
    for (int i = a; i < b; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int readPagesNaive(vector<int> arr, int n, int k)
{
    if (k == 1)
        return findSum(arr, 0, n);
    if (n == 1)
        return arr[0];
    int res = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(readPagesNaive(arr, i, k - 1), findSum(arr, i, n)));
    }
    return res;
}
void repeatingPair(vector<int> arr, int N)
{
    for (int i = 0; i < N + 2; i++)
    {
        if (arr[abs(arr[i])] < 0)
        {
            cout << abs(arr[i]) << " ";
        }
        else
        {
            arr[abs(arr[i])] *= -1;
        }
    }
    cout<<endl;
}
int allocateMinPage(vector<int> arr, int max_value, int total_sum, int k)
{
    int low, high, res = 0;
    low = max_value, high = total_sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = 0;
        int temp = k;

        //chekcing for a feasible solution
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                temp--;
                sum = arr[i];
            }
        }
        if (temp >= 1)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
int main()
{
    repeatingPair({1,2,1,3,4,3},4);
    cout << "result: " << allocateMinPage({250 ,74 ,159, 181, 23, 45, 129, 174}, 250, 1035, 6) << endl;
    // cout << majority({8, 3, 4, 8, 8}) << endl;
    // cout << "pythagorean chahu" << pythagoreanTriplet({1, 3, 4, 5, 6}) << endl;
    cout << binarySearch({1, 2, 2, 3, 3, 3, 3, 3, 4}, 3) << endl;
    cout << RbinarySearch({1, 2, 3, 4}, 0, 4, 4) << endl;
    cout << firstOccurenseInsortedArray({1, 1, 2, 2, 3, 3, 3, 3, 3, 4}, 1) << endl;
    cout << recursiveFirstOccurenceInSortedArray({1, 1, 2, 2, 3, 3, 3, 3, 3, 4}, 0, 9, 4) << endl;
    cout << recursiveLastOccInSortedArray({1, 1, 2, 2, 3, 3, 3, 3, 3, 4}, 0, 9, 4) << endl;
    cout << lastOccInSortedArray({1, 1, 2, 2, 3, 3, 3, 3, 3, 4}, 3) << endl;
    cout << countOcc({1, 1, 2, 2, 3, 3, 3, 3, 3, 4}, 0) << endl;
    cout << findfloorSqrt(16) << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 130, 140, 150, 160};
    cout << search(arr, 150) << endl;
    cout << searchCircularly({10, 20, 40, 60, 5, 8}, 5) << endl;
    cout << findPeak({10, 20, 15, 5, 23, 90, 67}) << endl;
    cout << findPair({3, 5, 9, 2, 8, 10, 11}, 0) << endl;
    cout << findTriplet({2, 3, 4, 8, 9, 20, 40}, 32) << endl;
    cout << mergeandFind({10, 20, 30, 40, 50}, {5, 15, 25, 35}) << endl;
    cout << getMedian({10, 20, 30, 40, 50}, {5, 15, 25, 35, 45}) << endl;
    cout << getMajority({8, 7, 6, 8, 6, 6, 6, 6}) << endl;
    cout << findMajority({8, 7, 6, 8, 6, 6, 6, 6}) << endl;
    cout << repeatingElements({1, 3, 2, 4, 3, 3}) << endl;
    cout << countOnes({0, 0, 0, 0}) << endl;
    cout << sortedRotated({10, 20, 25, 5, 7, 9}, 10) << endl;
    // cout<<mysqrt(10)<<endl;
    cout << findTriple({2, 3, 4, 8, 9, 20, 40}, 32) << endl;
}