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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vi v;
    FOR(i, 0, n)
    {
        if (s[i] == '1')
            v.pb(i);
    }

    int size = v.size();
    int ans = 0;
    if (size > 0)
    {
        if ((n -1- v[size - 1] + v[0]) <= k && size>1)
        {
            ans = 11 * size - 11;
        }
        else if (n-1 - v[size - 1] <= k)
        {
            ans = size * 11 - 10;
        }
        else if (v[0] <= k)
        {
            ans = 11 * size - 1;
        }
        else
            ans = 11 * size;
    }

    cout << ans << endl;
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