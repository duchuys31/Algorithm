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
int a[N],Tree[4*N],Lazy[4*N];
void build(int node,int l,int r){
    if(l==r)Tree[node]=a[l];
    else {
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);
        Tree[node]=Tree[2*node]+Tree[2*node+1];
    }
}
void update(int node,int l,int r,int left,int right,int val){
    if(Lazy[node]!=0){
        Tree[node]+=(r-l+1)*Lazy[node];
        if(l!=r){
            Lazy[node*2]+=Lazy[node];
            Lazy[node*2+1]+=Lazy[node];
        }
        Lazy[node]=0;
    }
    if(r<left||l>right)return ;
    if(left<=l&&r<=right){
        Tree[node]+=(r-l+1)*val;
        if(l!=r){
            Lazy[node*2]+=val;
            Lazy[node*2+1]+=val;
        }
        return ;
    }
    update(node*2,l,(l+r)/2,left,right,val);
    update(node*2+1,(l+r)/2+1,r,left,right,val);
    Tree[node]=Tree[node*2]+Tree[node*2+1];
}
int get(int node,int l,int r,int left,int right){
    if(l>right||r<left)return 0;
    if(Lazy[node]!=0){
        Tree[node]+=(r-l+1)*Lazy[node];
        if(l!=r){
            Lazy[node*2]+=Lazy[node];
            Lazy[node*2+1]+=Lazy[node];
        }
        Lazy[node]=0;
    }
    if(l>=left&&r<=right)return Tree[node];
    return get(node*2,l,(l+r)/2,left,right)+get(node*2+1,(l+r)/2+1,r,left,right);
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
