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
    string s;
    cin>>s;
    string temp = s;

    int ans = 0;
    for(int i=1;i<n;i+=2){
        if(s[i]!=s[i-1]){
            if(i==1){
                s[i] = s[i-1];
            }
            else{
                if(s[i-2]==s[i]){
                    s[i-1] = s[i];
                }else{
                    s[i] = s[i-1];
                }
            }
            // cout<<i<<" ";
            ans++;
        }
    }

    for(int i=1;i<n;i+=2){
        if(temp[i]!=temp[i-1]){
            if(i==1){
                temp[i-1] = temp[i];
            }
            else{
                if(temp[i-2]==temp[i]){
                    temp[i-1] = temp[i];
                }else{
                    temp[i] = temp[i-1];
                }
            }
            // cout<<i<<" ";
        }
    }
    // cout<<temp<<endl;

    int min_seg=1,min_seg2=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            min_seg++;
        }
        if(temp[i]!=temp[i-1]){
            min_seg2++;
        }
    }


    cout<<ans<<" "<<min(min_seg,min_seg2)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;while (t--)
    testcase();
}