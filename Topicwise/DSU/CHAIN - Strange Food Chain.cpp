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
    int parentb = find_set(parent,b);

    if(pa!=parentb){
        if(size[pa]>size[parentb]){
            parent[parentb] = pa;
            size[pa]+=size[parentb];
        }else{
            parent[pa] = parentb;
            size[parentb]+=size[pa];
        }
    }

}

void testcase()
{
    int n,k;
    cin>>n>>k;

    int parent[2*n],size[2*n];

    make_set(parent,size,2*n);


    int ans=0;
    while(k--){
        int q,x,y;
        cin>>q>>x>>y;

        if(q==1){
            if(x<=n&&y<=n){
                if(find_set(parent,x-1+n)==find_set(parent,y-1)||find_set(parent,x-1)==find_set(parent,y-1+n)){
                    ans++;
                }else{
                    union_sets(x-1,y-1,parent,size);
                }
            }else{
                ans++;
            }
        }else{
            if(x<=n&&y<=n){
                if(find_set(parent,x-1)==find_set(parent,y-1)){
                    ans++;
                }else{
                    union_sets(x-1+n,y-1,parent,size);
                }
            }else{
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}