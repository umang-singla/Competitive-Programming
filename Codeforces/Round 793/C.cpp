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
    int n;
    cin>>n;
    int a[n];
    FOR(i,0,n) cin>>a[i];

    sort(a,a+n);

    int p[n];

    map <int,int> m;
    FOR(i,0,n) m[a[i]]++;
    set <int> s;
    FOR(i,0,n) s.insert(a[i]);
    int lis1=0,lis2=0;
    vi one;
    bool odd=true;
    for(auto i:s){
        if(m[i]>1){
            lis1++;
            lis2++;
        }else{
            one.pb(i);
        }
    }

    int size = 0;
    if(one.size()>0) size = one.size();

    lis1 += size/2 + size%2;
    lis2 += size/2 + size%2;

    cout<<min(lis1,lis2)<<endl;

    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}