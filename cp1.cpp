#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
main(){
//  vector<vector<int>>q={{6,5,4},{2,3,7},{4,6,5},{7,2,3},{5,3,1}};
int n;
// vector<int>res;
 int count=0;
 map<int,int>m;
 cin>>n;
while(n--){
int a,b,c;
cin>>a>>b>>c;
int temp=a+b+c;
m[temp]++;
}
for(auto i:m){
    if(i.second==1)
    count++;
}
// sort(res.begin(),res.end());
// vector<int>m(res[res.size()-1]+1,0);
// for(int i=0;i<res.size();i++){
//     m[res[i]]++;
// }
// for(int i=0;i<m.size();i++){
//   if(m[i]==1)
//   count++;
// }
// cout<<count<<endl;
}