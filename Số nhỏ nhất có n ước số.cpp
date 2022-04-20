#include<bits/stdc++.h>
using namespace std; 
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long 
#define ll long long
#define db double
#define fi first 
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e18;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
v e={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,ans;
/*Main*/
void init(){
    ans=oo;
}
void DFS(int now,int cur,int cnt){
    if(cnt>n||cur>15)return ;
    if(cnt==n){
        ans=min (ans,now);
        return ;
    }
    for(int i=1;i<=64;i++){
        now=now*e[cur];
        if(now>ans)break;
        DFS(now,cur+1,cnt*(i+1));
    }

}
void solution(){
    cin>>n;
    DFS(1,0,1);
    cout<<ans<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	  // freopen("output.txt", "w", stdout);
    //   cout<<e.size()<<endl;
    int t=1;
    cin>>t;
    while(t--){
        init();
        solution();
    }
    return 0;
}
/*THE END*/
