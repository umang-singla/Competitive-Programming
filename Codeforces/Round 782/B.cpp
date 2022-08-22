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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count[n] = {0};

        int selected = 0;

        if (k % 2 == 0)
        {
            for (int i = 0; i < n && selected < k; i++)
            {
                if (s[i] == '0')
                {
                    count[i] = 1;
                    selected++;
                }
            }
            count[n-1]+=k-selected;
        }
        else{
            for (int i = 0; i < n && selected < k; i++)
            {
                if (s[i] == '1')
                {
                    count[i] = 1;
                    selected++;
                }
            }
            count[n-1]+=k-selected;
        }

        //printing
        for(int i=0;i<n;i++){
            if((k-count[i])%2==0){
                cout<<s[i];
            }
            else{
                if(s[i]=='0'){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<count[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}