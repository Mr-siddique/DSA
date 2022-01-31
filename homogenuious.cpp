#include<bits/stdc++.h>
using namespace std;
main()
{
    string str="abbbaa";
    int count=1,res=0;
    for(int i=1;i<str.length();i++)
    {
        if(str[i]==str[i-1])
        count++;
        else{
            res=max(res,count);
            count=1;
        }
    }
    res=max(res,count);
    cout<<res;
}