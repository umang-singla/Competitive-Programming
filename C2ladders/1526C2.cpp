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

    priority_queue<int, vector<int>, greater<int> > pq;

    int index = n;
    int health = 0;
    FOR(i,0,n){
        if(a[i]>=0){
            index=i;
            break;
        }
    }

    FOR(i,index,n){
        if(a[i]>=0){
            pq.push(a[i]);
            health+=a[i];
        }else{
            if(health+a[i]>=0){
                pq.push(a[i]);
                health += a[i];
            }else{
                if(pq.top()<a[i]){
                    health -= pq.top();
                    pq.pop();
                    pq.push(a[i]);
                    health += a[i];
                }
            }
        }
        // cout<<pq.top()<<" ";
    }

    if(pq.size()>0){
        cout<<pq.size()<<endl;
    }else cout<<0<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}