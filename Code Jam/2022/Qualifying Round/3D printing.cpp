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
        int c[3],m[3],y[3],k[3];

        for (int i=0;i<3;i++){
            cin>>c[i]>>m[i]>>y[i]>>k[i];
        }

        bool poss = true;
        int ans[4] = {0};

        ans[0] = min(c[0],min(c[1],c[2]));
        ans[1] = min(m[0],min(m[1],m[2]));
        ans[2] = min(y[0],min(y[1],y[2]));
        ans[3] = min(k[0],min(k[1],k[2]));

        if(ans[0] + ans[1] + ans[2] + ans[3] >= TOTAL){
            poss = true;
        }
        else{
            poss = false;
        }

        if(poss){
            cout<<"Case #"<<p+1<<": ";
            int temp[4] = {0};
            int k = TOTAL;
            int i =0;
            while(k){
                temp[i] = min(k,ans[i]);
                k-=min(k,ans[i]);
                i++;
            }
            cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<endl;
        }
        else{
            cout<<"Case #"<<p+1<<": IMPOSSIBLE"<<endl;
        }


    }

    return 0;
}