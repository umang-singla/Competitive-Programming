#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector << vi >>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define int long long int

using namespace std;

void testcase()
{
    int n;
    cin >> n;

    int power = 1;
    if (n == 1)
    {
        cout << 1 << endl
             << 1 << endl;
        return;
    }
    while (power < n)
        power *= 2;

    if (n %2==0)
    {
        int p[power + 1];
        int m = n;
        while (power != m && m > 0)
        {
            int m1 = power - 1 - (m);
            for (int i = m; i >= m1; i--)
            {
                p[i] = power - 1 - (i);
            }
            m = m1 - 1;
            power = 1;
            while (power < m)
                power *= 2;
        }
        if (power == 1 && m > 0)
        {
            p[1] = 1;
        }
        else if (m > 0)
        {
            // cout<<power;
            for (int i = power; i >= 1; i--)
            {
                p[i] = power - 1 - i;
            }
            p[power] = power - 1;
            p[power - 1] = power;
        }

        bool poss = true;
        for (int i = 1; i <= n; i++)
            if (p[i] == 0)
                poss = false;

        if (poss)
        {
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " ";
            }
            cout << endl;
            FOR(i, 1, n + 1)
                cout << p[i] << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        testcase();
}