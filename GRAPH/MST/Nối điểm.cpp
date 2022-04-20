#include<bits/stdc++.h>
using namespace std; 
/*Start*/
#define int long long 
#define ll long long
#define db double
#define fi first
#define se second

typedef pair <db,db> ii;
typedef pair <pair<int,int>,db> iii;

typedef vector<int> v;

const ll oo=1e18;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/

/*main*/
int n;
ii a[N];
vector<iii>List;
int parent[N];
db dd(ii x,ii y){
    ii ans={y.fi-x.fi,y.se-x.se};
    return sqrt(ans.fi*ans.fi+ans.se*ans.se);
}
int find(int i){
    if(parent[i]==-1)return i;
    parent[i]=find(parent[i]);
    return parent[i];
}
bool Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[v] = u;
    return true;
}
bool cmp(iii a,iii b){
    return a.se<b.se;
}
void kruskal(){
    db ans=0;
    sort(List.begin(),List.end(),cmp);
    for(auto x:List){
        if(!Union(x.fi.fi,x.fi.se))continue;
        ans+=x.se;
    }
    printf("%.6lf\n",ans);
}
void solution(){
    memset(parent,-1,sizeof(parent));
    List.clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].fi>>a[i].se;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            List.push_back({{i,j},dd(a[i],a[j])});
        }
    }
    kruskal();
}
/**/
main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
