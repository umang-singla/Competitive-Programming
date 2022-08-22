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
    int n,m,k;
    cin>>n>>m>>k;

    int st =1 , ed = n*m;

    while (st<ed)
    {
        int mid = (st+ed+1)/2;

        int cnt = 0;
        for(int i=0;i<n;i++){
            if(mid%(i+1)==0){
                if(mid/(i+1)<=m){
                    cnt+= mid/(i+1);
                    cnt--;
                }else{
                    cnt+= m;
                }
            }else{
                cnt+=min(m,mid/(i+1));
            }
        }

        // cout<<mid<<" "<<cnt<<endl;

        if(cnt< k){
            if(st == mid){
                break;
            }
            st = mid;

        }else{
            ed = mid - 1;
        }
    }

    cout<<st<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--) 
    testcase();
}