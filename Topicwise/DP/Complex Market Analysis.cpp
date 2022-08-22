#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define int long long int

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}


void test_case(){
    int n,e;
    cin>>n>>e;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int ans =0;

    int i =0;

    int dp[n] = {0};

    for(int i=0;i<n;i++){
        if(isPrime(a[i])){
            dp[i] = 0;
            int k = i+e;
            int p1=0,p2=0;
            while(k<n&&a[k]==1){
                p1++;
                dp[k] += 1 + dp[k-e];
                k+=e;
            }
            int j=i-e;
            while(j>=0&&a[j]==1){
                p2++;
                //ans++;
                j-=e;
            }

            ans += p2*(p1+1) + p1;
            
        }
    }

    cout<<ans<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        test_case();
    }
    

}