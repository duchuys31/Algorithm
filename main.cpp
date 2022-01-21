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
int dp[105][105];
/*Main*/
void init(){
    memset(dp,0,sizeof(dp));
}
void solution(){
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.size(),m=str2.size();
    for(int i=0;i<=n;i++)dp[0][i]=i;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                dp[i%2][j]=i;
            }
            else if(str1[j-1]==str2[i-1]){
                dp[i%2][j]=dp[(i-1)%2][j-1];
            }
            else{
                dp[i%2][j]=min(dp[(i-1)%2][j],min(dp[i%2][j-1],dp[(i-1)%2][j-1]))+1;
            }
        }
    }
    cout<<dp[m%2][n]<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        init();
        solution();
    }
    return 0;
}
/*THE END*/
