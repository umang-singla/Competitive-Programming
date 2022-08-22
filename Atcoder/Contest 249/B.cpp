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
#define FOR(i, l, r) for (i = l; i < r; ++i)
#define FORr(i, l, r) for (i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof ((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x)((c).find(x) != (c).end())
#define cpresent(c, x)(find(all(c), x) != (c).end())

using namespace std;

// void testcase(){

// }

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;
    // cin>>t;
    // while(t--){
    //     testcase();
    // }

    string s;
    cin>>s;

    int n = s.size();

    bool lower = false,upper=false;

    for(int i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z'){
            lower = true;
        }
        if(s[i]>='A' && s[i]<='Z'){
            upper = true;
        }
    }

    int L[26] = {0},U[26]={0};
    // cout<<'Z'-'A'<<endl;

    for(int i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z'){
            L[s[i]-'a']+=1;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            U[s[i]-'A']+=1;
        }
    }

    bool poss = true;
    for(int i=0;i<26;i++){
        if(L[i]>1 || U[i]>1){
            poss = false;
            break;
        }
    }

    if(poss&&lower&&upper){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}