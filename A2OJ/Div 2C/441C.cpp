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

#define mod 1000000007

using namespace std;

void testcase()
{

    int n, m, k;
    cin >> n >> m >> k;

    int ans[n][m];

    int i = 0, j = 0;

    for (int i = 0; i < n; i++)
    {
        FOR(j, 0, m)
        {
            ans[i][j] = 1;
        }
        cout << endl;
    }

    int temp = k;

    while (k > 1)
    {
        ans[i][j] = k;
        if (j == m - 1 && i % 2 == 0)
        {
            i++;
        }
        else if (j == 0 && i % 2 == 1)
        {
            i++;
        }
        else if (i % 2 == 0)
        {
            j++;
        }
        else
        {
            j--;
        }
        ans[i][j] = k;
        if (j == m - 1 && i % 2 == 0)
        {
            i++;
        }
        else if (j == 0 && i % 2 == 1)
        {
            i++;
        }
        else if (i % 2 == 0)
        {
            j++;
        }
        else
        {
            j--;
        }
        k--;
    }

    vector<pair<int, int>> v[temp];

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            FOR(j, 0, m)
            {
                // cout<<ans[i][j]<<" ";
                v[ans[i][j] - 1].pb(mp(i, j));
            }
        }
        else
        {
            FORr(j, m-1, 0)
            {
                // cout<<ans[i][j]<<" ";
                v[ans[i][j] - 1].pb(mp(i, j));
            }
        }
    }

    for (int i = 0; i < temp; i++)
    {
        cout << v[i].size() << " ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j].ff + 1 << " " << v[i][j].ss + 1 << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        testcase();
    }
}