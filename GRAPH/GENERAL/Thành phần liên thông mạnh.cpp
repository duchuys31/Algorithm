#include<bits/stdc++.h>
using namespace std; 
/*S31*/
#define int long long 
#define ll long long
#define db double
#define fi first
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e18;
const int mod=1e9+7;
const int N=1e4+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n,m,cnt,ans;
v a[N];
int low[N],num[N],tail[N],parent[N];
stack<int>st;
void reset(){
    for(int i=1;i<=n;i++){
        low[i]=num[i]=0;
        tail[i]=0;
        parent[i]=0;
        a[i].clear();
    }
    cnt=ans=0;
    while(!st.empty())st.pop();
}
void tarjan(int u){
    low[u]=num[u]=++cnt;
    st.push(u);
    for(auto x:a[u]){
        // if(x==parent[u])continue;
        if(num[x]){
            low[u]=min(low[u],num[x]);
        }
        else{
            parent[x]=u;
            tarjan(x);
            low[u]=min(low[u],low[x]);
        }
    }
    tail[u]=cnt;
    if(num[u]==low[u]){
        ans++;
        int x;
        do{
            x=st.top(); st.pop();
            low[x]=num[x]=oo;
        }while(x!=u);
    }
}
/*main*/
void solution(){
    cin>>n>>m;
    reset();
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        // a[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!num[i])tarjan(i);
    }
    cout<<ans<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
