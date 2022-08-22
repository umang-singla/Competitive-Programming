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

    pii a[n];
    FOR(i,0,n){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a, a+n);

    // FOR(i,0,n) cout<<a[i].ff<<" "<<a[i].ss<<endl;

    bool poss = true;
    if(n%2){
        if(a[0].second !=0){
            poss = false;
        }
        FOR(i,1,n){
            if(i%2){
                if(a[i].second == i || a[i].second==i+1){
                    continue;
                }else{
                    poss = false;
                    break;
                }
            }else{
                if(a[i].second == i || a[i].second==i-1){
                    continue;
                }else{
                    poss = false;
                    break;
                }
            }
        }
    }else{
        FOR(i,0,n){
            if(i%2==0){
                if(a[i].second == i || a[i].second==i+1){
                    continue;
                }else{
                    poss = false;
                    break;
                }
            }else{
                if(a[i].second == i || a[i].second==i-1){
                    continue;
                }else{
                    poss = false;
                    break;
                }
            }
        }
    }

    if(poss){
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
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