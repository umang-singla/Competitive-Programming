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
    int b[n + 1];
    FOR(i, 0, n + 1)
        cin >> b[i];
    if (n % 2)
    {
        int x = b[0];
        FOR(i, 1, n + 1)
        x = x ^ b[i];

        bool done[n + 1] = {0};
        FOR(i, 0, n + 1)
        {
            if (b[i] == x)
            {
                done[i] = 1;
                break;
            }
        }

        FOR(i, 0, n + 1)
        {
            if (!done[i])
                cout << (x ^ b[i]) << " ";
        }
        cout << endl;
    }else{
        int prefix[n+1],suffix[n+1];
        prefix[0] = b[0];
        FOR(i,1,n+1) prefix[i] = prefix[i-1]^b[i];
        suffix[n]= b[n];
        FORr(i,n-1,0) suffix[i] = suffix[i+1]^b[i];

        int index = -1;
        if(suffix[1] == b[0] ) index = 0;
        FOR(i,1,n) if((prefix[i-1]^suffix[i+1]) == b[i]){
            index = i;
        }
        if(prefix[n-1]==b[n]) index = n;

        // cout<<index<<endl;

        FOR(i,0,n+1){
            if(i!=index){
                cout<<(b[index]^b[i])<<" ";
            }
        }
        cout<<endl;
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