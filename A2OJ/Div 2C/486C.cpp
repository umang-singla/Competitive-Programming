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
#define vvi vector << vi >>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define int long long int

#define mod 1000000007

using namespace std;

void testcase()
{

    int n,p;
    cin>>n>>p;

    string s;
    cin>>s;

    int a[n] = {0};

    FOR(i,0,n){
        a[i] = min(abs(26 - abs(s[i]-s[n-1-i])),abs(s[i] - s[n-1-i]));
        // cout<<a[i]<<" ";
    }
    // cout<<endl;

    int ans = 0;

    int mid = n/2;
    int j = -1;
    if(p-1 >= mid){
        for(int i = mid; i < n; i++){
            if(a[i] > 0){
                j = i;
                break;
            }
        }

        // cout<<j<<" ";

        if(j == -1){
            ans = 0;
        }else{
            if(j >= p-1 ){
                for(int i=j;i<n;i++){
                    if(a[i]>0){
                        ans = ans + i - p + 1 + a[i];
                        p = i+1;
                    }
                }
            }else{
                int temp = p-1;
                for(int i=p-1;i>=j;i--){
                    if(a[i] > 0){
                        // cout<<i<<" ";
                        ans = ans + p - 1 - i + a[i];
                        // cout<<ans<<" ";
                        p = i+1;
                    }
                }
                for(int i = temp+1;i<n;i++){
                    if(a[i]>0){
                        // cout<<i<<" ";
                        ans = ans + i - p + 1 + a[i];
                        // cout<<ans<<" ";
                        p = i+1;
                    }
                }

                p=temp+1;
                int ans1=0;
                for(int i=p-1;i<n;i++){
                    if(a[i] > 0){
                        ans1 = ans1 + i - p + 1 + a[i];
                        // cout<<ans1<<" ";
                        p = i+1;
                    }
                }
                for(int i=temp-1;i>=j;i--){
                    if(a[i] > 0){
                        ans1 = ans1 + p - 1 - i + a[i];
                        // cout<<ans1<<" ";
                        p = i+1;
                    }
                }
                ans = min(ans,ans1);
            }
        }
    }else{
        for(int i=mid-1;i>=0;i--){
            // cout<<a[i]<<" ";
            if(a[i]>0){
                j = i;
                break;
            }
        }
        // cout<<j<<endl;
        if(j==-1){
            ans = 0;
        }else{
            if(j >= p-1){
                int temp = p-1;
                for(int i=p-1;i<=j;i++){
                    if(a[i]>0){
                        ans = ans + i - p + 1 + a[i];
                        p = i+1;
                    }
                }
                for(int i=temp-1;i>=0;i--){
                    if(a[i]>0){
                        ans = ans + p - 1 - i + a[i];
                        p = i+1;
                    }
                }

                int ans1=0;
                p = temp+1;
                for(int i=p-1;i>=0;i--){
                    if(a[i]>0){
                        ans1 = ans1 + p - 1 - i + a[i];
                        p = i+1;
                    }
                }
                for(int i=temp+1;i<=j;i++){
                    if(a[i]>0){
                        ans1 = ans1 + i - p + 1 + a[i];
                        p = i+1;
                    }
                }
                ans = min(ans,ans1);
            }else{
                for(int i=j;i>=0;i--){
                    if(a[i]>0){
                        ans = ans + p - 1 - i + a[i];
                        p = i+1;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    while (t--)
    {
        testcase();
    }
}