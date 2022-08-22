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
    int a,b,n;
    cin>>a>>b>>n;

    vector<int> v;
    int i=0;
    int power = 1;
    while(a>0||b>0){
        if(a%2!=b%2){
            v.pb(power);
        }
        i++;
        power*=2;
        a/=2;
        b/=2;
    }

    if(v.size()==0){
        cout<<0<<endl;
        return;
    }

    if(v[v.size()-1] >= n) cout<<-1<<endl;
    else{
        n--;

        int cnt = 1;
        int sum = 0;

        for(auto i:v){
            if(sum + (i) > n){
                sum = (i);
                cnt++;
            }else{
                sum += i;
            }
        }

        // cnt++;

        cout<<cnt<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}