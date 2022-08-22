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

void testcase()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    if(x>a){
        x -= a;
        if(c<x){
            cout<<"NO"<<endl;
            return;
        }else{
            c -= x;
            x = 0;
        }

    }

    if(y > b){
        y -= b;
        if(c<y){
            cout<<"NO"<<endl;
            return;
        }else{
            c -= y;
            y = 0;
        }
    }

    cout<<"YES"<<endl;
    return;

    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}