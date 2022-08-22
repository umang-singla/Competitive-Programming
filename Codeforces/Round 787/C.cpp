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
    string s;
    cin>>s;

    int n = s.size();

    if(n==1) cout<<1<<endl;
    else if(s[0]=='0') cout<<1<<endl;
    else if(s[n-1]=='1') cout<<1<<endl;
    else{
        int one=-1,zero=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero = i;
                break;
            }

        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                one = i;
                break;
            }
        }

        int doubt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                if(one !=-1 && zero !=-1 && i>one && i<zero){
                    doubt++;
                }else if(one == -1 && zero !=-1 && i<zero){
                    doubt++;
                }else if(one !=-1 && zero == -1 && i>one){
                    doubt++;
                }else if(one == -1 && zero == -1){
                    doubt++;
                }
            }
        }

        int ans=doubt;
        if(one>=0) ans++;
        if(zero>=0) ans++;

        cout<<ans<<endl;
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