#include<bits/stdc++.h>
using namespace std;

vector<int> a,t;

void build(int index,int l,int r){
    if(l==r){
        t[index] = a[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    
    t[index] = t[2*index] + t[2*index+1];
}

void update(int index,int l,int r,int pos,int val){
    if(pos < l || pos > r) return;
    if(l==r){
        t[index] = val;
        a[pos] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*index,l,mid,pos,val);
    update(2*index+1,mid+1,r,pos,val);
    
    t[index] = t[2*index] + t[2*index+1];
}

int query(int index,int l,int r,int ql,int qr){
    
    if(l>qr || r < ql) return 0;
    if(l>=ql && r<=qr) return t[index];
    
    int mid = (l+r)/2;
    
    return query(index*2,l,mid,ql,qr) + query(2*index+1,mid+1,r,ql,qr);
}