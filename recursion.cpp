#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool ispalindrome(string str, int i, int j)
{
    if (i >= j)
        return true;
    return str[i] == str[j] && ispalindrome(str, i + 1, j - 1);
}
int perfectCuts(int n, int a, int b, int c)
{
    if (n == 0)
        return n;
    if (n < 0)
        return -1;
    int res = max(perfectCuts(n - a, a, b, c), max(perfectCuts(n - b, a, b, c), perfectCuts(n - c, a, b, c)));
    if (res == -1)
        return -1;
    return res + 1;
}
void printSubsets(string str,int index = 0, string current = "")
{
    
    if (index == str.length())
    {
        cout<<current<<" ";
        return;
    }
    printSubsets(str,index + 1, current);
    current += str[index];
     printSubsets(str,index + 1, current);
}
void TOH(int n,char a,char b,char c){
    if(n==1){
 f   cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
    return;
    }
    // cout<<"move "<<n<<" from "<<a<<" to "<<b<<endl;
     TOH(n-1,a,c,b);
    cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
     TOH(n-1,c,b,a);
    
}
int jos(int n,int k){
    if(n==1)
    return 0;
    return (jos(n-1,k)+k)%n;
}
void subsetsSum(vector<int>arr,int index,int k,int &count,vector<int>temp){
    if(k==0){
         count++;
         return;
    }
    if(index==arr.size()){
        int sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
        }
        if(sum==k)
        count++;
        return;
    }
    subsetsSum(arr,index+1,k,count,temp);
   temp.push_back(arr[index]);
    subsetsSum(arr,index+1,k,count,temp);
}
int betterSubsetsSum(vector<int>arr,int index,int sum){
    if(index==0){
        return (sum==0)?1:0;
    }
    return betterSubsetsSum(arr,index-1,sum)+betterSubsetsSum(arr,index-1,sum-arr[index-1]);
}
void phone(string str,int index,string current,int n,vector<string>&res){
    if (index == str.length())
    {
        if(current.length()==n)
        res.push_back(current);
        return;
    }
    phone(str,index + 1, current,n,res);
    current += str[index];
     phone(str,index + 1, current,n,res);
}
main()
{
    string str = "abbcbba";
    int count = 0;
    cout << ispalindrome(str, 0, str.length() - 1) << endl;
    cout << perfectCuts(23, 11, 9, 12) << endl;

    vector<string>v;
    printSubsets("abc");
    TOH(2,'a','b','c');
     count=0;
    subsetsSum({10,20,15},0,25,count,{});
    cout<<count<<endl;
    cout<<betterSubsetsSum({10,20,15},3,25)<<endl;
    vector<int>arr{3,4,5};
     str="";
   for(int i=0;i<arr.size();i++){
       if(arr[i]==1)
       str+="";
       else if(arr[i]==2)
       str+="abc";
        else if(arr[i]==3)
       str+="def";
        else if(arr[i]==4)
       str+="ghi";
        else if(arr[i]==5)
       str+="jkl";
        else if(arr[i]==6)
       str+="mno";
        else if(arr[i]==7)
       str+="pqrs";
        else if(arr[i]==8)
       str+="tuv";
        else if(arr[i]==9)
       str+="wxyz";
   }
   vector<string>res;
   
    phone(str,0,"",3,res);
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}