#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int
#define TOTAL 1000000 

using namespace std;

signed main()
{
    int t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        int n;
        cin>>n;
        int s[n];
        for (int i=0;i<n;i++){
            cin>>s[i];
        }

        sort(s,s+n);

        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i]>ans) ans++;
        }

        cout<<"Case #"<<p+1<<": "<<ans<<endl;
    }

    return 0;
}