#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        if(n>m) cout<<"NO"<<endl;
        else{
            int req_chair = 0;
            req_chair = 2*a[n-1] +1;
            for(int i=n-2;i>=0;i--){
                req_chair += a[i] + 1;
            }
            req_chair -= a[0];
            if(req_chair>m) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}