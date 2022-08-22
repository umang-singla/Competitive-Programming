#include <bits/stdc++.h>
#define modulo 1000000007
#define int long long int

using namespace std;

bool poss(int x,int a[],int n){
    int b[n+1]={0};
    for(int i=0;i<n;i++){
       if(a[i]%x<=n) b[a[i]%x]++;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0) return false;
    }
    return true;
}

void solve(int S, int a[],int n){

    if(S<0){
        cout<<"NO"<<endl;
        return;
    }
    else if(S==0){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> F;
    for(int i=1;i<sqrt(S)+1;i++){
        if(S%i==0){
            F.push_back(i);
            F.push_back(S/i);
        }
    }

    for(int i=0;i<F.size();i++){
        if(poss(F[i],a,n)){
            cout<<"YES"<<" "<<F[i]<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        bool unique = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                unique = false;
                break;
            }
        }
        if (!unique)
            cout << "NO" << endl;
        else
        {
            int S=0;
            for(int i=0;i<n;i++)
            {
                S+=a[i];
            }
            S = S - (n * (n + 1)) / 2;

            solve(S,a,n);
        }

    }
    return 0;
}