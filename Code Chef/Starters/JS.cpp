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
    int a[n];
    int i = 0;
    FOR(i, 0, n)
    {
        cin >> a[i];
    }
    if (a[0] % 2 == a[n - 1] % 2)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] % 2 == a[0] % 2)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    else
    {
        int step[n] = {0};

        int temp = 1,same=0,odd=0;
        for (int i = 1; i < n; i++)
        {
            if(a[i]%2==a[0]%2 && a[i-1]%2 != a[0]%2){
                temp++;
                temp+=odd;
                odd=0;
                same = 0;
            }else if(a[i]%2==a[0]%2 && a[i-1]%2 == a[0]%2){
                odd++;
            }else{
                step[i] = temp + same;
                same++;
            }
        }
        temp = 1;

        for (int i = n - 2; i >= 1; i--)
        {
            if (a[i] % 2 == a[n - 1] % 2)
            {
                step[i] += temp;
                temp++;
            }
        }

        int ans = INT64_MAX;

        for (int i = 1; i < n; i++)
        {
            if (a[i] % 2 != a[0] % 2)
                ans = min(ans, step[i]);
        }

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
    {
        testcase();
    }
}