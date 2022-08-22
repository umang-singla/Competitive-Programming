#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        int x[n+1];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i+1];
        }

        int cost = 0;

        x[0] = 0;
        int x1=0,xp=0;
        if(a>b){
            int prefix[n+1];
            prefix[0] = 0;
            for(int i=1;i<=n;i++){
                prefix[i] = prefix[i-1] + x[i];
            }

            cost = INT64_MAX;

            for(int i=0;i<=n;i++){
                cost = min(cost, a*x[i] + b*(prefix[n] - prefix[i] - (n - i - 1)*x[i]));
            }
        }else{
            cost = b*x[1];
            for(int i=2;i<=n;i++){
                cost += a*(x[i-1] - x[i-2]);
                cost += b*(x[i]-x[i-1]);
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}