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

void testcase(int c)
{
    int n,x,y;
    cin>>n>>x>>y;

    int sum = (n*(n+1))/2;

    if(sum%(x+y) == 0){
        cout<<"Case #"<<c<<": "<<"POSSIBLE"<<endl;
        int temp_x = x*(sum/(x+y));
        int sum=0,size=0;
        vi alan;
        FORr(i,n,1){
            if(sum+i<=temp_x){
                sum += i;
                alan.pb(i);
                size++;
            }
        }
        if(sum<temp_x){
            size++;
            alan.pb(temp_x-sum);
        }
        cout<<size<<"\n";
        sort(all(alan));
        for(auto i:alan){
            cout<<i<<" ";
        }
        cout<<"\n";
        
    }else{
        cout<<"Case #"<<c<<": "<<"IMPOSSIBLE"<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;FOR(i,0,t)
    testcase(i+1);
}