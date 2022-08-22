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
    int b[n];
    FOR(i, 0, n)
    cin >> a[i];
    FOR(i, 0, n)
    cin >> b[i];

    vector<pii> moves;
    bool sorted_a = true;
    FOR(i, 1, n)
    {
        if (a[i] < a[i - 1])
            sorted_a = false;
    }
    if (!sorted_a)
    {
        FOR(i, 0, n)
        {
            FOR(j, i + 1, n)
            {
                if (a[j] < a[i])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    moves.pb({i, j});
                }
            }
        }
    }
    else
    {
        FOR(i, 0, n)
        {
            FOR(j, i + 1, n)
            {
                if (b[j] < b[i])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    moves.pb({i, j});
                }
            }
        }
    }

    bool issorted = true;
    if (!sorted_a)
    {

        FOR(i, 0, n)
        {
            FOR(j, i+1, n)
            {
                if (b[j] < b[i] && a[i] == a[j])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    moves.pb({i, j});
                }
            }
        }
        FOR(i, 1, n)
        {
            if (b[i] < b[i - 1])
                issorted = false;
        }
    }
    else
    {
        FOR(i, 0, n)
        {
            FOR(j, i+1, n)
            {
                if (a[j] < a[i] && b[i] == b[j])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    moves.pb({i, j});
                }
            }
        }
        FOR(i, 1, n)
        {
            if (a[i] < a[i - 1])
                issorted = false;
        }
    }

    if (!issorted)
    {
        cout << -1 << endl;
    }
    else
    {
        if (moves.size() > 0)
        {
            cout << moves.size() << endl;
            for (auto i : moves)
            {
                cout << i.ff + 1 << " " << i.ss + 1 << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
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