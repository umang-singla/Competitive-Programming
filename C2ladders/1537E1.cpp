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

bool cmp(string a,string b){
    int mod = a.size();
    for(int i=0;i<b.size();i++){
        if(a[i%mod]<b[i]) return true;
        else if(a[i%mod]>b[i]) return false;
    }
    int i=0,index = b.size()%mod;
    while(index<a.size()){
        if(a[index]<a[i]) return true;
        else if(a[index]>a[i]) return false;
        index++;
        i++;
    }
    return false;
}

//dddcdd
//dddcdddddcdd
//dddcdddcdddc


void testcase()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(s[0]=='a'){
        FOR(i,0,k) cout<<'a';
        cout<<endl;
    }else{
        string temp="";

        vector <char> q;
        FORr(i,n-1,0) q.push_back(s[i]);

        while(!q.empty()){
            temp+=q[q.size()-1];
            q.erase(--q.end());

            string temp2="";
            if(q.size()!=0) for(int i=q.size()-1;i>=0;i--){
                temp2+=q[i];
            }

            if(cmp(temp,temp2)) break;
        }

        s = temp;

        int size = s.size();
        while(size<k){
            s = s + s;
            size*=2;
        }

        FOR(i,0,k) cout<<s[i];
        cout<<endl;



    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t;cin >> t;while (t--)
    testcase();
}