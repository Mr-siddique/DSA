#include <iostream>
#include<bits/stdc++.h>
using namespace std;
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = nums[1] - nums[0];
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] < l){
                l = nums[i] - nums[i-1];
            } 
        }
        int r = nums[n-1] - nums[0];
        while(l<r){
            int mid = l + (r - l)/2;
            int count = 0;
            for(int i = 0; i < n; i++){
                int pos = upper_bound(nums.begin(), nums.end(), nums[i] + mid) - nums.begin();
                count += pos - i - 1;
            }
            if(count < k){
                l = mid+1;
            }
            else
                r = mid;
        }
        return l;
        
    }
main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       vector<int>arr(n);
       for(int i=0;i<n;i++)
       cin>>arr[i];
   cout<<smallestDistancePair(arr,k)<<endl;
   }   
}































// bool mycomp(vector<int>a,vector<int>b)
// {
//     return a[0]<b[0];
// }
// int main() {
// 	//code
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	    int k,n;
// 	    cin>>n>>k;
// 	   unordered_map<int,int>mp;
// 	   for(int i=0;i<n;i++){
// 	       int temp;
// 	       cin>>temp;
// 	      mp[temp]++;
// 	   }
// 	   long long sum=0;
//        vector<vector<int>>temp;
//        for(auto x:mp)
//        temp.push_back({x.first,x.second});
//        sort(temp.begin(),temp.end(),mycomp);
//        for(int i=0;i<mp.size();i++)
//        {
//            int freq=temp[i][1];
//            sum+=(freq*temp[i][0]);
//            k-=freq;
//            if(k==0)
//            break;
//           if(k<0){
//               while(k<0)
//               {
//                   sum-=temp[i][0];
//                   k++;
//               }
//           }
//        }
//        cout<<sum<<endl;
// 	}
// 	return 0;
// }
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
// 	//code
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	    int k,n;
// 	    cin>>n>>k;
// 	   unordered_map<int,int>mp;
// 	   for(int i=0;i<n;i++){
// 	       int temp;
// 	       cin>>temp;
// 	      mp[temp]++;
// 	   }
// 	   long long sum=0;
//        bool m=false;
// 	   while(k)
// 	   {
// 	   int mn=INT_MAX;
// 	   int freq;
// 	       for(auto x:mp)
// 	       {
// 	           if(x.first<mn){
// 	           mn=x.first;freq=x.second;
// 	           }
//            }
//         mp.erase(mn);
// 	     while(freq){
// 	     sum+=mn;
//          freq--;
//          k--;
//          if(k==0)
//          break;
//          }
// 	   }
// 	   cout<<sum<<endl;
// 	}
// 	return 0;
// }