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

using namespace std;

// 2 1 3 4 6 5 7 8 10 9
// 3 4 1 6 7 2 8 10 9 7

void testcase()
{
    int n;
    cin>>n;
    int p[n];
    FOR(i,0,n) cin>>p[i];

    vi v;
    FOR(i,0,n) if(p[i]!=i+1) v.pb(i);

    if(v.size()==0) cout<<0<<endl;
    else{
        bool one=true;
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]>1) one=false;
        }
        if(one){
            cout<<1<<endl;
            cout<<v[0]+1<<" "<<v[v.size()-1]+1<<endl;
            for(int i=0;i<n;i++) cout<<i+1<<" ";
            cout<<endl;
        }else{
            if(n==3){
                cout<<2<<endl;
                cout<<1<<" "<<3<<endl;
                cout<<2<<" "<<1<<" "<<3<<endl;
                cout<<1<<" "<<2<<endl;
                cout<<1<<" "<<2<<" "<<3<<endl;
            }else{
                vector<vi> a;
                vi temp;
                int j=0;
                while(j<n){
                    if()
                }
            }

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