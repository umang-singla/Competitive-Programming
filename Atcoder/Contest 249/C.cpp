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

using namespace std;

void testcase()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin>>t;
    // while(t--){
    //     testcase();
    // }
    int n, k;
    cin >> n >> k;

    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int L[26][n];

    memset(L, 0, sizeof(L));

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto c : s[j])
            {
                if (c - 'a' == i)
                {
                    L[i][j] = 1;
                    break;
                }
            }
        }
    }

    int sum[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            sum[i] += L[j][i];
        }
    }

    sort(sum, sum + n);

    cout << sum[n - k] << endl;

    return 0;
}