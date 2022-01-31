#include <bits/stdc++.h>
using namespace std;
int builtTree(int arr[], int low, int high, int tree[], int segmentIndex)
{
    if (low == high)
    {
        tree[segmentIndex] = arr[low];
        return arr[low];
    }
    int mid = (low + high) / 2;
    tree[segmentIndex] = builtTree(arr, low, mid, tree, 2 * segmentIndex + 1) + builtTree(arr, mid + 1, high, tree, 2 * segmentIndex + 2);
    return tree[segmentIndex];
}
int getSum(int tree[], int qs, int qe, int ss, int se, int si)
{
    if (qs > se || qe < ss)
        return 0;
    if (qs <= ss && qe >= se)
        return tree[si];
    int mid = (ss + se) / 2;
    return getSum(tree, qs, se, ss, mid, 2 * si + 1) + getSum(tree, qs, qe, mid + 1, se, 2 * si + 2);
}
void update(int tree[], int diff, int index, int ss, int se, int si)
{
    if (index < ss || index > se)
        return;
    tree[si] += diff;
    if (ss < se)
    {
        int mid = (ss + se) / 2;
        update(tree, diff, index, ss, mid, 2 * si + 1);
        update(tree, diff, index, mid + 1, se, 2 * si + 2);
    }
}

//binary index tree
int getSum(int binaryIndexTree[], int index)
{
    index = index + 1;
    int sum = 0;
    while (index > 0)
    {
        sum += binaryIndexTree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateTree(int arr[], int binaryIndexTree[], int n, int index, int diff)
{
    // arr[index] = diff;
    index = index + 1;
    while (index <= n)
    {
        binaryIndexTree[index] += diff;
        index = index + index & (-index);
    }
}
int *constructTree(int arr[], int n)
{
    int *binaryIndexTree=new int[n + 1];
    for (int i = 0; i <= n; i++)
        binaryIndexTree[i] = 0;

    for (int i = 0; i < n; i++)
        updateTree(arr, binaryIndexTree, n, i, arr[i]);
return binaryIndexTree;
}
// 10 30 30 100 50
main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tree[4 * n] = {0};
    builtTree(arr, 0, n - 1, tree, 0);
    for (int i = 0; i < 4 * n; i++)
        cout << tree[i] << " ";
    cout << endl;
    cout << getSum(tree, 1, 2, 0, n - 1, 0) << endl;
    int value = 20;
    int index = 2;
    int diff = value - arr[index];
    update(tree, diff, index, 0, n - 1, 0);
    cout << getSum(tree, 1, 2, 0, n - 1, 0) << endl;
    int bArr[] = {10, 20, 30, 40, 50};
    int size = sizeof(bArr) / sizeof(bArr[0]);
    int *BITree=constructTree(bArr, size);
    for(int i=0;i<=size;i++)cout<<BITree[i]<<" ";cout<<endl;
    updateTree(arr,BITree,size,2,35-arr[2]);
    for(int i=0;i<=size;i++)cout<<BITree[i]<<" ";cout<<endl;
    cout<<getSum(BITree,4)<<endl;
}