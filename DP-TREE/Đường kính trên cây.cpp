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

const ll oo=1e13;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n,ans;
int f[N],g[N];
bool check[N];
v List[N];
void solve(int id)
{
    priority_queue<int>val;
    int sum_f=0,sum_g=0;
    for(auto x:List[id]){
        if(!check[x]){
            check[x]=1;
            solve(x);
            val.push(f[x]);
        }
    }
    if(!val.empty())sum_f+=val.top()+1;
    if(val.size()>=2){
        sum_g+=val.top()+1;
        val.pop();
        sum_g+=val.top()+1;
    }
    f[id]=sum_f;
    g[id]=sum_g;
}
/*Main*/
void init(){
    memset(check,0,sizeof(check));
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));

}
void solution(){
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    ans = -oo;
    check[1]=1;
    solve(1);
    for(int i=1;i<=n;i++)ans=max(ans,max(f[i],g[i]));
    cout << ans << endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	  // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        init();
        solution();
    }
    return 0;
}
/*THE END*/
