#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int maxOcc(int L[], int R[], int n, int maxx)
{
    int arr[maxx + 2] = {0};
    // memset(arr, 0, sizeof(arr));

    for (int i = 0; i < n; i++)
    {
        arr[L[i]]++;

        arr[R[i] + 1]--;
    }

    int maxm = arr[0], res = 0;

    for (int i = 1; i < maxx + 2; i++)
    {
        arr[i] += arr[i - 1];

        if (maxm < arr[i])
        {
            maxm = arr[i];
            res = i;
        }
    }
    for (int i = 0; i < maxx + 2; i++)
    {
        cout << arr[i] << " ";
    }
    return res;
}
// For the observation, in previous hint, make 2 arrays, 
// First, will store smallest occuring element before the element
// Second, will store largest occuring element after the element

// Traverse the Second array, till the element in second array is larger than or equal to First array, and store the index difference. And if it becomes smaller, traverse the first array till it again becomes larger.

// And store the max difference of this index difference.
void temp(int arr[],int n){
 int first[n],second[n],min_elem=arr[0],max_elem=arr[n-1];
    first[0]=arr[0];
    second[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        if(arr[i]<min_elem)
        min_elem=arr[i];
        first[i]=min_elem;
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max_elem)
        max_elem=arr[i];
        second[i]=max_elem;
    }
    for(int i=0;i<n;i++){
        cout<<first[i]<<" "<<second[i]<<" "<<endl;
    }
}
main()
{
    // int x[] = {1, 4, 3, 1};
    // int y[] = {15, 8, 5, 4};
    // cout << endl
    //      << maxOcc(x, y, 4, 15) << endl;
    int arr[]={34,8,10,3,2,80,30,33,1};
    temp(arr,9);
}