#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
    int findShortestSubArray(vector<int> nums) {

        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int first,second=-1;
     vector<int>res_temp;
        for(auto temp:m){
            if(temp.second==second&&find(nums.begin(),nums.end(),temp.first)>find(nums.begin(),nums.end(),first)){
            second=temp.second;
            first=temp.first;
            }else if(temp.second>second){
            second=temp.second;
            first=temp.first;
            } 
        }
    
        int i=0,j=nums.size()-1;
        while(nums[i]!=first)
            i++;
        while(nums[j]!=first)
            j--;
        if(i==0)
            return j+1;
            return (j+1)-i;
    }
main(){
cout<<findShortestSubArray({1,2,2,1,2,1,1,1,1,2,2,2})<<endl;
}