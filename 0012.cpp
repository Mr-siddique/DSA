#include<bits/stdc++.h>
using namespace std;
long long fact (int n){
  if(n<=1) return 1;
  return n*fact(n-1);
}
main()
{
 string str="1020202021010101";
 vector<int>temp;
 for(int i=0;i<str.length();i++){
 temp.push_back(str[i]-48);
 if(temp[i]==0)
 temp[i]=-3;
 }
 int prefix_sum=0,count=0;
 unordered_set<int>s;
 for(int i=0;i<temp.size();i++)
 {
   prefix_sum+=temp[i];
   if(prefix_sum==0)
   count++;
  if(s.find(prefix_sum)!=s.end())
  count++;
  s.insert(prefix_sum);
 }
 cout<<count;
}