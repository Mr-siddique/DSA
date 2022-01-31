#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int firstLargestElementIndex(int arr[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[index])
            index = i;
    }
    return index;
}
int secondLargetElementIndex(int arr[], int n)
{
    int largest = 0, res = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[largest] < arr[i])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (res == -1 || arr[i] > arr[res])
                res = i;
        }
    }
    return res;
}
void reverseArray(int arr[], int n)
{
    int swap;
    int len = floor(n / 2);
    for (int i = 0; i < len; i++)
    {
        swap = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = swap;
    }
}
int removeDuplicates(int arr[], int n)
{
    int *temp = new int[n];
    temp[0] = arr[0];
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != temp[res - 1])
        {
            temp[res] = arr[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++)
    {
        arr[i] = temp[i];
    }
    return res;
}
int duplicates(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
void moveZeroTotheend(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
}
void leftRotateArrayByOne(int arr[], int n)
{
    int swap = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[i - 1] = swap;
}
// void leftRotateArrayByD(int arr[],int n,int d){
// int *temp=new int[n];
// int j=0;
// for(int i=d;i<n;i++){
//     temp[j++]=arr[i];
// }
// for(int i=0;i<d;i++){
//     temp[j++]=arr[i];
// }
// }
void reversearr(int low, int high, int arr[])
{
    while (low < high)
    {
        swap(arr[low++], arr[high--]);
    }
}
void leftRotatebyD(int n, int d, int arr[])
{
    reversearr(0, d - 1, arr);
    reversearr(d, n - 1, arr);
    reversearr(0, n - 1, arr);
}
void leaders(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool count = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                count = false;
                break;
            }
        }
        if (count == true)
            cout << arr[i] << " ";
    }
}
void Onleader(int arr[], int n)
{
    int curr_leader = arr[n - 1];
    cout << curr_leader << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > curr_leader)
        {
            curr_leader = arr[i];
            cout << curr_leader << " ";
        }
    }
}
vector<int> rev(vector<int> v, int k)
{
    // cout<<*v.begin()+0<<" "<<*v.begin()+0+k-1;
    int n = v.size();
    for (int i = 0; i < n; i += k)
        if (i + k <= n)
            reverse(v.begin() + i, v.begin() + i + k);
    return v;
}
int maxDiffrence(int arr[], int n)
{
    int min_val = arr[0];
    int max_diff = arr[1] - arr[0];
    for (int i = 1; i < n; i++)
    {
        max_diff = max(arr[i] - min_val, max_diff);
        min_val = min(min_val, arr[i]);
    }
    return max_diff;
}
void frequenciesOfSortedArray(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp)
            temp = arr[i];
    }
    int *res_table = new int[temp + 1];
    fill(res_table, res_table + temp + 1, 0);
    for (int i = 0; i < n; i++)
    {
        res_table[arr[i]] += 1;
    }
    for (int i = 0; i <= temp; i++)
    {
        if (res_table[i] > 0)
            cout << res_table[i] << " ";
    }
}
void frequencies(int arr[], int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            count += 1;
        else
        {
            cout << count << " ";
            count = 1;
        }
    }
    cout << count << " ";
}
int stokBuyandSell(int arr[], int n)
{
    // 1,5,3,8,12
    // 1,3,5,8,12
    int min_value, max_value;
    min_value = arr[0];
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > min_value)
        {
            sum += arr[i] - min_value;
            min_value = arr[i];
        }
        else if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    return sum;
}
int betterStockBuyAndSell(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            res += arr[i] - arr[i - 1];
    }
    return res;
}
int whereToBuyANDsell(int arr[], int n)
{
    int buy = -1, sell = -1, profit = 0;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            if (flag == false)
            {
                flag = true;
                buy = i - 1;
            }
        }
        if (arr[i] < arr[i - 1] && buy != -1)
        {
            
                flag = false;
                sell = i - 1;
                profit += arr[sell] - arr[buy];
                buy = -1;
                cout << "(" << buy << " " << sell << ")";
            
        }
        if (buy != -1 && i == n - 1)
        {
            sell = i;
            profit += arr[sell] - arr[buy];
            cout << "(" << buy << " " << sell << ")";
        }
    }
    if(profit==0)
    cout<<"No Profit"<<endl;
    return profit;
}
int trapRainWater(int arr[], int n)
{
    int res = 0;
    int count = false;
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp)
        {
            temp = arr[i];
            count = true;
        }
        int sum = temp - arr[i];
        res += sum;
    }
    return count == true ? res : 0;
}
int getWater(int arr[], int n)
{
    int *leftMax = new int[n];
    int *rightMax = new int[n];
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        res += min(leftMax[i], rightMax[i]) - arr[i];
    }
    return res;
}
int maxConsecutiveOnes(int arr[], int n)
{
    int count = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 0;
        }
    }
    return res;
}

