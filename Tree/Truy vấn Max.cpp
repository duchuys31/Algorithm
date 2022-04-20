#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
const int oo=LONG_LONG_MAX;
const int mod=1e9+7;
const int N=1e5+5;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
int n,m;
int a[N],tree[4*N],lazy[4*N];
//
void build(int node,int l,int r){
    if(l==r)tree[node]=a[l];
    else {
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
}
void update(int node,int l,int r,int left,int right,int val){
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(l!=r){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(r<left||l>right)return;
    if(l>=left&&r<=right){
        tree[node]+=val;
        if(l!=r){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return ;
    }
    update(node*2,l,(l+r)/2,left,right,val);
    update(node*2+1,(l+r)/2+1,r,left,right,val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int get(int node,int l,int r,int left,int right){
    if(l>right||r<left)return 0;
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(l!=r){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>=left&&r<=right)return tree[node];
    return max(get(node*2,l,(l+r)/2,left,right),get(node*2+1,(l+r)/2+1,r,left,right));
}
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(m--){
        int key,x,y,val;
        cin>>key>>x>>y;
        if(key==2){
            cin>>val;
            update(1,1,n,x,y,val);
        }
        else cout<<get(1,1,n,x,y)<<endl;
    }
    return 0;
}
//n
