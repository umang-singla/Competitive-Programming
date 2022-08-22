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
#define vvi vector < vi >
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
    cin>>n;
    int i=0;
    int a[n];
    FOR(i, 0, n)
    {
        cin>>a[i];
    }

    int x;
    cin>>x;

    int binary[n][32];
    memset(binary, 0, sizeof(binary));

    for(int i=0;i<n;i++){
        int j=0;
        while(a[i]>0){
            binary[i][j]=a[i]%2;
            a[i]/=2;
            j++;
        }
    }

    int binary_x[32];
    memset(binary_x, 0, sizeof(binary_x));
    int j=0;
    while(x>0){
        binary_x[j] = x%2;
        x/=2;
        j++;
    }

    vi nv(n,0);

    int power = 1;

    for(int i=0;i<32;i++){
        for(int j=0;j<n;j++){
            if(binary_x[i]==1){
                nv[j] = nv[j] + binary[j][i]*power;
            }
        }
        power*=2;
    }   

    sort(all(nv));


    int ans = n;

    int cnt = 1;
    for(int i=1;i<n;i++){
        if(nv[i]==nv[i-1]){
            cnt++;
        }
        else{
            ans += cnt*(cnt-1);
            cnt = 1;
        }
    }

    if(cnt>1){
        ans += cnt*(cnt-1);
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