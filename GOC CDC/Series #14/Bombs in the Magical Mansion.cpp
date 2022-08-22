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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        char a[n][n+1];
        FOR(i, 0, n)
        cin >> a[i];

        int grid[n][n];
        FOR(i,0,n){
            FOR(j,0,n) grid[i][j] = -1;
        }

        vector<pii> graph[n][n];
        FOR(i, 0, n)
        {
            FOR(j, 0, n)
            {
                if (i - 1 >= 0)
                {
                    graph[i][j].pb(mp(i - 1, j));
                }
                if (i + 1 < n)
                {
                    graph[i][j].pb(mp(i + 1, j));
                }
                if (j - 1 >= 0)
                {
                    graph[i][j].pb(mp(i, j - 1));
                }
                if (j + 1 < n)
                {
                    graph[i][j].pb(mp(i, j + 1));
                }
            }
        }

        queue<pii> q;
        FOR(i, 0, n)
        {
            FOR(j, 0, n)
            {
                if (a[i][j] == '#')
                {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            pii curr = q.front();
            q.pop();
            // cout<<curr.first<<" "<<curr.second<<endl;

            if(grid[curr.first][curr.second] + 1 <= d) for (const auto &desti : graph[curr.first][curr.second])
            {
                // cout<<desti.first<<" "<<desti.second<<endl;
                if (grid[desti.first][desti.second] == -1)
                {

                    grid[desti.first][desti.second] = grid[curr.first][curr.second] + 1;

                    q.push(desti);
                }
            }
            // cout<<q.size()<<endl;
        }

        FOR(i, 0, n)
        {
            FOR(j, 0, n)
            {
                // cout<<grid[i][j]<<" ";
                if (grid[i][j] > -1 && grid[i][j] <= d)
                {
                    cout << 'x';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << "\n";
        }
    }
}