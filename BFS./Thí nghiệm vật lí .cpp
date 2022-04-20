#include<bits/stdc++.h>
using namespace std; 
//
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
const int N=1e5+5;
const int oo=1e9;
int n;
vector<ii> a(N);
v check(N,oo);
unordered_map<int,v>d[2];
void process(){
    queue<pair<int,bool>>q;
    q.push({0,1});
    q.push({0,0});
    check[0]=0;
    while(!q.empty()){
        ii u=q.front();  q.pop();
        int dir=u.se? 0:1;
        int id=u.se ? a[u.fi].fi:a[u.fi].se;
        for(int x:d[dir][id]){
            if(check[x]==oo){
                q.push({x,!u.se});
                check[x]=check[u.fi]+1;
            }
        }
    }
    cout<<(check[1]==oo ? -1:check[1]-1);
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n+2;i++){
        cin>>a[i].fi>>a[i].se;
        d[0][a[i].fi].push_back(i);
        d[1][a[i].se].push_back(i);
    }
    process();
    return 0;
}
//
