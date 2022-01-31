#include<iostream>
#include<vector>
#include<map>
using namespace std;
main(){
    vector<int>forbidden={162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    vector<int>hashmap(2001);
    for(int i=0;i<forbidden.size();i++){
        hashmap[forbidden[i]]=1;
    }
    int count=0;
    int a,b,x;
    a=29;
    b=98;x=80;
    int current=0;
    while(current<x){
     current+=a;
     count++;
     if(hashmap[current]==1){
     cout<<-1 <<endl;
     break;
     }
     if(current>x){
     
      current=current-b;
      count++;
     if(hashmap[current]==1){
     cout<<-1<<endl;
     break;
     }
     }
    }
    if(current==x)
     cout<<count<<endl;
     else cout<<-1;
    cout<<count<<current;
}
