#include <cmath>
#include <iostream>
using namespace std;
bool isPerfectSquare(long long n)
{
    if (n < 0 || (n & 2) || ((n & 7) == 5) || ((n & 11) == 8))
        return false;
    if (n == 0)
        return true;
    if ((sqrt(n) - floor(sqrt(n))) != 0)
        return false;
    return true;
}
int fun(int n){
   int x=1,k;
   if(n==1)
   return x;
   for(k=1;k<n;++k){
       x+=fun(k)*fun(n-k);
   }
return x;
}
double f(double x){
  if (abs(x*x - 3) < 0.01) return x;
  else return f(x/2 + 1.5/x);
}
main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     long long n, num1, num2, maximum = -1, minimum = -1;
    //     cin >> n;
    //     num1 = n + 1;
    //       num2 = n - 1; 
    //     while (true) { 
    //         if (isPerfectSquare(num1)) { 
    //             maximum = num1; 
    //             break; 
    //         } 
    //         if (isPerfectSquare(num2)) { 
    //             minimum = num2; 
    //             break; 
    //         } 
    //         else{
    //             num1++;num2--;
    //         }
    //     } 
    //     cout<<maximum<<" "<<minimum<<" "<<num1<<" "<<num2<<endl;
    //     if(isPerfectSquare(maximum)&&isPerfectSquare(minimum))
    //     cout<<maximum<<endl;
    //     else if(isPerfectSquare(maximum)){
    //         cout<<maximum<<endl;
    //     }else{
    //         cout<<minimum<<endl;
    //     }
    // }
    cout<<fun(5)<<endl;
    cout<<f(9.99)<<endl;
    
}
