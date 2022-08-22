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
    int n;
    cin>>n;

    int r[n];
    for(int i=0;i<n;i++) cin>>r[i];

    int mentor[n];
    memset(mentor,-1,sizeof(mentor));

    map<int,int> m;
    for(int i=0;i<n;i++) m[r[i]]++;;

    for(int i=0;i<n;i++){
        auto it = m.upper_bound(2*r[i]);
        if(it!=m.begin()){
            it--;
            if(it->first != r[i]) mentor[i] = it->first;
            else{
                if(it->second > 1) mentor[i] = it->first;
                else{
                    if(it!=m.begin()){
                        it--;
                        mentor[i] = it->first;
                    }
                }
            }
        }
    }

    cout<<"Case #"<<c<<": ";
    for(int i=0;i<n;i++) cout<<mentor[i]<<" ";
    cout<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;
    for(int i=0;i<t;i++)
    testcase(i+1);
}