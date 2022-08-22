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
        int n, m, b;
        cin >> n >> m >> b;

        int w[n], s[n];
        FOR(i, 0, n)
            cin >> w[i];
        FOR(i, 0, n)
            cin >> s[i];

        int graph[n][n + 1];
        FOR(i,0,n){
            FOR(j,0,n+1){
                graph[i][j] = 0;
            }
        }
        // memset(graph, 0, sizeof(graph));
        while (m--)
        {
            int p, q;
            cin >> p >> q;

            graph[p - 1][graph[p - 1][0] + 1] = q - 1;
            graph[p - 1][0]++;
            graph[q - 1][graph[q - 1][0] + 1] = p - 1;
            graph[q - 1][0]++;
        }

        pii v[n + 1];
        FOR(i, 0, n)
        v[i].ff = v[i].ss = 0;

        int visited[n] = {0};

        FOR(i, 0, n)
        {
            if (!visited[i])
            {
                int curr = i;
                int st[n];
                int top = -1;
                st[top + 1] = i;
                top++;
                visited[curr] = 1;
                int wage = 0, skill = 0;
                while (top > -1)
                {
                    int curr = st[top];
                    top--;
                    wage += w[curr];
                    skill += s[curr];
                    for (int j = 1; j < graph[curr][0] + 1; j++)
                    {
                        if (!visited[graph[curr][j]])
                        {
                            st[top + 1] = graph[curr][j];
                            top++;
                            visited[graph[curr][j]] = 1;
                        }
                    }
                }

                v[v[0].ff + 1].ff = wage;
                v[v[0].ff + 1].ss = skill;
                v[0].ff++;
            }
        }

        // cout<<'a';

        n = v[0].ff;

        int **dp = new int *[n];
        FOR(i, 0, n)
        dp[i] = new int[b + 1];

        FOR(i, 0, n)
        {
            FOR(j, 0, b + 1)
            dp[i][j] = 0;
        }

        // cout<<'a';

        FOR(i, 0, b + 1)
        {
            if (v[1].first <= i)
                dp[0][i] = v[1].second;
        }

        // cout<<'a';

        FOR(i, 1, n)
        {
            FOR(j, 0, b + 1)
            {
                if (v[i + 1].ff <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i + 1].ff] + v[i + 1].ss);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        // cout<<'a';

        cout << dp[n - 1][b] << endl;
    }
} 