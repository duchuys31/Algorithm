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
int a[N];
int parent[N];
int find(int i){
    if(parent[i]==i)return i;
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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i]=1;
            parent[i]=i;
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        for(int i=1;i<=n;i++){
            parent[i]=find(parent[i]);
            // cout<<i<<":"<<parent[i]<<endl;
            a[parent[i]]++;
        }
        cout<<*max_element(a+1,a+n+1)-1<<endl;
    }
    return 0;
}
//TheEnd
