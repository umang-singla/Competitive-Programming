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
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define int long long int

#define mn 1000000000

using namespace std;

void testcase()
{
    int a,b,k;
    cin>>a>>b>>k;
    int temp_a=a,temp_b=b;

    vi fac_a,fac_b;

    FOR(i,1,sqrt(a)+1){
        if(a%i==0){
            fac_a.pb(i);
            fac_a.pb(a/i);
        }
        
    }

    FOR(i,1,sqrt(b)+1){
        if(b%i==0){
            fac_b.pb(i);
            fac_b.pb(b/i);
        }
    }

    sort(all(fac_a));
    sort(all(fac_b));


    int n_a=0,n_b=0;

    // cout<<'a';

    for(auto f:fac_a){
        if(f==1) continue;
        while (a%f==0)
        {
            n_a++;
            a/=f;
        }        
    }

    for(auto f:fac_b){
        if(f==1) continue;
        while (b%f==0)
        {
            n_b++;
            b/=f;
        }
    }

    int max_op = 0;
    max_op = n_a + n_b;
    // cout<<max_op<<endl;

    if(max_op < k){
        cout<<"NO"<<endl;
        // cout<<'a';
    }
    else{
        if(k>1) cout<<"YES"<<endl;
        else{
            if(temp_a==temp_b) cout<<"NO"<<endl;
            else if(temp_a%temp_b==0||temp_b%temp_a==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}