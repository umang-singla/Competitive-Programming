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

    int a[n][n], grid[n][n];

    // memset(grid,0,sizeof(grid));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            grid[i][j] = 0;
        }
    }

    int right[2 * n - 1] = {0}, left[2 * n - 1] = {0};

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int temp = i;
        while (temp < n)
        {
            right[i] += a[temp][j];
            temp++;
            j++;
        }
        j = 0;
        temp = i;
        while (temp < n)
        {
            grid[temp][j] += right[i];
            temp++;
            j++;
        }
    }

    for (int i = n; i < 2 * n - 1; i++)
    {
        int j = i - n + 1;
        int temp = 0;
        while (j < n)
        {
            right[i] += a[temp][j];
            temp++;
            j++;
        }
        j = i - n + 1;
        temp = 0;
        while (j < n)
        {
            grid[temp][j] += right[i];
            temp++;
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int temp = i;
        while (temp >= 0)
        {
            left[i] += a[temp][j];
            temp--;
            j++;
        }
        j = 0;
        temp = i;
        while (temp >= 0)
        {
            grid[temp][j] += left[i];
            temp--;
            j++;
        }
    }

    for (int i = n; i < 2 * n - 1; i++)
    {
        int j = i - n + 1;
        int temp = n - 1;
        while (j < n)
        {
            left[i] += a[temp][j];
            temp--;
            j++;
        }
        j = i - n + 1;
        temp = n - 1;
        while (j < n)
        {
            grid[temp][j] += left[i];
            temp--;
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] -= a[i][j];
        }
    }

    vector<pair<int, pair<int, int>>> v1, v2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i+j) % 2 == n % 2)
            {
                v1.pb(mp(grid[i][j], mp(i, j)));
            }
            else
            {
                v2.pb(mp(grid[i][j], mp(i, j)));
            }
        }
    }

    sort(all(v1));
    sort(all(v2));

    cout << v1[v1.size() - 1].ff + v2[v2.size() - 1].ff << endl;
    cout << v1[v1.size() - 1].ss.ff +1<< " " << v1[v1.size() - 1].ss.ss+1 << " " << v2[v2.size() - 1].ss.ff+1 << " " << v2[v2.size() - 1].ss.ss +1<< endl;
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