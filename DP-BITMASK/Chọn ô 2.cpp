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
v tmp={0,1,2,4,5,8,9,10};
const int N=1e5+5;
int dp[N][12];
int n;
int a[5][N];
int solve(int k,int s){
    int ans=0;
    for(int i=1;i<=4;i++){
        if(s>>(i-1)&1) ans+=a[i][k];
    }
    return ans;
}
bool check(){
    for(int i=1;i<n;i++){
        if(dp[i][0]!=dp[i+1][0]||dp[i][0]!=0||dp[i+1][0]!=0)return 1;
    }
    return 0;
}
void solution(int max_a){
    for(int x:tmp)dp[1][x]=solve(1,x);
    for(int i=2;i<=n;i++){
        for(int x:tmp){
            int s=solve(i,x);
            dp[i][x]=s;
            for(int k:tmp){
                if((x&k)==0){
                    dp[i][x]=max(dp[i][x],dp[i-1][k]+s);
                }
            }
        }
    }
    int ans=INT_MIN;
    for(int x:tmp)ans=max(ans,dp[n][x]);
    if(check()||(!check&&max_a==0))cout<<ans<<endl;
    else cout<<max_a<<endl;
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int d=INT_MIN;
        cin>>n;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                d=max(d,a[i][j]);
            }
        }
        solution(d);
    }
    return 0;
}
//TheEnd
// 0001 1 x
// 0010 2 x
// 0100 4 x
// 0101 5 x
// 1000 8 x
// 1001 9 x
// 1010 10 x
