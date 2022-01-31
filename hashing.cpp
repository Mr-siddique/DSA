// #include<iostream>
#include <bits/stdc++.h>
using namespace std;
class myHash
{
    int bucket;
    list<int> *table;
    myHash(int b)
    {
        bucket = b;
        table = new list<int>[b];
    }
    void insert(int num)
    {
        table[bucket % num].push_back(num);
    }
    void del(int num)
    {
        table[bucket % num].remove(num);
    }
    bool search(int key)
    {
        int i = key % bucket;
        for (auto x : table[i])
            if (x == key)
                return true;
        return false;
    }
};
class my_hash
{
    int capacity, size;
    int *arr;

public:
    my_hash(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[c];
        for (int i = 0; i < c; i++)
            arr[i] = -1;
    }
    int hash(int num)
    {
        return num % capacity;
    }
    bool insert(int num)
    {
        if (size == capacity)
            return false;
        int index = hash(num);
        int i = index;
        while (arr[index] != -1 && arr[index] != -2 && arr[index] != num)
        {
            index = (index + 1) % capacity;
        }
        if (arr[index] == num)
            return false;
        else
        {
            arr[index] = num;
            size++;
            return true;
        }
    }
    bool del(int num)
    {
        int index = hash(num);
        int i = index;
        while (arr[index] != -1)
        {
            if (arr[index] == num)
            {
                arr[index] = -2;
                return true;
            }
            index = (index + 1) % capacity;
            if (index == i)
                return false;
        }
        return false;
    }
    bool search(int num)
    {
        int index = hash(num);
        int i = index;
        while (arr[i] != -1)
        {
            if (arr[index] == num)
                return true;
            index = (index + 1) % capacity;
            if (index == i)
                return false;
        }
        return false;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
            cout << arr[i] << " ";
    }
};
//unorderd_map<T>&&unordered_set<T>are the containers which depends on hashing in c++
int countDistinctElements(vector<int> arr)
{
    unordered_set<int> s(arr.begin(), arr.end());
    return s.size();
}
void printFrequencies(vector<int> arr)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]]++;
    for (auto i : mp)
        cout << i.first << " : " << i.second << endl;
}
void intersection(vector<int> arr, vector<int> brr)
{
    unordered_set<int> s(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < brr.size(); i++)
    {
        if (s.find(brr[i]) != s.end())
        {
            count++;
            s.erase(brr[i]);
        }
    }
    cout << count << endl;
}
void unionOfTwoArrays(vector<int> arr, vector<int> brr)
{
    unordered_set<int> s(arr.begin(), arr.end());
    for (int i = 0; i < brr.size(); i++)
        s.insert(brr[i]);
    cout << s.size() << endl;
}
bool isPair(vector<int> arr, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(sum - arr[i]) != s.end())
            return true;
        s.insert(sum - arr[i]);
    }
    return false;
}
//naive (subarray with sum=0)
bool zeroSum(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}
bool sumZero(vector<int> arr)
{
    int prefix_sum = 0;
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        if (s.find(prefix_sum) != s.end() || prefix_sum == 0)
            return true;
        s.insert(prefix_sum);
    }
    return false;
}
bool requiredSum(vector<int> arr, int num)
{
    int prefix_sum = 0;
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        if (s.find(prefix_sum - num) != s.end() || prefix_sum == num)
            return true;
        s.insert(prefix_sum);
    }
    return false;
}
int longestsubArraySum(vector<int> arr, int sum)
{
    int prefix_sum = 0;
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)
            res = i + 1;
        if (mp.find(prefix_sum) == mp.end())
            ;
        mp.insert({prefix_sum, i});
        if (mp.find(prefix_sum - sum) != mp.end())
            res = max(res, i - mp[prefix_sum - sum]);
    }
    return res;
}
int longestequalBinarySubArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 0)
            arr[i] = -1;
    return longestsubArraySum(arr, 0);
}
int longestCommonSubarrayWithEqualSum(vector<int> arr, vector<int> brr)
{
    vector<int> temp(arr.size());
    for (int i = 0; i < arr.size(); i++)
        temp[i] = arr[i] - brr[i];
    return longestsubArraySum(temp, 0);
}
int longestConsecutiveSubsequence(vector<int> arr)
{
    int res = 0;
    unordered_set<int> s(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {

        if (s.find(arr[i] - 1) == s.end())
        {
            int count = 1;
            while (s.find(arr[i] + count) != s.end())
                count++;
            res = max(res, count);
        }
    }
    return res;
}
//useing unordered set
void countDistinctElementInWindow(vector<int> arr, int k)
{
    for (int i = 0; i <= arr.size() - k; i++)
    {
        unordered_set<int> s(arr.begin() + i, arr.begin() + i + k);
        cout << s.size() << " ";
    }
}
void DistinctElementInWindow(vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;
    cout << mp.size() << " ";
    for (int i = k; i < arr.size(); i++)
    {
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
            mp.erase(arr[i - k]);
        mp[arr[i]]++;
        cout << mp.size() << " ";
    }
}

unordered_set<int> occurencesCount(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > n / k)
            s.insert(arr[i]);
    }
    return s;
}

