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
    int n, s;
    cin >> n >> s;
    int a[n];
    FOR(i, 0, n)
        cin >> a[i];

    int sum = 0;
    FOR(i, 0, n)
    sum += a[i];

    if (s > sum)
        cout << -1 << endl;
    else
    {
        int ans = 0;

        vi index;
        FOR(i, 0, n)
        if (a[i] == 1) index.pb(i);
        int len = 0;
        if (sum == s)
        {
            len = n;
            cout<<0<<endl;
        }
        else
        {
            len = index[s];
            // cout<<len<<endl;
            for (int i = 1; i < sum - s; i++)
            {
                len = max(len, index[i + s] - (index[i - 1] + 1));
                // cout<<len<<" ";
            }

            len = max(len, n - (index[sum - s - 1] + 1));

            cout << n - len << endl;
        }
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