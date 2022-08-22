#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define int long long int

int **Matrix_k(int **F,int **F1,int d){
    int **temp;

    temp = new int *[d];
    for(int i=0;i<d;i++){
        temp[i] = new int[d];
    }

    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            temp[i][j] = 0;
            for(int k=0;k<d;k++){
                temp[i][j] += F[i][k]*F1[k][j];
            }
        }
    }

    return temp;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f0 = 0, f1 = 1;

    int **F,**F1;

    F = new int *[2];
    F1 = new int *[2];

    for(int i=0;i<2;i++){
        F[i] = new int[2];
        F1[i] = new int[2];
    }

    F[0][0] = 1;
    F[0][1] = 1;
    F[1][0] = 1;
    F[1][1] = 0;

    F1[0][0] = 1;
    F1[0][1] = 1;
    F1[1][0] = 1;
    F1[1][1] = 0;

    int k;
    cin>>k;

    for(int i = 0;i<k-1;i++){
        F1 = Matrix_k(F,F1,2);
    }

    int ans = F1[0][0]*f0 + F1[0][1]*f1;

    cout<<ans;




        

}