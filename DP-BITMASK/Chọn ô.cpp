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
const int N=2000000;
int n;
int a[25][25];
int dp[N];
void solve(){
    int last=(1<<n)-1;
    memset(dp,0,sizeof(dp));
    for(int s=0;s<=last;s++){
        int count = 0;
        for(int i=1;i<=n;i++)if(s>>(i-1)&1)count++;
        for(int i=1;i<=n;i++){
            if(s>>(i-1)&1){
                int p=s xor (1<<(i-1));
                dp[s]=max(dp[s],dp[p]+a[count][i]);
            }
        }
    }
    cout<<dp[last]<<endl;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
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
