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

bool isPalindrome(int n){
    int temp = n;
    vector <int> v;
    while(temp){
        v.pb(temp%10);
        temp/=10;
    }

    bool pal = true;
    FOR(i, 0, v.size()/2){
        if(v[i] != v[v.size()-i-1]){
            pal = false;
            break;
        }
    }

    return pal;
}

void testcase(int c){
    int a;
    cin>>a;

    int ans = 0;

    set <int> s;

    for(int i=1;i<=sqrt(a);i++){
        if(a%i == 0){
            s.insert(i);
            s.insert(a/i);
        }
    }

    for(auto i:s){
        if(isPalindrome(i)){
            ans++;
        }
    }

    
    cout<<"Case #"<<c+1<<": "<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    FOR(i, 0, t){
        testcase(i);
    }
}