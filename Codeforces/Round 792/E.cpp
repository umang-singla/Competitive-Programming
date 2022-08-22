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

    int a[n];
    FOR(i, 0, n)
        cin >> a[i];

    sort(a, a + n);

    int diff = 1, mex = 0;
    set<int> s;
    FOR(i, 0, n)
    s.insert(a[i]);

    FOR(i, 0, n)
    {
        if (a[i] == mex)
            mex++;
    }

    diff = s.size();

    int ans = diff - mex;

    map<int, int> m;

    FORr(i, n - 1, 0)
    {
        m[a[i]]++;
    }
    vector<int> one, more;
    for (auto i : s)
    {
        if (m[i] == 1)
            one.push_back(i);
        else
        {
            for (int j = 0; j < m[i] - 1; j++)
            {
                more.pb(i);
            }
        }
    }

    int i = one.size() - 1;

    while (i >= 0 && k)
    {
        if (mex >= one[i])
        {
            break;
        }
        else
        {
            m[mex] = 1;
            m[one[i]] = 0;
            while (m[mex] != 0)
            {
                mex++;
            }
            k--;
            i--;
        }
    }

    i = more.size() - 1;
    while (i >= 0 && k)
    {
        m[mex] = 1;
        // m[more[i]]--;
        while (m[mex] != 0)
        {
            mex++;
        }
        diff++;
        k--;
        i--;
    }

    i = more.size() - 1;
    while (i >= 0 && k)
    {
        if (mex >= one[i])
            break;
        else
        {
            m[mex] = 1;
            // m[more[i]]--;
            while (m[mex] != 0)
            {
                mex++;
            }
            k--;
            i--;
        }
    }

    cout<<diff-mex<<endl;
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