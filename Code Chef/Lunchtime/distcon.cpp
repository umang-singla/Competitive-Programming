#include <bits/stdc++.h>
#define mod 1000000007
#define int long long int

using namespace std;

signed main()
{
    int d;
    cin>>d;

    if(d%2==0){
        cout<<0<<" "<<d/2<<endl;
        cout<<0<<" "<<-1*(d/2)<<endl;
        cout<<d/2<<" "<<0<<endl;
        cout<<-1*(d/2)<<" "<<0<<endl;

    }
    else{
        cout<<-1<<endl;
    }

    

    return 0;
}