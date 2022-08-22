#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<<vi>>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define FORr(i, l, r) for (int i = l; i >= r; --i)

#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

#define int long long int

using namespace std;

int fd(int &c,char &op,int &k){
    if(op == '+') return c + k;
    else if(op == '-') return c - k;
    else if(op == '*') return c*k;
    else return c/k;
}

queue<pair<pair<int,int>,int>> q,temp;

void testcase(int c)
{
    int n,p,m,ar,ac;
    cin>>n>>p>>m>>ar>>ac;

    char op[4];int k[4];

    for(int i=0;i<4;i++){
        cin>>op[i]>>k[i];
    }

    int ans = 0;
    q.push({{ar-1,ac-1},0});
    for(int i=0;i<m;i++){
        
        while (!q.empty())
        {
            pair<pair<int,int>,int> top = q.front();
            q.pop();
            ans = max(ans,top.ss);
            if(top.ff.ff-1>=1){
                temp.push({{ top.ff.ff-1,top.ff.ss },fd(top.ss,op[0],k[0])});
            }
            if(top.ff.ss-1>=1){
                temp.push({{ top.ff.ff,top.ff.ss-1 },fd(top.ss,op[1],k[1])});
            }if(top.ff.ff+1<=n){
                temp.push({{ top.ff.ff+1,top.ff.ss },fd(top.ss,op[3],k[3])});
            }if(top.ff.ss+1<=n){
                temp.push({{ top.ff.ff,top.ff.ss+1 },fd(top.ss,op[2],k[2])});
            }
        }

        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }

    }

    while (!q.empty())
    {
        pair<pair<int,int>,int> top = q.front();
        q.pop();
        ans = max(ans,top.ss);
    }



    cout<<"Case #"<<c<<": "<<ans<<endl;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin >> t;
    for(int i=0;i<t;i++)
    testcase(i+1);
}