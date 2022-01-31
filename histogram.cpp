#include <bits/stdc++.h>
using namespace std;
int rectangularAreaNaive(vector<int> arr)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
                temp += arr[i];
            else
                break;
        }
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] >= arr[i])
                temp += arr[i];
            else
                break;
        }
        res = max(res, temp);
    }
    return res;
}
vector<int> previousSmaller(vector<int> arr)
{
    stack<int> stk;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
            stk.pop();
        res.push_back(stk.empty() ? -1 : stk.top());
        stk.push(i);
    }
    return res;
}
vector<int> nextSmaller(vector<int> arr)
{
    stack<int> stk;
    vector<int> res(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
            stk.pop();
        res[i] = stk.empty() ? arr.size() : stk.top();
        stk.push(i);
    }
    return res;
}
int rectangularAreaBetter(vector<int> arr)
{
    int res = 0;
    vector<int> ps = previousSmaller(arr);
    vector<int> ns = nextSmaller(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        curr += (i - ps[i] - 1) * arr[i];
        curr += (ns[i] - i - 1) * arr[i];
        res = max(res, curr);
    }
    return res;
}
int rectangularAreaEfficient(vector<int> arr)
{
    int res = 0;
    stack<int> stk;
    for (int i = 0; i < arr.size(); i++)
    {
        while (stk.empty() == false && arr[stk.top()] >= arr[i])
        {
            int tp = stk.top();
            stk.pop();
            int curr = arr[tp] * (stk.empty() ? i : i - stk.top() - 1);
            res = max(res, curr);
        }
        stk.push(i);
    }
    while (stk.empty() == false)
    {
        int tp = stk.top();
        stk.pop();
        int curr = arr[tp] * (stk.empty() ? arr.size() : arr.size() - stk.top() - 1);
        res = max(res, curr);
    }
    return res;
}
int largestRectanglewithAllOne(vector<vector<int>> arr)
{
    int res = 0;
    res = rectangularAreaEfficient(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++){
            if(arr[i][j]==1)
            arr[i][j] += arr[i - 1][j];
        res = max(res, rectangularAreaEfficient(arr[i]));
        }
    }
    return res;
}
main()
{
    vector<int> v = {6, 2, 5, 4, 1, 5, 6};
    cout << rectangularAreaNaive(v) << endl;
    cout << rectangularAreaBetter(v) << endl;
    cout<<rectangularAreaEfficient(v)<<endl;
    cout << largestRectanglewithAllOne({{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}}) << endl;
}