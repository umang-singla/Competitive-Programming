#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pipii pair<int, pii>
#define ff first
#define ss second

class LFUCache {
    
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
    unordered_map<int, pipii> um;
    int sz;
    int cntr;
    
    public:
    LFUCache(int capacity) {
        sz=capacity;
        while(!pq.empty())    
            pq.pop();
        um.clear();
        cntr=0;
    }
    
    int get(int key) {
        if(um.find(key)!=um.end())
        {
            um[key].ss.ff++;
            um[key].ss.ss=++cntr;
            pq.push({{um[key].ss.ff, um[key].ss.ss}, key});
            return um[key].ff;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        
        if(sz==0)
            return;
        
        if(um.find(key)==um.end())
        {
            if(um.size() == sz)
            {
                while(!pq.empty())
                {
                    pair<pii, int> temp = pq.top();
                    pq.pop();
                    
                    if(um.find(temp.ss) == um.end())
                        continue;
                    
                    if(um[temp.ss].ss.ff == temp.ff.ff && um[temp.ss].ss.ss == temp.ff.ss)
                    {
                        um.erase(temp.ss);
                        break;
                    }
                }
            }
            
            um[key]={value, {1, ++cntr}};
        }
        else
        {
            um[key].ff = value;
            um[key].ss.ff++;
            um[key].ss.ss = ++cntr;
        }
        
        pq.push({{um[key].ss.ff, um[key].ss.ss}, key});
    }
};