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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
        cout << 0 << endl;
    else
    {

        map<int, int> m;
        for (int i = 0; i < n; i++)
            if (m.find(a[i]) == m.end())
                m[a[i]] = i;

        set<int> s;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (i < n-1 && a[i] > a[i + 1])
                index = i;

            if (m[a[i]] <= index)
            {
                index = i;
            }
        }

        for (int i = 0; i <= index; i++)
            s.insert(a[i]);

        int ans = s.size();

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
        testcase();
}