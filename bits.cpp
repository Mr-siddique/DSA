#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// bitwise operators
// 1-&(AND)
// 2-|(OR)
// 3-^(xor)
// 4-<<(left-shift)
// property 1=>If we assume that leading y bits are 0 then result of (x<<y)is  x*2^y (^=pow)
// 5- >>(right-shift) adds 0 to the beginning and removes the last bits
// property 1- x>>y=floor(x/pow(2,y))
// 5- ~(bitwise NOT)=>flips all the bits (0->1),(1->0)

//check kth bit is set or not
//using leftshift operator
bool kthBitusingLeftShift(int n,int k){
  if(n & (1 << (k - 1))!=0) 
  return true;
  return false;
}
bool kthBitUsingRightshift(int n,int k){
  return ((n>>(k-1))&1!=0)?true:false;
}
//naive soln without using bits
int countBits(int n){
int res=0;
while(n>0){
  if(n%2!=0)
  res++;
  n=n/2;
}
return res;
}

//naive soln using bitwise operator
int countBitsBitwise(int n){
  int res=0;
  while(n>0){
    if(n&1==1)
    res++;
    n>>1;
  }
  return res;
}
int brainkarninghmsCountBits(int n){
  int res=0;
  while(n>0){
    n=n&(n-1);
    res++;
  }
  return res;
}
int countBits(int a,int b)
{
  int n=a^b;
  int count=0;
  while(n>0){
   n=n&(n-1);
   count++;
  }
  return count;
}
bool isPowOf2(int n){
  if(n<=0)
  return false;
  return (n&(n-1)==0);
}
int oddAperingNumber(vector<int>v){
  int res=0;
  for(int i=0;i<v.size();i++){
    res=res^v[i];
  }
  return res;
}
int findMissing(vector<int>v){
  int missing=v[0];
  for(int i=1;i<v.size();i++){
    missing=missing^v[i];
  }
  int mis=1;
  for(int i=2;i<=v.size()+1;i++){
    mis=mis^i;
  }
  return missing^mis;
}
void oddAppearnig(vector<int>v){
  int XOR,res1,res2;
  XOR=res1=res2=0;
  for(int i=0;i<v.size();i++){
   XOR=XOR^v[i];
  }
  int sn=XOR&~(XOR-1);
  for(int i=0;i<v.size();i++){
    if((sn&v[i])!=0)
    res1=res1^v[i];
    else
    res2=res2^v[i];
  }
  cout<<res1<<" "<<res2<<endl;
}
void powerSet(string str){
  int n=str.length();
  int power=pow(2,n);
  for(int i=0;i<power;i++){
    for(int j=0;j<n;j++){
      if((i&(1<<j))!=0)
      cout<<str[j];
    }
    cout<<" ";
  }
}
main(){
    int a=3,b=6;
    // 3&6=0011&0110=0010=2
    cout<<(a&b)<<endl;
    // 3|6=0011|0110=0111=7
    cout<<(a|b)<<endl;
    // 3^6=0011^0110=0101=5
  cout<<(a^b)<<endl;
    //3<<1=0011 <<1 0110=6  ==3*pow(2,1)
    //3<<2=0011 <<2 1100=12==3*pow(2,2);
    cout<<(a<<1)<<" "<<(a<<2)<<" "<<(a<<4)<<endl;
    // 33>>1==floor(33/pow(2,1))
    // 33>>2==floor(33/pow(2,2))
   cout<<(33>>1)<<" "<<(33>>2)<<endl;
  //  unsigned int x=1;
  //  cout<<(~x)<<endl;
   cout<<kthBitusingLeftShift(4,2)<<endl;
   cout<<kthBitUsingRightshift(500,3)<<endl;
  //  cout<<(10^20)<<endl;
   cout<<countBits(20,25);
   unsigned int temp=23;
   cout<<(~temp)<<endl;
   cout<<findMissing({1,2,4,5})<<endl;
   oddAppearnig({3,4,3,4,8,4,4,32,7,7});
   powerSet("Ma");
   cout<<endl;
  long long int x=387328793282378932787328;
  if(log2(x)==ceil(log2(x)))
  cout<<true<<endl;
  else
  cout<<false;
}
// 00000
// 11110
// 00001