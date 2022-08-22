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
#define vvi vector< <vi> >
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof ((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())

#define int long long int

using namespace std;

bool comparator(vi a, vi b) {
    return a.size() <= b.size();
}

void testcase(){

    string s;
    cin>>s;

    int a[10]={0};

    a[0] = 1;
    a[1] = 2;
    FOR(i, 2, 10){
        FOR(j,0,i){
            a[i] += a[j];
        }
        a[i]++;
    }

    int ans = 0;

    bool flag = false;

    FOR(i,0,s.length()){
        int x = s[i]-'0';
        if(x>1){
            flag = true;
        }
        if(x > 0 || flag) ans += a[s.length()-1-i];
    }

    cout<<ans<<endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;
    while(t--){
        testcase();
    }
}