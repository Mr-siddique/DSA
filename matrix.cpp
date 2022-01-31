#include <bits/stdc++.h>
using namespace std;
//declaring a 2d array of vectors
void vector2d()
{
    int m = 3, n = 2;
    vector<int> arr[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i].push_back(10);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // arr[i].push_back(10);
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
    //another method to create a 2d vector
    vector<vector<int>> v;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.push_back(i * j);
        v.push_back(temp);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
}
//print matrix in snake pattern
void printSnakePattern(vector<vector<int>> arr)
{
    bool count = false;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j] << " ";
        else
            for (int j = arr[i].size() - 1; j >= 0; j--)
                cout << arr[i][j] << " ";
    }
}
//boundry traversal of a matrix
void boundryTraversal(vector<vector<int>> arr)
{
    if (arr.size() == 1)
        for (int i = 0; i < arr[0].size(); i++)
            cout << arr[0][i];
    else if (arr[0].size() == 1)
        cout << arr[0][0] << " ";
    else
    {
        for (int i = 0; i < arr[0].size(); i++)
            cout << arr[0][i] << " ";
        for (int i = 1; i < arr.size(); i++)
            cout << arr[i][arr[i].size() - 1] << " ";
        for (int i = arr[arr.size() - 1].size() - 2; i >= 0; i--)
            cout << arr[arr.size() - 1][i] << " ";
        for (int i = arr.size() - 2; i >= 1; i--)
            cout << arr[i][0] << " ";
    }
}
    // vector<vector<int>> transpose(vector<vector<int>>& A) {
    //     vector<vector<int>>res;
    //     // cout<<A.size()<<endl;
    //     for(int i=0;i<A[0].size();i++)
    //     {
    //         vector<int>temp;
    //         for(int j=0;j<A.size();j++)
    //             temp.push_back(A[j][i]);
    //         res.push_back(temp);
    //     }
    // return res;
        
    // }
void transposeOfMatrix(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
            swap(arr[i][j], arr[j][i]);
            cout<<"transpose"<<":";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void rotateMatrix90deg(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
        reverse(arr[i].begin(), arr[i].end());
    for (int i = 0; i < arr.size(); i++)
    {
        // reverse(arr[i].begin(), arr[i].end());
        for (int j = i + 1; j < arr.size(); j++)
            swap(arr[i][j], arr[j][i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void spiralMatrix(vector<vector<int>> arr)
{
    int top = 0, bottom, left = 0, right, m, n;
    m = arr.size();
    n = arr[0].size();
    right = n - 1;
    bottom = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << arr[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << arr[i][right] << " ";
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
    }
}
int binarySearch(vector<int> arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
vector<int> searchInmatrix(vector<vector<int>> arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = binarySearch(arr[i], x);
        if (temp != -1)
            return {i, temp};
    }
    return {-1};
}
vector<int> againSearchInMatrix(vector<vector<int>> arr, int x)
{
    int i = 0;
    int j = arr[0].size() - 1;
    while (i < arr.size() && j >= 0)
    {
        if (arr[i][j] == x)
            return {i, j};
        else if (arr[i][j] > x)
            j--;
        else
            i++;
    }
    return {-1};
}
int matrixMedian(vector<vector<int>> arr)
{
    int mn, mx;
    int r = arr.size(), c = arr[0].size();
    mn = arr[0][0];
    mx = arr[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        mn = min(mn, arr[i][0]);
        mx = max(mx, arr[i][c - 1]);
    }
    int medpos=(r*c+1)/2;
    while(mn<mx){
     int mid=(mn+mx)/2;
     int mid_pos=0;
     for(int i=0;i<r;i++)
     mid_pos+=upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();
     if(mid_pos<medpos)
     mn=mid+1;
     else 
     mx=mid;
    }
    return mn;
}
main()
{
    vector2d();
    cout << endl;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    printSnakePattern(matrix);
    cout << endl;
    boundryTraversal(matrix);
    cout << endl;
    transposeOfMatrix({{1,2,3},{4,5,6}});
    cout << endl;
    rotateMatrix90deg(matrix);
    cout << endl;
    spiralMatrix(matrix);
    cout << endl;
    vector<int> res = searchInmatrix(matrix, 16);
    res.size() == 1 ? cout << res[0] << endl : cout << "found at : " << res[0] << " " << res[1] << endl;
    res = againSearchInMatrix(matrix, 17);
    res[0] == -1 ? cout << "not found" << endl : cout << "found at : " << res[0] << " " << res[1] << endl;
    cout<<matrixMedian(matrix)<<endl;
    //  vector<vector<int>(3)>temp(2);
    //  cout<<temp.size()<<" "<<temp[0].size();
    int n=2,m=3;
    int a[n][m];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}