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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int moves[n] = {0};
    int b[n];
    for (int i = 0; i < n; i++){
        b[i] = 0;
        for(int j=i-1;j>=0;j--){
            b[j] = a[j]*(b[j+1]/a[j] + 1);
            moves[i]+= b[j+1]/a[j] + 1;
        }
        for(int j=i+1;j<n;j++){
            b[j] = a[j]*(b[j-1]/a[j] + 1);
            moves[i]+= b[j-1]/a[j] + 1;
        }
    }

    int ans = INT64_MAX;
    for(int i=0;i<n;i++){
        ans = min(ans, moves[i]);
    }
    cout<<ans<<endl;
}