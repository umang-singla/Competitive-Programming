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

#define mod 1000000007

using namespace std;

int len[10][100001],sum[10][100001];

int pow2(int n){
    int ans = 1;
    int fac = 2;
    while(n){
        if(n%2){
            ans = (ans*fac)%mod;
        }
        fac = (fac*fac)%mod;
        n/=2;
    }
    return ans;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < 10; i++)
    {
        len[i][0] = 1;
        len[i][1] = 1;
        len[i][2] = 1;
        sum[i][0] = 0;
        sum[i][1] = i;
        sum[i][2] = i;
    }

    for (int i = 1; i < 10; i++)
    {
        for (int j = 3; j < 100001; j++)
        {
            len[i][j] = (len[i][j - 1] + len[i][j - 2] + len[i][j - 3])%(mod-1);
            sum[i][j] = (sum[i][j - 1] + sum[i][j - 2] + sum[i][j - 3])%(mod);
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        if (n == 0)
        {
            cout << 0 << endl;
        }
        else if (n == 1 || n == 2)
        {
            cout << k << endl;
        }
        else
        {
            int ans = (sum[k][n])%mod;

            int l = len[k][n] - 1;
            // cout<<len<<endl;
            int power = pow2(l);
            // cout<<power;


            ans = (ans*power)%mod;

            cout << ans << endl;
        }
    }
}