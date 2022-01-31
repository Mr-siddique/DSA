#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
bool prime[MAX];
int prefix[MAX], suffix[MAX];

void compute(int prefix[], int suffix[])
{
    memset(prime, true, sizeof(prime));

    for (int i = 2; i * i < MAX; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < MAX; j += i)
                prime[j] = false;
        }
    }

    prefix[1] = 1;
    suffix[MAX - 1] = 1e9 + 7;

    for (int i = 2; i < MAX; i++)
    {
        if (prime[i])
            prefix[i] = i;
        else
            prefix[i] = prefix[i - 1];
    }

    for (int i = MAX - 1; i > 1; i--)
    {
        if (prime[i])
            suffix[i] = i;
        else
            suffix[i] = suffix[i + 1];
    }
}
void query(int prefix[], int suffix[], int L, int R)
{
    if (prefix[R] < L || suffix[L] > R)
    {
        cout << "-1" << endl;
    }
    else
    {
        if (prefix[R] - suffix[L] > 0)
        {
            cout << prefix[R] - suffix[L] << endl;
        }
        else if (prefix[R] - suffix[L] == 0)
        {
            cout << "0" << endl;
        }

    }
}
int main()
{
    compute(prefix, suffix);
    int q;
    cin >> q;
    int L[q], R[q];
    for (int i = 0; i < q; i++)
    {
        cin >> L[i] >> R[i];
    }

    for (int i = 0; i < q; i++)
        query(prefix, suffix, L[i], R[i]);
    return 0;
}