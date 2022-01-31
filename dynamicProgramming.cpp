#include <bits/stdc++.h>
using namespace std;

//meoization
int fibonacci(vector<int> memo, int n)
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 0 || n == 1)
            res = n;
        else
            res = fibonacci(memo, n - 1) + fibonacci(memo, n - 2);
        memo[n] = res;
    }
    return memo[n];
}
//tabulaation(bottom up)
long long fibonacci(int n)
{
    vector<long long> temp(n + 1);
    temp[0] = 0, temp[1] = 1;
    for (int i = 2; i <= n; i++)
        temp[i] = temp[i - 1] + temp[i - 2];
    return temp[n];
}
void solve(string str, string s, int index, unordered_set<string> &se)
{
    if (index == str.size())
    {
        se.insert(s);
        return;
    }
    solve(str, s, index + 1, se);
    s += str[index];
    solve(str, s, index + 1, se);
}
void subSequence(string str1, string str2)
{
    unordered_set<string> a, b;
    solve(str1, "", 0, a);
    solve(str2, "", 0, b);
    int res = 0;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        string temp = (*i);
        if (b.find(temp) != b.end())
        {
            if ((*(b.find(temp))).length() > res)
                res = (*(b.find(temp))).length();
        }
    }
    cout << res << endl;
}
//memoization
int lcs(string a, string b, int m, int n, vector<vector<int>> &table)
{
    if (table[m][n] != -1)
        return table[m][n];
    if (m == 0 || n == 0)
        table[m][n] = 0;
    else
    {
        if (a[m - 1] == b[n - 1])
            table[m][n] = 1 + lcs(a, b, m - 1, n - 1, table);
        else
            table[m][n] = max(lcs(a, b, m - 1, n, table), lcs(a, b, m, n - 1, table));
    }
    return table[m][n];
}
//tabulation
int lcs_tabulation(string a, string b, int m, int n)
{
    vector<vector<int>> table(m + 1, vector<int>(n + 1, -1)); //cout<<a<<" "<<b<<endl;
    for (int i = 0; i <= m; i++)
        table[i][0] = 0;
    for (int i = 0; i <= n; i++)
        table[0][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    return table[m][n];
}
int coinChange(vector<int> coin, int sum, int n)
{
    if (sum == 0)
        return 1;
    if (n = 0)
        return 0;
    int res = coinChange(coin, sum, n - 1);
    if (coin[n - 1] <= sum)
        res = res + coinChange(coin, sum - coin[n - 1], n);
    return res;
}

//dp(tabulation based solution)
int coinChange(vector<int> coin, int sum)
{
    int n = coin.size();
    int dp[sum + 1][n + 1];
    fill(dp[0], dp[0] + n + 1, 1);
    for (int i = 1; i <= sum; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coin[j - 1] <= i)
                dp[i][j] += dp[i - coin[j - 1]][j];
        }
    }
    for (int i = 0; i <= sum; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[sum][n];
}
// s1 to s2(insert,delete,replace)
int editDistanceRecursive(string str_a, string str_b, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str_a[m - 1] == str_b[n - 1])
        return editDistanceRecursive(str_a, str_b, m - 1, n - 1);
    else
        return 1 + min({editDistanceRecursive(str_a, str_b, m, n - 1), editDistanceRecursive(str_a, str_b, m - 1, n), editDistanceRecursive(str_a, str_b, m - 1, n - 1)});
}
int editDistanceDP(string str_a, string str_b, int m, int n, vector<vector<int>> &memo)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (memo[m][n] != -1)
        return memo[m][n];
    if (str_a[m - 1] == str_b[n - 1])
        return memo[m][n] = editDistanceDP(str_a, str_b, m - 1, n - 1, memo);
    else
        return memo[m][n] = 1 + min({editDistanceDP(str_a, str_b, m - 1, n - 1, memo), editDistanceDP(str_a, str_b, m - 1, n, memo), editDistanceDP(str_a, str_b, m, n - 1, memo)});
}
int editDistanceTabulation(string str_a, string str_b, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < dp[0].size(); i++)
        dp[0][i] = i;
    for (int i = 1; i < dp.size(); i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str_a[i - 1] == str_b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }
    return dp[m][n];
}
int longestIncreasingSubsequence(vector<int> arr)
{
    // 2 3 4 1 0
    int n = arr.size();
    int lis[n] = {0};
    lis[0] = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
        res = max(lis[i], res);
    }
    return res;
}
int lis(vector<int> arr)
{
    int n = arr.size();
    vector<int> tail;
    tail.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail.back())
            tail.push_back(arr[i]);
        else
        {
            int index = lower_bound(tail.begin(), tail.end(), arr[i]) - tail.begin();
            tail[index] = arr[i];
        }
    }

    return tail.size();
}
int maximumSumIncreasingSubsequence(vector<int> arr)
{
    int n = arr.size();
    int msis[n];
    msis[0] = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        msis[i] = arr[i];
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                msis[i] = max(msis[j] + arr[i], msis[i]);
        res = max(res, msis[i]);
    }
    return res;
}
int longestBitonicSubsequence(vector<int> arr)
{
    int n = arr.size();
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                lis[i] = max(lis[j] + 1, lis[i]);
        }
    }
    // {1, 11, 2, 10, 4, 5, 2, 1}
    int lds[n];
    lds[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                lds[i] = max(lds[j] + 1, lds[i]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << lis[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << lds[i] << " ";
    int res = lds[0] + lis[0] - 1;
    for (int i = 1; i < n; i++)
        res = max(res, lds[i] + lis[i] - 1);
    return res;
}
int ceilIndex(vector<int> arr, int l, int r, int x)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
        return mid;

    if (x < arr[mid])
        return ceilIndex(arr, l, mid - 1, x);

    return ceilIndex(arr, mid + 1, r, x);
}

void revereseArr(vector<int> &arr, int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
        swap(arr[i++], arr[j--]);
}
int longest_bitonic_subsequence(vector<int> arr)
{
    cout << "****************************************************************************" << endl;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    if (n == 0)
        return 0;

    // Aux array storing the input array
    // in same order to calculate LIS:
    vector<int> increasing(n);
    vector<int> tail1(n); // To store lengths of IS

    // Aux array storing the input array
    // in reverse order to calculate LIS:
    // This will calculate Longest Decreasing
    // Subsequence which is required for
    // Longest Bitonic Subsequence
    vector<int> decreasing(n);
    vector<int> tail2(n); // To store lengths of DS

    // initializing first index same as
    // original array:
    increasing[0] = arr[0];

    // index in initialized as 1 from where
    // the remaining computations will be done
    int in = 1;

    // tail1 stores Longest Increasing subsequence
    // length values till index in
    tail1[0] = 0;

    // remaining computations to get the
    // LIS length for increasing
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < increasing[0])
        {
            increasing[0] = arr[i];
            tail1[i] = 0;
        }
        else if (arr[i] > increasing[in - 1])
        {
            increasing[in++] = arr[i];
            tail1[i] = in - 1;
        }
        else
        {
            increasing[ceilIndex(increasing, -1, in - 1, arr[i])] = arr[i];
            tail1[i] = ceilIndex(increasing, -1, in - 1, arr[i]);
        }
    }

    // reiitializing the index to 1
    in = 1;

    // reversing the array to get the Longest
    // Decreasing Subsequence Length:
    revereseArr(arr, n);
    decreasing[0] = arr[0];
    tail2[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < decreasing[0])
        {
            decreasing[0] = arr[i];
            tail2[i] = 0;
        }
        else if (arr[i] > decreasing[in - 1])
        {
            decreasing[in++] = arr[i];
            tail2[i] = in - 1;
        }
        else
        {
            decreasing[ceilIndex(decreasing, -1,
                                 in - 1, arr[i])] = arr[i];
            tail2[i] = ceilIndex(decreasing, -1,
                                 in - 1, arr[i]);
        }
    }

    revereseArr(arr, n);
    revereseArr(tail2, n);

    // Longest Bitonic Subsequence length is
    // maximum of tail1[i] + tail2[i] + 1:
    cout << "tail1"
         << " "
         << "increasing"
         << " : "
         << "tail2"
         << " "
         << "decreasing" << endl;
    for (int i = 0; i < n; i++)
        cout << tail1[i] << " " << increasing[i] << " : " << tail2[i] << " " << decreasing[i] << endl;
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ans < (tail1[i] + tail2[i] + 1))
            ans = (tail1[i] + tail2[i] + 1);

    return ans;
}
// MODIFICATION REQUIRED IN THIS CODE
// int maximum_sum_increasing_subsequence(vector<int>arr){
//     int n=arr.size();
//     vector<int>temp;
//     temp.push_back(arr[0]);
//     int res=arr[0];
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>temp.back())
//         {
//             temp.push_back(arr[i]);
//             res+=arr[i];
//         }else{
//               int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
//             temp[index] = arr[i];
//         }
//     }
//     return res;
// }
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}
int buildBridges(vector<pair<int, int>> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        temp[i] = arr[i].second;
    return lis(temp);
}
int longestChainOfPairs(vector<pair<int, int>> arr)
{
    int n = arr.size();
    vector<int> lis(n);
    int res = 1;
    lis[0] = 1;
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j].second < arr[i].first)
                lis[i] = max(lis[i], lis[j] + 1);
        }
        res = max(res, lis[i]);
    }
    return res;
}
// {5,24}{15,28},{27,40},{29,60},{50,90}
bool my_comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

