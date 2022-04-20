#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define ll long long
#define db double
#define fi first
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=LONG_LONG_MAX;
const int mod=1e9+7;
const int N=1e4+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
//
int n,m,cnt;
v a[N];
int low[N],num[N],tail[N];
int parent[N];
void tarjan(int u){
    low[u]=num[u]=++cnt;
    for(auto x:a[u]){
        if(x==parent[u])continue;
        if(num[x]){
            low[u]=min(low[u],num[x]);
        }
        else {
            parent[x]=u;
            tarjan(x);
            low[u]=min(low[u],low[x]);
        }
    }
    tail[u]=cnt;
}
int solve1(){
    int ans=0;
    int khop[N]={0},con[N]={0};
    for(int i=1;i<=n;i++){
        int u=parent[i];
        if(u>0)con[u]++;
    }
    for(int i=1;i<=n;i++){
        int u=parent[i];
        if(u>0&&parent[u]>0&&low[i]>=num[u])khop[u]=1;
    }
    for(int i=1;i<=n;i++){
        if(parent[i]==0&&con[i]>=2)khop[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(khop[i]==1)ans++;
    }
    return ans;
}
int solve2(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(parent[i]>0&&low[i]>=num[i])ans++;
    }
    return ans;
}
void solution(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!num[i])tarjan(i);
    }
    cout<<solve1()<<" ";
    cout<<solve2()<<endl;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    solution();
    return 0;
}
//
