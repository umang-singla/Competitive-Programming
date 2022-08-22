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

vector <pii> v;

void make_set(int parent[],int size[],int n){
    FOR(i,0,n)parent[i] = i;
    FOR(i,0,n) size[i] = 0;
}

int find_set(int parent[],int i){
    if(parent[i]==i){
        return i;
    }else{
        return( parent[i] = find_set(parent,parent[i]));
    }
}

void union_sets(int a,int b,int parent[],int size[]){
    int pa = find_set(parent,a);
    int pb = find_set(parent,b);

    if(pa!=pb){
        if(size[pa]>size[pb]){
            parent[pb] = pa;
            size[pa]+=size[pb];
        }else{
            parent[pa] = pb;
            size[pb]+=size[pa];
        }
    }else{
        v.pb({a,b});
    }

}

void testcase()
{
    int n;
    cin>>n;
    int a[n-1],b[n-1];
    FOR(i,0,n-1) cin>>a[i]>>b[i];

    int parent[n],size[n];
    make_set(parent,size,n);

    int graph[n][n];
    memset(graph,0,sizeof(graph));

    FOR(i,0,n-1){
        graph[a[i]-1][b[i]-1]=1;
        graph[b[i]-1][a[i]-1]=1;
        union_sets(a[i]-1,b[i]-1,parent,size);
    }

    set <int> s;
    FOR(i,0,n) s.insert(find_set(parent,i));

    // cout<<s.size();

    if(s.size()>1){

        cout<<s.size()-1<<endl;
        vector<int> temp;
        for(auto c:s) temp.pb(c);
        FOR(i,1,temp.size()){
            cout<<v[i-1].first+1<<" "<<v[i-1].second+1<<" "<<temp[i]+1<<" "<<temp[i-1]+1<<" "<<endl;
        }

    }else{
        cout<<0<<endl;
    }



}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}