//mooresVoting algo (no of elements in output <=k-1)
void occurenceCount(vector<int> arr, int k)
{
    unordered_map<int, int> m;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
            m[arr[i]]++;
        else if (m.size() < k - 1)
            m[arr[i]] = 1;
        else
        {
            for (auto it = m.begin(); it != m.end(); it++)
            {
                it->second--;
                if (it->second == 0)
                {
                    int key = it->first;
                     m.erase(key);
                      break;
                }
            }
        }
    }
    for (auto x : m)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x.first)
                count++;
        }
        if (count > n / k)
            cout << x.first << " ";
    }
}
main()
{
    // vector<mylist>chain(10);
    // insert(chain,20);
    // insert(chain,30);
    my_hash obj(5);
    cout << obj.insert(10) << endl;
    cout << obj.insert(15) << endl;
    cout << obj.insert(3) << endl;
    cout << obj.insert(11) << endl;
    cout << obj.search(3) << " ";
    cout << obj.del(11) << endl;
    cout << obj.search(11) << endl;
    cout << endl;
    obj.print();
    cout << endl
         << countDistinctElements({15, 12, 13, 12, 13, 13, 18}) << endl;
    printFrequencies({10, 12, 10, 15, 10, 20, 12, 12});
    intersection({10, 10, 10}, {10, 10, 10});
    unionOfTwoArrays({15, 20, 5, 15}, {15, 15, 15, 20, 10});
    cout << isPair({11, 5, 6}, 10) << endl;
    cout << zeroSum({1, 4, 13, -3, -10, 5}) << endl;
    cout << sumZero({1, 4, 13, -3, -10, 5}) << endl;
    cout << requiredSum({5, 2, 8, 10, -5, -8, 6}, 3) << endl;
    cout << longestsubArraySum({8, 3, 1, 5, -6, 6, 2, 2}, 4) << endl;
    cout << longestequalBinarySubArray({1, 0, 1, 0, 0, 1}) << endl;
    cout << longestCommonSubarrayWithEqualSum({0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 1}) << endl;
    cout << longestConsecutiveSubsequence({1, 9, 3, 4, 2, 20}) << endl;
    countDistinctElementInWindow({10, 20, 30, 40}, 3);
    cout << endl;
    DistinctElementInWindow({10, 20, 30, 40}, 3);
    cout << endl;
    unordered_set<int> s = occurencesCount({30, 10, 20, 20, 10, 20, 30, 30}, 4);
    for (auto i : s)
        cout << i << " ";
    cout << endl;
    occurenceCount({30, 10, 20, 20, 20, 10, 40, 30,30}, 4);
    cout<<endl;
}