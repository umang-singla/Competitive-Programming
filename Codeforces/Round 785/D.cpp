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
#define mod 1000000007

using namespace std;

void testcase()
{
    int b, q, y;
    cin >> b >> q >> y;
    int c, r, z;
    cin >> c >> r >> z;

    if (r % q != 0)
    {
        cout << 0 << endl;
    }
    else if (c < b || (c - b) % q != 0 || (c - b) / q + 1 > y)
    {
        cout << 0 << endl;
    }
    else if (c + (z - 1LL) * r > b + (y - 1LL) * q)
    {
        cout << 0 << endl;
    }
    else if (c - r < b || c + (z)*r > b + (y - 1) * q)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        set<int> d;
        int m = r / q;

        FOR(i, 1, sqrt(q) + 1)
        {
            if (q % i == 0)
            {
                d.insert(i * m);
                d.insert((q / i) * m);
            }
        }

        int ans = 0;

        for (auto diff : d)
        {
            ans = (ans + ((r / diff) % mod) * ((r / diff) % mod)) % mod;
        }

        cout << ans << endl;
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
    {
        testcase();
    }
}