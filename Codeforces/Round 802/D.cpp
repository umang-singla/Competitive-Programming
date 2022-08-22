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
    int v[n];
    FOR(i,0,n) cin>>v[i];

    int q;
    cin>>q;

    int time = v[0],overflow = 0;

    int vol = 0;
    FOR(i,0,n) vol += v[i];

    FOR(i,1,n){
        if(v[i]>time){
            v[i] -= time;
            if(v[i]>=overflow){
                v[i] -= overflow;
                overflow = 0;
                time += v[i]/(i+1) + (v[i]%(i+1) > 0);
                if(v[i]%(i+1) > 0) overflow = (i+1) - v[i]%(i+1);
            }else{
                overflow -= v[i];
                v[i] = 0;
            }
        }else{
            overflow += (time-v[i]);
        }
    }

    


    
    while (q--)
    {
        int t;
        cin>>t;

        if(t<time) cout<<-1<<endl;
        else cout<<vol/t + (vol%t != 0)<<endl;

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