int maxSumSubArray(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            res = max(sum, res);
        }
    }
    return res;
}
int maxSubArraySum(int arr[], int n)
{
    int max_elem = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        max_elem = max(max_elem + arr[i], arr[i]);
        res = max(max_elem, res);
    }
    return res;
}
int maxAlternatingOddEvenElement(int arr[], int n)
{
    int count = 1;
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] % 2 == 0 && arr[i + 1] % 2 == 1 || arr[i] % 2 == 1 && arr[i + 1] % 2 == 0)
        {
            count++;
            res = max(res, count);
        }
        else
        {
            count = 1;
        }
    }
    return res;
}
int maxSumofcircularSubarray(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_max += arr[index];
            curr_sum = max(curr_sum, curr_max);
        }
        res = max(res, curr_sum);
    }
    return res;
}
int maxSumInCircularSubArray(int arr[], int n)
{
    int max_sum = maxSubArraySum(arr, n);
    if (max_sum < 0)
        return max_sum;
    int total_sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        total_sum += arr[i];
    }
    int min_sum = arr[0];
    int minSum = arr[0];
    for (int i = 1; i < n; i++)
    {
        min_sum = min(arr[i], min_sum + arr[i]);
        minSum = min(minSum, min_sum);
    }
    int tempTotal = total_sum - minSum;
    // cout<<max_sum<<" "<<tempTotal<<endl;
    return max(max_sum, tempTotal);
}
int findmajority(int arr[], int n)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            res = i;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }
    return (count >= (n / 2)) ? res : -1;
}
void minimumFlips(int arr[], int n)
{
    vector<int> initial_IndexOnes;
    vector<int> initial_IndexZeroes;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            int j = i + 1;
            while (arr[j] == arr[i] && j < n)
                j++;
            initial_IndexZeroes.push_back(i);
            i = j - 1;
        }
        else
        {
            int j = i + 1;
            while (arr[j] == arr[i] && j < n)
                j++;
            initial_IndexOnes.push_back(i);
            i = j - 1;
        }
    }
    // for(int i=0;i<initial_IndexZeroes.size();i++){
    //  cout<<initial_IndexZeroes[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<initial_IndexOnes.size();i++){
    //     cout<<initial_IndexOnes[i]<<" ";
    // }
    if (initial_IndexOnes.size() < initial_IndexZeroes.size())
    {
        for (int i = 0; i < initial_IndexOnes.size(); i++)
        {
            cout << initial_IndexOnes[i] << " to " << initial_IndexZeroes[i + 1] - 1 << endl;
        }
    }
    else if (initial_IndexZeroes.size() < initial_IndexOnes.size())
    {
        for (int i = 0; i < initial_IndexZeroes.size(); i++)
        {
            cout << initial_IndexZeroes[i] << " to " << initial_IndexOnes[i + 1] - 1 << endl;
        }
    }
    else
    {
        for (int i = 0; i < initial_IndexZeroes.size(); i++)
        {
            cout << initial_IndexZeroes[i] << " to " << initial_IndexZeroes[i] << " OR " << initial_IndexOnes[i] << " to " << initial_IndexOnes[i] << endl;
        }
    }
}
void flipConsecutiveBits(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
            {
                cout << "flip from " << i << " to ";
            }
            else
            {
                cout << i - 1 << endl;
            }
        }
    }
    if (arr[i - 1] != arr[0])
    {
        cout << i - 1 << endl;
    }
    "bbaaaaabb"
}

