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
#define vvi vector< <vi> >
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (i = l; i < r; ++i)
#define FORr(i, l, r) for (i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof ((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())
#define int long long int

using namespace std;

int ones(int n){
    if(n<0) return INT32_MAX;
    int ans=0;
    while(n){
        ans+=n%2;
        n/=2;
    }
    return ans;
}

int solve(vector<int> v,int i,int n){
    if(n==0) return 0;
    else if(i<0 || n<0) return INT32_MAX;
    else{
        // cout<<min(1 + solve(v,i-1,n-v[i]),solve(v,i-1,n))<<" "<<i<<" "<<n<<endl;
        return min(1 + ones(n-v[i]),min(1+solve(v,i-1,n-v[i]),solve(v,i-1,n)));
    }
}

void testcase(){
    int n;
    cin>>n;

    set <int> m;

    int k=6,i=4;

    while(k<=n){
        m.insert(k);
        k=k*i;
        i++;
    }
    
    vector <int> ans;
    for(auto x:m){
        ans.pb(x);
    }
    // cout<<ans.size()<<endl;
    if(n<6) cout<<ones(n)<<endl;
    else cout<<min(ones(n),solve(ans,ans.size()-1,n))<<endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        testcase();
    }
}