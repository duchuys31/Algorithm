#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
//
const int N=1e5+5;
int parent[N];
int find(int i){
    if(parent[i]==-1)return i;
    parent[i]=find(parent[i]);
    return parent[i];
}
void Union(int x,int y){
    int p_a=find(x);
    int p_b=find(y);
    if(p_a!=p_b)parent[p_a]=p_b;
}
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(parent,-1,sizeof(parent));
    int t;
    cin>>t;
    while(t--){
        int x,y,d;
        cin>>x>>y>>d;
        if(d==1)Union(x,y);
        else{
            int p_x=find(x);
            int p_y=find(y);
            if(p_x==p_y)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
//TheEnd
