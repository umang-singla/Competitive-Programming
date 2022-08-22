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
#define vvi vector << vi >>
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

void build(int a[], int v, int tl, int tr,int t[]) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm,t);
        build(a, v*2+1, tm+1, tr,t);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r,int t[]) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm),t)
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r,t);
}

void update(int v, int tl, int tr, int pos, int new_val,int t[]) {
    // cout<<v<<" "<<tl<<" "<<tr<<endl;
    if (tl == tr) {
        // cout<<v<<" ";
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val,t);
        else
            update(v*2+1, tm+1, tr, pos, new_val,t);
        t[v] = t[v*2] & t[v*2+1];
    }
}


void testcase()
{
    int n, q;
    cin >> n >> q;

    int segtree_x[4 * n] = {0};
    int segtree_y[4 * n] = {0};

    while (q--)
    {

        int t;
        cin >> t;
        if (t == 1)
        {

            int x,y;
            cin>>x>>y;

            update(1,0,n-1,x-1,1,segtree_x);
            update(1,0,n-1,y-1,1,segtree_y);      
        }
        else if (t == 2)
        {

            int x,y;
            cin>>x>>y;

            update(1,0,n-1,x-1,0,segtree_x);
            update(1,0,n-1,y-1,0,segtree_y);
            
        }else{


            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;

            // FOR(i,0,10) cout<<segtree_y[i]<<" ";


            if(sum(1,0,n-1,x1-1,x2-1,segtree_x)||sum(1,0,n-1,y1-1,y2-1,segtree_y)){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
        testcase();
}