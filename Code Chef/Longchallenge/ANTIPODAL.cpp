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

bool comparator(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    if (a.ff.ff == 0 || b.ff.ss == 0)
        return false;
    else if (a.ff.ss == 0 || b.ff.ff == 0)
        return true;
    else
    {
        if (a.ff.ff < 0 && b.ff.ff < 0)
            return a.ff.ss * b.ff.ff < a.ff.ff * b.ff.ss;
        else if (a.ff.ff < 0)
            return true;
        else if (b.ff.ff < 0)
            return false;
        else
            return a.ff.ss * b.ff.ff < b.ff.ss * a.ff.ff;
    }
}

void testcase()
{
    int n;
    cin >> n;
    pair<int, int> p[n];

    FOR(i, 0, n)
    {
        cin >> p[i].ff >> p[i].ss;
    }

    map<pair<int, int>, int> m[n];

    FOR(i, 0, n)
    {
        m[i][mp(0, 1)] = 0;
        m[i][mp(1, 0)] = 0;
        FOR(j, 0, n)
        {
            if (i != j)
            {
                if (p[i].ff == p[j].ff)
                {
                    m[i][mp(0, 1)]++;
                }
                else if (p[i].ss == p[j].ss)
                {
                    m[i][mp(1, 0)]++;
                }
                else
                {
                    int y = p[j].ss - p[i].ss, x = p[j].ff - p[i].ff;
                    if (y > 0 && x > 0)
                    {
                        m[i][mp(x / __gcd(x, y), y / __gcd(x, y))]++;
                    }
                    else if (y < 0 && x < 0)
                    {
                        m[i][mp(-1 * x / __gcd(-1 * x, -1 * y), -1 * y / __gcd(-1 * x, -1 * y))]++;
                    }
                    else if (y > 0 && x < 0)
                    {
                        m[i][mp(x / __gcd(-1 * x, y), y / __gcd(-1 * x, y))]++;
                    }
                    else
                    {
                        m[i][mp(-1 * x / __gcd(x, -1 * y), -1 * y / __gcd(x, -1 * y))]++;
                    }
                }
            }
        }
    }

    vector<pair<pair<int, int>, int>> v[n];

    for (int k = 0; k < n; k++)
    {
        for (auto i : m[k])
        {
            v[k].pb(mp(i.ff, i.ss));
        }
        sort(all(v[k]), comparator);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int p = 1, q = v[i].size() - 2;
        ans += v[i][q + 1].ss * v[i][0].ss;
        while (p < q)
        {
            if (v[i][q].ff.ff * v[i][p].ff.ff > 0)
                break;
            else
            {
                if (v[i][q].ff.ss * v[i][p].ff.ss + v[i][q].ff.ff * v[i][p].ff.ff == 0)
                {
                    ans += v[i][q].ss * v[i][p].ss;
                    p++;
                    q--;
                }
                else if (v[i][q].ff.ss * v[i][p].ff.ss + v[i][q].ff.ff * v[i][p].ff.ff > 0)
                {
                    q--;
                }
                else
                {
                    p++;
                }
            }
        }
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
    {
        testcase();
    }
}