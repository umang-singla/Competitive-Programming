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
#define FOR(i, l, r) for (i = l; i < r; ++i)
#define FORr(i, l, r) for (i = l; i >= r; --i)

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
    string s;
    cin>>s;

    vector < string > v;

    string temp = "";

    for(int i=0;i<s.size();i++){
        if(s.at(i)!='W'){
            temp+=s.at(i);
        }else{
            if(temp.length() > 0){
                v.pb(temp);
            }
            temp = "";
        }
    }

    if(temp.length() > 0){
        v.pb(temp);
    }

    bool poss = true;




    for(auto it = v.begin(); it != v.end(); it++){
        bool r=false,b=false;
        if(it->size()==1){
            poss = false;
        }
        for(int i=0;i<it->length();i++){
            if(it->at(i)=='R'){
                r=true;
            }else if(it->at(i)=='B'){
                b=true;
            }
        }
        if(!r || !b){
            poss = false;
        }

        if(!poss){
            break;
        }
    }

    if(poss) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        testcase();
    }
}
