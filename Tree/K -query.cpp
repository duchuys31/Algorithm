#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
typedef vector<vector<int>> vv;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
const int N=2e5+5;
struct dl{
    int u,v,val,id;
};
int n,q;
dl a[N];
int bit[N],d[N];
void update(int i){
    for(;i<N;i+=i&-i)bit[i]++;
}
int get(int i){
    int ans=0;
    for(;i;i-=i&-i)ans+=bit[i];
    return ans;
}
bool cmp(dl a,dl b){
    return (a.val>b.val || (a.val==b.val&&a.id>b.id));
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].u=a[i].v=i;
        a[i].id=0;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>a[n+i].u>>a[n+i].v>>a[n+i].val;
        a[n+i].id=i;
    }
    sort(a+1,a+n+q+1,cmp);
    for(int i=1;i<=n+q;i++){
        if(a[i].id==0)update(a[i].u);
        else d[a[i].id]=get(a[i].v)-get(a[i].u-1);
    }
    for(int i=1;i<=q;i++)cout<<d[i]<<endl;
    return 0;
}
//TheEnd
