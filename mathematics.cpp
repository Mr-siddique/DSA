//gcd using equilidiean algorithm (optimized than neive solution)
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int optimizedeculidean(int x, int y)
{
    if (y == 0)
        return x;
    return optimizedeculidean(y, x % y);
}
int efficientLCM(int a, int b)
{
    return (a * b) / optimizedeculidean(a, b);
}
bool optimizedPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= ceil(sqrt(n)); i += 6)
    {
        if (n % i == 0 || n % i + 2 == 0)
            return false;
    }
    return true;
}
void optimizedPrimeFactors(int n)
{
    if (n <= 1)
        return;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n = n / 3;
    }
    for (int i = 5; i <= ceil(sqrt(n)); i += 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n = n / (i + 2);
        }
    }
    if (n > 3)
        cout << n << " ";
}
void optimizedDivisors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " ";
        }
    }
}
void optimizedDivisorsInSortedOrder(int n)
{
    int i;
    for (i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
    for (; i > 0; i--)
    {
        if (n % i == 0)
        {
            if (i != n / i)
                cout << n / i << " ";
        }
    }
}
void primesUsingSeiveAlgo(int n)
{
    if (n <= 1)
        return;
    vector<bool> check_prime(n + 1, true);
    // fill(check_prime,check_prime+n+1,true);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (check_prime[i])
        {
            for (int j = i * 2; j <= n; j = j + i)
            {
                check_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (check_prime[i])
            cout << i << " ";
    }
}
int recursivePower(int x, int y)
{
    if (y == 0)
        return 1;
    int temp = recursivePower(x, y / 2);
    temp *= temp;
    return (y % 2 == 0) ? temp : temp * x;
}
int iterativePower(int x, int y)
{
    int pow = x;
    for (int i = 1; i < y / 2; i++)
    {
        pow = pow * i;
        pow *= pow;
    }
    return pow;
}
main()
{
    int x, y;
    cin >> x >> y;
    cout << optimizedeculidean(x, y) << endl;
    cout << efficientLCM(x, y) << endl;
    //basic eculidean
    while (x != y)
    {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    cout << x << endl;
    cout << optimizedPrime(1031) << endl;
    optimizedPrimeFactors(450);
    cout << endl;
    optimizedDivisors(25);
    cout << endl;
    optimizedDivisorsInSortedOrder(15);
    cout << endl;
    primesUsingSeiveAlgo(25);
    cout << endl;
    cout << recursivePower(3, 5) << endl;
    cout << iterativePower(3, 5) << endl;
}