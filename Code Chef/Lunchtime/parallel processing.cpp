#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], prefix[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
            {
                prefix[i] = a[i];
            }
            else
            {
                prefix[i] = prefix[i - 1] + a[i];
            }
            // cout<<prefix[i]<<" ";
        }

        int ans = INT_MAX;
        ans = prefix[n-1];
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, max(prefix[i], prefix[n - 1] - prefix[i]));
        }

        cout << ans << endl;
    }
    return 0;
}