//window sliding tecnique
int maxSumOfKconsecutiveElements(int arr[], int n, int k)
{
    int res;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    res = sum;
    for (int i = k; i < n; i++)
    {
        sum += (arr[i] - arr[i - k]);
        res = max(res, sum);
    }
    return res;
}
bool issumArrayofGivenSum(int arr[], int n, int sum, int k)
{
    int res, temp = 0;
    for (int i = 0; i < k; i++)
    {
        temp += arr[i];
    }
    if (temp == sum)
        return true;
    for (int i = k; i < n; i++)
    {
        temp += (arr[i] - arr[i - k]);
        if (temp == sum)
            return true;
    }
    return false;
}
bool isSubArrayOfSum(int arr[], int n, int sum)
{
    int temp = 0;
    int index = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (temp == sum)
            return true;
        if (temp < sum)
            temp += arr[i];
        while (temp > sum && index < i - 1)
            temp -= arr[index++];
    }
    return temp == sum;
}
void printN_bonachhiNumbers(int n, int m)
{
    vector<int> res(m, 0);
    res[n - 1] = 1;
    res[n] = 1;
    for (int i = n + 1; i < m; i++)
    {
        res[i] = 2 * res[i - 1] - res[i - n - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cout << res[i] << " ";
    }
}

//prefix sum technique
vector<int> pre_computation(int arr[], int n)
{
    vector<int> res(n);
    res[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] + arr[i];
    }
    return res;
}
int getSum(int arr[], int n, int query1, int query2)
{
    vector<int> sums = pre_computation(arr, n);
    if (query1 == 0)
        return sums[query2];
    else
        return sums[query2] - sums[query1 - 1];
}
//cheking on a particular index
bool hasEquilibriumPoint(int arr[], int n, int equilibrium_index)
{
    vector<int> sums = pre_computation(arr, n);
    if (equilibrium_index == 0 && sums[n - 1] - sums[n - 2] == 0)
        return true;
    if (sums[equilibrium_index - 1] == (sums[n - 1] - sums[n - 2]))
        return true;
    return false;
}
//cheking on any index
bool isEqPoint(int arr[], int n)
{
    int sum = arr[0], left_sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (left_sum == sum - arr[i])
            return true;
        left_sum += arr[i];
        sum -= arr[i];
    }
    return false;
}
int maxOcc(int L[], int R[], int n)
{
    int arr[1000];

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < n; i++)
    {
        arr[L[i]]++;

        arr[R[i] + 1]--;
    }

    int maxm = arr[0], res = 0;

    for (int i = 1; i < 1000; i++)
    {
        arr[i] += arr[i - 1];

        if (maxm < arr[i])
        {
            maxm = arr[i];

            res = i;
        }
    }

    return res;
}
main()
{
    int arr[] = {10, 10, 20, 30, 30, 30};
    // cout<<firstLargestElementIndex(arr,5)<<endl;
    // cout<<secondLargetElementIndex(arr,5)<<endl;
    // reverseArray(arr,5);
    // for(int i=0;i<5;i++){
    // cout<<arr[i]<<" ";
    // }
    // int res = removeDuplicates(arr, 6);
    // for (int i = 0; i < res; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // leaders(arr,6);
    // vector<int>temp=rev({35 ,56 ,48 ,21 ,87},5);
    // // cout<<temp.size();
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i]<<" ";
    // }
    // frequencies(arr, 6);
    cout << endl;
    // frequenciesOfSortedArray(arr, 6);
    // int temp[]={2,3,-8,7,-1,2,3};
    int temp[] = {3, 4, 8, -9, 20, 6};
    cout << getSum(temp, 7, 2, 6) << endl;
    cout << hasEquilibriumPoint(temp, 6, 4) << endl;
    // cout<<maxSumOfKconsecutiveElements(temp,6,3)<<endl;
    // cout<<issumArrayofGivenSum(temp,6,46,3)<<endl;
    // cout<<isSubArrayOfSum(temp,6,6)<<endl;
    // printN_bonachhiNumbers(4,10);
    // minimumFlips(temp, 10);
    // flipConsecutiveBits(temp, 10);
    // cout<<stokBuyandSell(temp,6);
    //    cout<<trapRainWater(temp,5);
    // cout<<getWater(temp,5);
    // cout<<maxConsecutiveOnes(temp,7)<<endl;
    // cout<<maxSumSubArray(temp,7)<<endl;
    // cout<<maxSubArraySum(temp,7)<<endl;
    // cout << maxAlternatingOddEvenElement(temp, 4) << endl;
    // cout << maxSumInCircularSubArray(temp, 2) << endl;
}