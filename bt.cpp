#include <bits/stdc++.h>
using namespace std;
// int main()
// {
// 	int n; cin>>n;
// 	int a[n];
// 	for(int i=0;i<n;i++)
// 	    cin>>a[i];
// 	sort(a,a+n);
// 	int x;
// 	cin>>x;
// 	while(x--)
// 	{
// 		int p;
// 		cin>>p;
// 		int i=upper_bound(a,a+n,p)-a;
// 		cout<<i<<endl;
// 	}
// }
int main()
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    int remaining_minutes = 4 * 60 - k;
    for (int i = 1; i <= n; i++)
    {
        remaining_minutes -= 5 * i;
        count++;
        if (remaining_minutes < 0)
        {
            count--;
            break;
        }
    }
    cout << count << endl;
}