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
    int n,k;
    cin>>n>>k;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int binary[n][31];

    memset(binary,0,sizeof(binary));

    for(int i=0;i<n;i++){
        int temp = a[i];
        int j = 0;
        while(temp){
            binary[i][j] = temp%2;
            temp/=2;
            j++;
        }
    }

    int bin_sum[31] = {0};

    for(int i=0;i<31;i++){
        for(int j=0;j<n;j++){
            bin_sum[i] += binary[j][i];
        }
    }

    for(int i=30;i>=0;i--){
        if((n - bin_sum[i]) <= k){
            k -= (n - bin_sum[i]);
            bin_sum[i] = n;
        }
    }

    int power = 1;
    int ans = 0;

    for(int i=0;i<31;i++){
        if(bin_sum[i] == n){
            ans += power;
        }
        power *= 2;
    }

    cout<<ans<<endl;
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
