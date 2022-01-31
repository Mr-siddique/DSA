#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int temp;
	   // bool x=true;
	    unordered_set<int>s;
	    for(int i=0;i<m;i++){
	     cin>>temp;
	    s.insert(temp);
	    }
	   // cout<<s.size()<<" "<<n<<endl;
	    for(int i=0;i<n;i++)
	    {
	        cin>>temp;
	        if(s.find(temp)==s.end()){
	        break;
	        }
	    }
	    if(s.find(temp)==s.end())
	    cout<<"No"<<endl;
	    else
	    cout<<"Yes"<<endl;
	}
	return 0;
}