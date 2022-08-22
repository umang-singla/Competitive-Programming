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

bool avail(vector<int> a, int key)
{
    if (a.size() > 0)
    {
        int st = 0, ed = a.size() - 1;
        while (st <= ed)
        {
            int mid = (st + ed) / 2;
            if (a[mid] == key)
                return true;
            else if (a[mid] < key)
            {
                st = mid + 1;
            }
            else
            {
                ed = mid - 1;
            }
        }
        return false;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    // testcase();
    int n, m;
    cin >> n >> m;

    vector<vi> from(n), to(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        from[a - 1].pb(b - 1);
        to[b - 1].pb(a - 1);
    }

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        sort(all(to[i]));
        sort(all(from[i]));
        if (to[i].size() > 1)
        {
            // cout<<to[i].size()<<" ";
            for (int j = 0; j < to[i].size(); j++)
            {
                for (int k = j + 1; k < to[i].size(); k++)
                {
                    // cout<<to[i][j]<<" "<<to[i][k]<<endl;
                    dp[to[i][j]][to[i][k]]++;
                    dp[to[i][k]][to[i][j]]++;
                }
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (from[i].size() > 1)
        {
            for (int j = 0; j < from[i].size(); j++)
            {
                for (int k = j + 1; k < from[i].size(); k++)
                {
                    if (avail(from[from[i][j]], i) && avail(from[from[i][k]], i))
                    {
                        ans--;
                    }
                    // cout<<i<<" "<<from[i][j]<<" "<<from[i][k]<<endl;

                    ans += dp[from[i][j]][from[i][k]];
                }
            }
        }
    }

    cout << ans << endl;
}