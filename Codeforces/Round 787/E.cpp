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
    int n,k;
    cin >> n >> k;
    string s;
    cin>>s;

    if(k>=25){
        for(auto i:s){
            cout<<'a';
        }
        cout<<endl;
    }else{
        if(s[0]-'a'>k){
            char temp = s[0];
            for(int i=0;i<n;i++){
                if(s[i]<=temp&&s[i]>=temp-k){
                    s[i] = temp-k;
                }
            }
            cout<<s<<endl;
        }else if(s[0]-'a'<k){
            int index = -1;
            char temp = s[0];
            for(int i=0;i<n;i++){
                if(s[i]-'a'>k){
                    index = i;
                    break;
                }
            }
            // cout<<index<<" ";
            if(index==-1){
                for(auto i:s){
                    cout<<'a';
                }
                cout<<endl;
            }else{
                int m = 0;
                for(int i=0;i<index;i++){
                    m = max(m,(int)(s[i]-'a'));
                    s[i] = 'a';
                }
                k-=m;
                char temp = s[index];
                for(int i=index;i<n;i++){
                    if(s[i]<=temp&&s[i]>=temp-k){
                        s[i] = temp-k;
                    }
                    if(s[i]-'a'<=m){
                        s[i] = 'a';
                    }
                }
                cout<<s<<endl;
            }
        }else{
            for(int i=0;i<n;i++){
                if(s[i]-'a'<=k){
                    s[i] = 'a';
                }
            }
            cout<<s<<endl;
        }
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