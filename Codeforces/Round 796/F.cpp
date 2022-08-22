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

//union_find
void make_set(int parent[],int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

int find_set(int parent[],int v){

    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent,parent[v]);

}

void testcase()
{
    int n,m;
    cin>>n>>m;

    int a[n],b[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];

    int parent[n+1];
    make_set(parent,n+1);

    int prefix1[n+1];

    prefix1[0]=0;
    FOR(i,0,n) prefix1[i+1] = prefix1[i] + a[i];

    int prefix2[n+1];

    prefix2[0]=0;
    FOR(i,0,n) prefix2[i+1] = prefix2[i] + b[i];

    // FOR(i,0,n+1)cout<<prefix1[i]<<" ";
    // cout<<endl;


    while (m)
    {

        int l,r;
        cin>>l>>r;

        if((prefix1[r]-prefix1[l-1])==(prefix2[r]-prefix2[l-1])){
            // cout<<'a';
            for(int v=find_set(parent,l-1);v<r;v=find_set(parent,v)){
                a[v] = b[v];
                prefix1[v+1] = prefix1[v] + a[v];
                parent[v] = v+1;
            }
        }

        m--;
        
    }

    bool equal=true;
    // FOR(i,0,n) cout<<a[i]<<" ";
    // cout<<endl;
    FOR(i,0,n) if(a[i]!=b[i]) equal=false;

    if(equal) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}