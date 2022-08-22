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
    string s,t;
    cin>>s>>t;

    int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0;

    for(int i=0;i<n;i++){
        if(s[i]=='a')a1++;
        if(t[i]=='a')a2++;
        if(s[i]=='b')b1++;
        if(t[i]=='b')b2++;
        if(s[i]=='c')c1++;
        if(t[i]=='c')c2++;
    }

    if(a1!=a2||b1!=b2||c1!=c2){
        cout<<"NO"<<endl;
        return;
    }

    int left[n]={0},right[n]={0};

    set<int> sb;
    if(s[0]=='b') sb.insert(0);
    if(s[0]=='a') left[0]=1;
    for(int i=1;i<n;i++){
        if(s[i]=='b'){
            sb.insert(i);
            if(s[i-1]=='a') left[i] = left[i-1];
            else if(s[i-1]=='b') left[i] = left[i-1];
            else left[i]=0;
        }
        else if(s[i]=='a'){
            left[i] = left[i-1]+1;
        }
        else left[i]=0;
    }

    if(s[n-1]=='c') right[n-1]=1;

    for(int i=n-2;i>=0;i--){
        if(s[i]=='b'){
            // sb.insert(i);
            if(s[i+1]=='c') right[i] = right[i+1];
            else if(s[i+1]=='b') right[i] = right[i+1];
            else right[i]=0;
        }
        else if(s[i]=='c'){
            right[i] = right[i+1]+1;
        }
        else right[i]=0;
    }

    bool poss = true;

    // FOR(i,0,n) cout<<right[i]<<" ";

    for(int i=0;i<n;i++){
        if(t[i]=='b'){
            int it = *sb.begin();
            if(i<it){
                if(it-i>left[it]){
                    poss=false;
                    // cout<<i;
                }else{
                    swap(s[i],s[it]);
                }
            }else{
                if(i-it>right[it]) poss=false;
                else swap(s[i],s[it]);
            }
            sb.erase(it);
        }
    }

    for(int i=0;i<n;i++){
        if((s[i]=='a'&&t[i]=='c')||(s[i]=='c'&&t[i]=='a')) poss=false;
    }

    if(poss) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}