//greedy solution
int longest_pair_chain(vector<pair<int, int>> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), my_comp);
    int index = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[index].second < arr[i].first)
        {
            count++;
            index = i;
        }
    }
    return count;
}
int maximumCuts(int n, int a, int b, int c)
{
    // if(dp)
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max({maximumCuts(n - a, a, b, c), maximumCuts(n - b, a, b, c), maximumCuts(n - c, a, b, c)});
    if (res == -1)
        return -1;
    else
        return res + 1;
}
// 5 1 2 3
int maximum_cuts(int n, int a, int b, int c)
{
    vector<int> arr(n + 1, -1);
    arr[0] = 0;
    // [0,-1,-1,-1,-1,-1]
    for (int i = 1; i <= n; i++)
    {
        if (i - a >= 0)
            arr[i] = max(arr[i], arr[i - a]);
        if (i - b >= 0)
            arr[i] = max(arr[i], arr[i - b]);
        if (i - c >= 0)
            arr[i] = max(arr[i], arr[i - c]);
        if (arr[i] != -1)
            arr[i]++;
    }
    return arr[n];
}
//recursion with backTracking
int solve(vector<int> coins, int index, int n, int res)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    for (int i = index; i < coins.size(); i++)
    {
        n -= coins[i];
        int count = solve(coins, i, n, res);
        if (count != -1)
            res = min(res, count + 1);
        n += coins[i];
    }
    if (res == INT_MAX)
        return -1;
    return res;
}
//simple recursion
int solve(vector<int> coins, int n)
{
    if (n == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= n)
        {
            int temp = solve(coins, n - coins[i]);
            if (temp != INT_MAX)
                res = min(res, temp + 1);
        }
    }
    return res;
}
int minimumCoins(vector<int> coins, int n)
{
    int res = INT_MAX;
    cout << solve(coins, n) << endl;
    return solve(coins, 0, n, res);
}
//dp solution
int minimum_coins(vector<int> coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i - coins[j]], dp[i]);
        }
        if (dp[i] != INT_MAX)
            dp[i]++;
    }
    return dp[amount];
}
//minimum jumps to reach end
int solveJumps(vector<int> steps, int index)
{
    if (index >= steps.size() - 1)
        return 0;
    int res = INT_MAX;
    for (int i = index + 1; i <= index + steps[index]; i++)
    {
        int sub_res = solve(steps, i);
        if (sub_res != INT_MAX)
            res = min(res, sub_res + 1);
    }
    return res;
}
int solve_jumps(vector<int> steps, int n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i <= n - 2; i++)
    {
        if (i + steps[i] >= n - 1)
        {
            int sub_res = solve_jumps(steps, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}
int minimumJumps(vector<int> steps)
{
    cout << solve_jumps(steps, steps.size()) << endl;
    return solveJumps(steps, 0);
}
int minimum_jumps(vector<int> steps)
{
    int n = steps.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j + steps[i] >= i)
            {
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp.back();
}

//0/1knapsack
int knapSack(vector<int> value, vector<int> weights, int weight, int n)
{
    if (n == 0 || weight == 0)
        return 0;
    int a = 0;
    if (weight >= weights[n - 1])
        a = knapSack(value, weights, weight - weights[n - 1], n - 1) + value[n - 1];
    return max(a, knapSack(value, weights, weight, n - 1));
}
//dp approch
int knapSack(vector<int> value, vector<int> weights, int weight)
{
    int n = value.size();
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= weight; j++)
        {
            if (j < weights[i - 1])
                dp[i][j] = dp[i - 1][j]; //max(dp[i][j-1],dp[i-1][j]);
            else
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
        }
    }
    return dp[n][weight];
}
//maximum value that we can get with i items and knapsack capcity j
//  20 5 4 6
// 35
int recursiveSolution(vector<int> arr, int i, int j, int sum)
{
    if (i + 1 == j)
        return max(arr[i], arr[j]);
    return max(sum - recursiveSolution(arr, i + 1, j, sum - arr[i]), sum - recursiveSolution(arr, i, j - 1, sum - arr[j]));
}
int optimalStrategyRecursive(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return recursiveSolution(arr, 0, arr.size() - 1, sum);
}
int recursiveSolution(vector<int> arr, int i, int j)
{
    if (i + 1 == j)
        return max(arr[i], arr[j]);
    return max(arr[i] + min(recursiveSolution(arr, i + 2, j), recursiveSolution(arr, i + 1, j - 1)), arr[j] + min(recursiveSolution(arr, i + 1, j - 1), recursiveSolution(arr, i, j - 2)));
}
int optimal_strategy_recursive(vector<int> arr)
{
    return recursiveSolution(arr, 0, arr.size() - 1);
}
int optimalStrategy(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    for (int gap = 3; gap < n; gap += 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n - 1];
}
int eggDropping(int f, int e)
{
    if (e == 1)
        return f;
    else if (f == 1)
        return 1;
    else if (f == 0)
        return 0;
    int res = f;
    for (int x = 1; x <= f; x++)
        res = min(max(eggDropping(x - 1, e - 1), eggDropping(f - x, e)), res);
    return res + 1;
}
int egg_dropping(int f, int e)
{
    vector<vector<int>> dp(f + 1, vector<int>(e + 1));
    fill(dp[1].begin(), dp[1].end(), 1);
    dp[1][0] = 0;
    for (int i = 2; i <= f; i++)
        dp[i][1] = i;
    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++)
                dp[i][j] = min(dp[i][j], max(dp[x - 1][j - 1], dp[i - x][j]) + 1);
        }
    }
    for (int i = 0; i <= f; i++)
    {
        for (int j = 0; j <= e; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[f][e];
}

//both the solution gives optimal answer ans can also be done using catalan numbers (1/n+1*2nCn)
int countBst(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] += dp[i - j] * dp[j - 1];
    }
    return dp[n];
}
int count_bst(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - j - 1];
    }
    return dp[n];
}
int solveSum(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);
    return max(arr[n - 1] + solveSum(arr, n - 2), solveSum(arr, n - 1));
}
int maximumSum(vector<int> arr)
{
    return solveSum(arr, arr.size());
}
int maximum_Sum(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n + 1);
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(arr[i - 1] + dp[i - 2], arr[i - 1]);
    }
    return dp[n];
}
int maximum_sum(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    int last, second_last;
    second_last = arr[0];
    last = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int temp = max(second_last + arr[i], last);
        second_last = last;
        last = temp;
    }
    return last;
}
//using backtraking
int subsetSum(vector<int> arr, int sum, int n)
{
    if (sum == 0)
        return 1;
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (sum >= arr[i])
        {
            sum -= arr[i];
            res += subsetSum(arr, sum, i);
            sum += arr[i];
        }
    }
    return res;
}
//using simple recursion
int subset_sum(vector<int> arr, int sum, int n)
{
    if (n == 0)
        return sum == 0 ? 1 : 0;
    return subset_sum(arr, sum - arr[n - 1], n - 1) + subset_sum(arr, sum, n - 1);
}
int subsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int matrixMultiplication(vector<int> arr, int i, int j)
{
    if (i + 1 == j)
        return 0;
    int res = INT_MAX;
    if (i + 2 == j)
        return arr[i] * arr[i + 1] * arr[j];
    for (int k = i + 1; k < j; k++)
        res = min(res, arr[i] * arr[k] * arr[j] + matrixMultiplication(arr, i, k) + matrixMultiplication(arr, k, j));
    return res;
}
int matrixChain(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = 0;
    }
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[0].back();
}
bool isPalindrome(string str, int i, int j)
{
    if (i == j)
        return true;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}
