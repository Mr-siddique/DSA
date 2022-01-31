#include <bits/stdc++.h>
using namespace std;
bool isSafe(string str, int low, int i, int high)
{
    if (low != 0 && str[low - 1] == 'a' && str[i] == 'b')
        return false;
    else if (high == low + 1 && str[low] == 'b' && str[i] == 'a')
        return false;
    return true;
}
void printPermutaion(string str, int low, int high)
{
    if (low == high)
    {
        cout << str << " ";
        return;
    }
    for (int i = low; i <= high; i++)
    {
        if (isSafe(str, low, i, high))
        {
            swap(str[low], str[i]);
            printPermutaion(str, low + 1, high);
            swap(str[low], str[i]);
        }
    }
}
void dfs(vector<vector<int>> &maze, int i, int j, int n, int m, vector<vector<int>> &res)
{
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 0)
        return;
    maze[i][j] = 0;
    res[i][j] = 1;
    dfs(maze, i + 1, j, n, m, res);
    dfs(maze, i, j + 1, n, m, res);
}
bool ratInAMaze(vector<vector<int>> maze, vector<vector<int>> &res)
{

    int n = maze.size();
    int m = maze[0].size();
    if (maze[n - 1][m - 1] == 0)
        return false;
    dfs(maze, 0, 0, n, m, res);
    return maze[n - 1][m - 1] == 0;
}
//using backTracking
bool ratVSmazeRec(vector<vector<int>> maze, vector<vector<int>> &res, int n, int m, int i, int j)
{
    if (i == n - 1 && j == m - 1 && maze[i][j] == 1)
    {
        res[i][j] = 1;
        return true;
    }
    if (i < n && j < m && maze[i][j] == 1)
    {
        res[i][j] = 1;
        if (ratVSmazeRec(maze, res, n, m, i + 1, j) == true)
            return true;
        else if (ratVSmazeRec(maze, res, n, m, i, j + 1) == true)
            return true;
        res[i][j] = 0;
    }
    return false;
}
bool ratVSmaze(vector<vector<int>> maze, vector<vector<int>> res, int n, int m)
{
    if (ratVSmazeRec(maze, res, n, m, 0, 0) == false)
        return false;
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
        return true;
    }
}

//N-queens problem
bool isSafe(vector<vector<int>> board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
bool solveRec(vector<vector<int>> &board, int col, int n)
{
    if (col == n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n) == true)
        {
            board[i][col] = 1;
            if (solveRec(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
bool solve(vector<vector<int>> board, int n)
{
    if (solveRec(board, 0, n) == false)
        return false;
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        return true;
    }
}
// sudoko problem
bool checkSafe(vector<vector<int>> grid, int i, int j, int n)
{
    int N = grid.size();
    for (int k = 0; k < N; k++)
    {
        if (grid[i][k] == n || grid[k][j] == n)
            return false;
    }
    int s = sqrt(N);
    int row_index = i - i % s;
    int col_index = j - j % s;
    for (int k = 0; k < s; k++)
    {
        for (int l = 0; l < s; l++)
        {
            if (grid[k + row_index][l + col_index] == n)
                return false;
        }
    }
    return true;
}
bool sudoko(vector<vector<int>> &grid)
{
    int N = grid.size();
    int i, j;
    for (i = 0; i < N; i++){
        bool flag=false;
        for (j = 0; j < N; j++){
            if (grid[i][j] == 0){
                flag=true;
                break;
            }
        }
        if(flag==true)
        break;
    }
    if (i == N && j == N)
        return true;

    for (int k = 1; k <= N; k++)
    {
        if (checkSafe(grid, i, j, k))
        {
            grid[i][j] = k;
            if (sudoko(grid))
                return true;
            grid[i][j] = 0;
        }
    }
    return false;
}
main()
{
    printPermutaion("abc", 0, 2);
    cout << endl;
    vector<vector<int>> v = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    vector<vector<int>> res(v.size(), vector<int>(v[0].size()));
    // if (ratInAMaze(v, res))
    // {
    //     cout << "YES" << endl;
    //     for (int i = 0; i < res.size(); i++)
    //     {
    //         for (int j = 0; j < res[0].size(); j++)
    //             cout << res[i][j] << " ";
    //         cout << endl;
    //     }
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
    cout << endl;
    cout << ratVSmaze(v, res, v.size(), v[0].size()) << endl;
    int n = 4;
    vector<vector<int>> queen(n, vector<int>(n));
    cout << solve(queen, n);
    cout << endl;
     vector<vector<int>> sdk = {{1, 0, 3, 0}, {0, 0, 2, 1}, {0, 1, 0, 2}, {2, 4, 0, 0}};
    if (sudoko(sdk) == false)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < sdk.size(); i++)
        {
            for (int j = 0; j < sdk.size(); j++)
                cout << sdk[i][j] << " ";
            cout << endl;
        }
    }
}