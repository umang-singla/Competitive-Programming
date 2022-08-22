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

// #define int long long int

using namespace std;

void testcase(int c)
{
    int n;
    cin>>n;
    string oldp;
    cin>>oldp;
    bool cap=false,small=false,digit=false,special=false;

    FOR(i,0,n){
        if(oldp[i]>='A'&&oldp[i]<='Z') cap=true;
        if(oldp[i]>='a'&&oldp[i]<='z') small=true;
        if(oldp[i]>='0'&&oldp[i]<='9') digit=true;
        if(oldp[i]=='#'||oldp[i]=='@'||oldp[i]=='*'||oldp[i]=='&') special=true;
    }

    if(!cap){
        oldp+='A';
        n++;
    }
    if(!small){
        oldp+='a';
        n++;
    }
    if(!digit){
        oldp+='0';
        n++;
    }
    if(!special){
        oldp+='#';
        n++;
    }
    while(n<7){
        oldp += 'a';
        n++;

    }

    cout<<"Case #"<<c<<": "<<oldp<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;for(int i=0;i<t;i++)
    testcase(i+1);
}