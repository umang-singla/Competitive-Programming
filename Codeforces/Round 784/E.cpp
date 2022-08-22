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
#define FOR(i, l, r) for (i = l; i < r; ++i)
#define FORr(i, l, r) for (i = l; i >= r; --i)

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
    vector<vector<char>> start, end;

    for (int i = 0; i < 11; i++)
    {
        vector<char> temp;
        start.pb(temp);
        end.pb(temp);
    }

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        start[temp.at(0) - 'a'].push_back(temp.at(1));
        end[temp[temp.size() - 1] - 'a'].push_back(temp.at(0));
    }

    int ans = 0;

    for (int i = 0; i < 11; i++)
    {
        if (!start[i].empty())
        {
            int cnt = 0;
            vector<int> store;

            for (char j = 'a'; j <= 'k'; j++)
            {
                if (count(all(start[i]), j) > 0)
                {
                    store.pb(count(all(start[i]), j));
                }
            }

            if (store.size() > 1)
            {
                for (int j = 0; j < store.size(); j++)
                {
                    for (int k = j + 1; k < store.size(); k++)
                    {
                        cnt += store[j] * store[k];
                    }
                }
            }

            ans += cnt;
        }

        if (!end[i].empty())
        {
            int cnt = 0;
            vector<int> store;


            for (char j = 'a'; j <= 'k'; j++)
            {
                if (count(all(end[i]), j) > 0)
                {
                    store.pb(count(all(end[i]), j));
                }
            }
            if (store.size() > 1)
            {
                for (int j = 0; j < store.size(); j++)
                {
                    for (int k = j + 1; k < store.size(); k++)
                    {
                        cnt += store[j] * store[k];
                    }
                }
            }


            ans += cnt;
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
