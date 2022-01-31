#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
void printKMax(vector<int>arr, int k) 
{ 
    int j, max; 
   int n=arr.size();
    for (int i = 0; i <= n - k; i++) 
    { 
        max = arr[i]; 
 
        for (j = 1; j < k; j++) 
        { 
            if (arr[i + j] > max) 
                max = arr[i + j]; 
        } 
        cout << max << " "; 
    } 
}
main(){
 int n,k;
 map<int,vector<int>>m;
 cin>>n>>k;
 for(int i=0;i<n;i++){
   int h;
   cin>>h;
   m[h].push_back(h);
 }
  int temp=k;
  int first,second;
  first=second=0;
 for(auto i:m){
     if(temp==k)
     first=i.first;
    if(k<=0){
     second=i.first;
     break;
    }
       k-=i.second.size();
     cout<<i.first<<": ";
     for(int j=0;j<i.second.size();  j++){
     cout<<i.second[j]<<" ";
     }
     cout<<endl;
 }
 cout<<first-second<<endl;
}