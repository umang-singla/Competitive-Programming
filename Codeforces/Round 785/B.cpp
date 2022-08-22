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

void testcase(){

    string s;
    cin>>s;

    int n = s.size();


    int b[26] = {0};

    for(auto c:s){
        b[c-'a']++;
    }


    int distinct = 0;

    for(int i=0;i<26;i++){
        if(b[i]>0){
            distinct++;
        }
    }

    if(distinct == n){
        cout<<"YES"<<endl;
    }else{
        string subst = s.substr(0,distinct);
        
        int a[26] = {0};

        for(auto c:subst){
            a[c-'a']++;
        }

        int dist = 0;
        FOR(i,0,26){
            if(a[i]>0){
                dist++;
            }
        }

        if(dist == distinct){
            int i=0,j=0;
            while(i<n){
                j = j%distinct;
                if(s[i]!=subst[j]){
                    cout<<"NO"<<endl;
                    return;
                }
                i++;
                j++;
            }
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        testcase();
    }
}