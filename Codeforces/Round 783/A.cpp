#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n == m)
        {
            if (n == 1)
                cout << 0 << endl;
            else
                cout << 2*(n-1) << endl;
        }
        else
        {
            int ans = 0;
            if (n == 1 && m == 2)
                ans = 1;
            else if (n == 2 && m == 1)
                ans = 1;
            else if (n == 1 && m > 2)
                ans = -1;
            else if (m == 1 && n > 2)
                ans = -1;
            else
            {
                if (n > m)
                    swap(n, m);
                ans = 2*(n-1);
                if ((m - n) % 2 == 0)
                    ans += 2 * (m - n);
                else
                {
                    ans += 2 * (m - n - 1) + 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}