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
#define vvi vector<<vi>>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

using namespace std;

void testcase()
{

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n)
        cin >> a[i];

    int dp[n][2];
    int prefix[n];
    prefix[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    if (a[0] % 2)
    {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    else
    {
        dp[0][0] = 0;
        dp[0][1] = 1;
    }

    FOR(i, 1, n)
    {
        if (a[i] % 2)
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] ;
            if(prefix[i] % 2) dp[i][0]++;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];

        }
    }

    cout << dp[n - 1][0] + dp[n - 1][1] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin >> t;
    while (t--)
    {
        testcase();
    }
}