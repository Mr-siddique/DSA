#include <bits/stdc++.h>
using namespace std;
void calcPrefix(vector<int>arr,vector<long long>&res){
        int temp=arr[0];
        res.push_back(temp);
    for(int i=1;i<arr.size();i++){
        res.push_back(res[i-1]^arr[i]);
    }
 }
main(){
    vector<int>arr = {1,3,4,8};
    
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<long long>res;
    vector<int>v;
    calcPrefix(arr,res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<queries.size();i++){
        int left=queries[i][0];
        int right=queries[i][1];
        if(left==0){
            cout<<res[right]<<endl;
        }else{
          cout<<(res[right]^res[left-1])<<endl;
        }
    }
}