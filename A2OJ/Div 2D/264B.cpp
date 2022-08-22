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
    int a[n];
    FOR(i, 0, n)
    cin >> a[i];

    set<int> factors[a[n - 1] + 1];
    set<int> multiples[a[n - 1] + 1];

    int dp[100001] = {0};
    FOR(i, 0, n)
    dp[a[i]] = 1;

    for (int i = 2; i <= a[n - 1]; i++)
    {
        if (factors[i].size() == 0)
        {
            for (int j = 1; j * i <= a[n - 1]; j++)
            {
                factors[j * i].insert(i);
                // factors[j * i].insert(j);
                if (dp[i * j])
                    multiples[i].insert(i * j);
            }
        }
    }
    // factors[2].insert(2);
    FOR(i, 1, a[n - 1] + 1)
    {
        if (factors[i].size() == 0)
        {
            factors[i].insert(i);
        }
    }

    FOR(i, 0, n)
    {
        factors[a[i]].erase(1);
    }

    // cout<<'a';

    FOR(i, 0, n)
    {
        for (auto x : factors[a[i]])
        {
            auto it = multiples[x].find(a[i]);

            if (it != multiples[x].begin() )
            {
                it--;
                dp[a[i]] = max(dp[a[i]], 1 + dp[*it]);
            }
        }
    }

    int ans = 0;
    FOR(i, 0, n)
    {
        // cout << dp[a[i]] << " ";
        if (dp[a[i]] > ans)
            ans = dp[a[i]];
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}