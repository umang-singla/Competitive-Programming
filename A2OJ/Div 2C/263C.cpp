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

#define int long long int

using namespace std;

void testcase()
{
    string s;
    cin >> s;

    int cnt = 1;

    string temp = "";
    temp += s[0];

    FOR(i, 1, s.size())
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        if (cnt < 3)
        {
            temp += s[i];
        }
    }

    s = temp;

    vector<pair<char, int>> v;
    FOR(i, 0, s.size())
    {
        if (i == 0)
        {
            v.pb(mp(s[i], 1));
        }
        else if (s[i] == s[i - 1])
        {
            v[v.size() - 1].ss++;
        }
        else
        {
            v.pb(mp(s[i], 1));
        }
    }

    temp = "";

    cnt = 0;

    FOR(i, 0, v[0].ss)
    {
        temp += v[0].ff;
    }

    FOR(i, 1, v.size())
    {
        if (v[i].ss == 2 && v[i - 1].ss == 2)
        {
            cnt++;
            if (cnt % 2)
            {
                temp += v[i].ff;
            }
            else
            {
                temp += v[i].ff;
                temp += v[i].ff;
            }
        }
        else
        {
            cnt = 0;
            FOR(j, 0, v[i].ss)
            {
                temp += v[i].ff;
            }
        }
    }

    cout<<temp<<endl;
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