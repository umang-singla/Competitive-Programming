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
    int n, m;
    cin >> n >> m;

    char grid[n][m+1];
    for (int i = 0; i < n; i++)
    {
        cin>>grid[i];
    }

    char ans[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] = '.';
        }
    }


    for (int i = 0; i < m; i++)
    {
        int k = n - 1;

        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[j][i] == '*')
            {
                ans[k][i] = grid[j][i];
                k--;
            }else if(grid[j][i] == 'o'){
                ans[j][i] = grid[j][i];
                k = j-1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout<<endl;
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
