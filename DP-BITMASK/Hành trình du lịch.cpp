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
const int N=1e6;
int n,x,last;
int a[25][25];
int dp[N][16];
bool check[N][16];
void reset(){
    last=(1<<n)-1;
    for(int i=1;i<=last;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=INT_MAX;
            check[i][j]=0;
        }
    }
}
void solve(){
    reset();
    queue<ii>q;
    q.push({0,0});
    check[0][0]=1;
    dp[0][0]=0;
    while(!q.empty()){
        ii u=q.front(); q.pop();
        for(int i=1;i<=n;i++){
            int k=1<<(i-1);
            if((u.fi&k)==0){
                x=u.fi^(1<<(i-1));
                dp[x][i]=min(dp[x][i],dp[u.fi][u.se]+a[u.se][i]);
                if(check[x][i]==0){
                    check[x][i]=1;
                    q.push({x,i});
                }
            }
        }
    }
    int ans =*min_element(dp[last]+1,dp[last]+n+1);
    cout<<ans<<endl;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // int d=25&6;
    // cout<<d<<endl;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j];
        }
        solve();
    }
    return 0;
}
//TheEnd
// 11001=2^0+2^3+2^4=25
// 00110=6