// geek  0  3
int stringPartitioning(string str, int i, int j)
{
    if (isPalindrome(str, i, j))
        return 0;
    int res = INT_MAX;
    for (int k = i; k < j; k++)
        res = min(1 + stringPartitioning(str, i, k) + stringPartitioning(str, k + 1, j), res);
    return res;
}
int stringPartitioning(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if (isPalindrome(str, i, j))
                dp[i][j] = 0;
            {
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[0].back();
}
int sum(vector<int> pages, int i, int j)
{
    int res = 0;
    for (int k = i; k <= j; k++)
        res += pages[k];
    return res;
}
// 10 20 30 40
// 2
int allocateMinimumPages(vector<int> pages, int i, int j, int students)
{
    if (students == 1)
        return sum(pages, i, j);
    if (j == 0)
        return pages[0];
    if (j < students)
        return -1;
    int res = INT_MAX;
    for (int k = i; k < j; k++)
        res = min(res, max(allocateMinimumPages(pages, i, k, students - 1), allocateMinimumPages(pages, k + 1, j, students - 1)));
    return res;
}
//another recursive implementation
int allocatePages(vector<int> pages, int n, int students)
{
    if (students == 1)
        return sum(pages, 0, n - 1);
    if (n == 1)
        return pages[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
        res = min(res, max(allocatePages(pages, i, students - 1), sum(pages, i, n - 1)));
    return res;
}
int allocatePages(vector<int> pages, int students)
{
    int n = pages.size();
    int k = students;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        dp[1][i] += dp[1][i - 1] + pages[i - 1];
    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
                dp[i][j] = pages[0];
            else
            {
                int res = INT_MAX;
                for(int k=1;k<j;k++)
                res=min(res,max(dp[i-1][k],sum(pages,k,j-1)));
                dp[i][j]=res;
            }
        }
    }
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[k].back();
}
main()
{
    int n = 15;
    vector<int> fib(n + 1, -1);
    cout << fibonacci(fib, n) << endl;
    cout << fibonacci(n) << endl;
    subSequence("XYZ", "ABC");
    string a = "axyz";
    string b = "baz";
    vector<vector<int>> table(a.length() + 1, vector<int>(b.length() + 1, -1));
    cout << lcs(a, b, a.length(), b.length(), table) << endl;
    cout << lcs_tabulation(a, b, a.length(), b.length()) << endl;
    //    cout<< coinChange({2,5,3,6},10,4)<<endl;
    cout << coinChange({1, 2, 3}, 4) << endl;
    cout << editDistanceRecursive("saturday", "sunday", 8, 6) << endl;
    string str_a = "saturday";
    string str_b = "sunday";
    int m = str_a.size();
    n = str_b.size();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    cout << editDistanceDP(str_a, str_b, m, n, memo) << endl;
    for (int i = 0; i < memo.size(); i++)
    {
        for (int j = 0; j < memo[i].size(); j++)
            cout << memo[i][j] << " ";
        cout << endl;
    }
    cout << editDistanceTabulation(str_a, str_b, m, n) << endl;
    cout << longestIncreasingSubsequence({3, 4, 2, 8, 10, 5, 1}) << endl;
    cout << lis({3, 4, 2, 8, 10, 5, 1}) << endl;
    cout << maximumSumIncreasingSubsequence({3, 20, 4, 6, 7, 30}) << endl;
    // cout<<maximum_sum_increasing_subsequence({3,20,4,6,7,30})<<endl;
    cout << longestBitonicSubsequence({1, 11, 2, 10, 4, 5, 2, 1}) << endl;
    cout << longest_bitonic_subsequence({1, 11, 2, 10, 4, 5, 2, 1}) << endl;
    cout << buildBridges({{6, 2}, {4, 3}, {2, 6}, {1, 5}, {1, 3}}) << endl;
    cout << longestChainOfPairs({{5, 24}, {29, 60}, {15, 28}, {27, 40}, {50, 90}}) << endl;
    cout << longest_pair_chain({{5, 24}, {29, 60}, {15, 28}, {27, 40}, {50, 90}}) << endl;
    cout << maximumCuts(23, 12, 11, 13) << endl;
    cout << maximum_cuts(23, 11, 12, 13) << endl;
    cout << minimumCoins({9, 6, 5, 1}, 11) << endl;
    cout << minimum_coins({3, 4, 1}, 5) << endl;
    cout << minimumJumps({3, 4, 2, 1, 2, 1}) << endl;
    cout << knapSack({60, 100, 120}, {10, 20, 30}, 5, 3) << endl;
    cout << knapSack({10, 40, 30, 50}, {5, 4, 6, 3}, 10) << endl;
    cout << optimalStrategyRecursive({2, 3, 15, 7}) << endl;
    cout << optimal_strategy_recursive({2, 3, 15, 7}) << endl;
    cout << optimalStrategy({2, 3, 15, 7}) << endl;
    cout << eggDropping(10, 2) << endl;
    cout << egg_dropping(3, 2) << endl;
    cout << countBst(17) << endl;
    cout << count_bst(17) << endl;
    cout << maximumSum({10, 5, 15, 20, 2, 30});
    cout << endl;
    cout << maximum_Sum({3, 5, 15, 20, 2, 30}) << endl;
    cout << maximum_sum({3, 5, 15, 20, 2, 30}) << endl;
    cout << subsetSum({10, 20, 15}, 25, 3) << endl;
    cout << subset_sum({10, 20, 15}, 0, 0) << endl;
    cout << subsetSum({2, 5, 3}, 5) << endl;
    cout << matrixMultiplication({2, 1, 3, 4}, 0, 3) << endl;
    cout << matrixChain({2, 1, 3, 4}) << endl;
    cout <<"string partitioning: "<<stringPartitioning("mississipp", 0, 3) << endl;
    cout << stringPartitioning("geek") << endl;
    cout << allocateMinimumPages({10}, 0, 0, 3) << endl;
    cout << allocatePages({10, 20, 30, 40}, 4, 3) << endl;
    cout << allocatePages({10, 20, 30, 40}, 2) << endl;
}
