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
    pii b[n];
    FOR(i, 0, n)
    {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }

    sort(b, b + n);

    int c[n];
    c[0] = a[0] / 2 + a[0] % 2;
    if (a[1] - (c[0]) > 0)
    {
        c[0] += (a[1] - (c[0])) / 2 + (a[1] - (c[0])) % 2;
    }
    if (b[0].ss == 0)
    {
        c[0] = min(c[0], a[0] / 2 + a[0] % 2 + b[1].ff / 2 + b[1].ff % 2);
    }
    else
    {
        c[0] = min(c[0], a[0] / 2 + a[0] % 2 + b[0].ff / 2 + b[0].ff % 2);
    }

    c[0] = min(c[0], (a[0]+a[1])/3+((a[0]+a[1])%3>0));

    // cout<<c[0]<<" ";

    FOR(i, 1, n - 1)
    {
        c[i] = a[i] / 2 + a[i] % 2;
        if (a[i+1] -  (c[i]) > 0)
        {
            c[i] += (a[i+1] - (c[i])) / 2 + (a[i+1] - (c[i])) % 2;
        }

        if(a[i-1] - (a[i] / 2 + a[i] % 2) > 0){
            c[i] = min(c[i], a[i] / 2 + a[i] % 2 + (a[i-1] - (a[i] / 2 + a[i] % 2)) / 2 + (a[i-1] - (a[i] / 2 + a[i] % 2)) % 2);
        }

        if (b[0].ss == i)
        {
            c[i] = min(c[i], a[i] / 2 + a[i] % 2 + b[1].ff / 2 + b[1].ff % 2);
        }
        else
        {
            c[i] = min(c[i], a[i] / 2 + a[i] % 2 + b[0].ff / 2 + b[0].ff % 2);
        }

        c[i] = min(c[i], min(a[i+1],a[i-1]) + (max(a[i+1],a[i-1]) - min(a[i+1],a[i-1])) / 2 + (max(a[i+1],a[i-1]) - min(a[i+1],a[i-1])) % 2);

        c[i] = min(c[i], (a[i]+a[i+1])/3+((a[i]+a[i+1])%3>0));
        c[i] = min(c[i], (a[i]+a[i-1])/3+((a[i]+a[i-1])%3>0));
        // cout<<c[i]<<" ";/
    }

    c[n-1] = a[n-1] / 2 + a[n-1] % 2;
    if (a[n-2] - (c[n-1]) > 0)
    {
        c[n-1] += (a[n-2] - (c[n-1])) / 2 + (a[n-2] -(c[n-1])) % 2;
    }

    cout<<c[n-1]<<" ";

    if(b[0].ss == n-1){
        c[n-1] = min(c[n-1], a[n-1] / 2 + a[n-1] % 2 + b[1].ff / 2 + b[1].ff % 2);
    }else{
        c[n-1] = min(c[n-1], a[n-1] / 2 + a[n-1] % 2 + b[0].ff / 2 + b[0].ff % 2);
    }

    c[n-1] = min(c[n-1], (a[n-1]+a[n-2])/3+((a[n-1]+a[n-2])%3>0));


    sort(c,c+n);

    cout << c[0] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
        testcase();
}