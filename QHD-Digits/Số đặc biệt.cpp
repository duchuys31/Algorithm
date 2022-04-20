#include<bits/stdc++.h>
using namespace std; 
/*S31*/
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
string s;
int n;
int dp[20][4][150][150]={0};
int digits[20]={0};
bool isprime(int x){
    if(x<2)return 0;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
/*main*/
int solve(int i,int rem,int sumx,int sumy){
    int ans=0;
    if(i==-1){
        if(rem==0&&isprime(sumx)&&isprime(sumy))return 1;
        return 0;
    }
    if(dp[i][rem][sumx][sumy]!=-1)return dp[i][rem][sumx][sumy];
    int tmp=0;
    for(int x=0;x<=9;x++)
    for(int y=0;y<=9;y++){
        int t=x+2*y+rem;
        if(t%10==digits[i]){
            tmp+=solve(i-1,t/10,sumx+x,sumy+y);
        }
    }
    return dp[i][rem][sumx][sumy]=tmp;
}
void solution(){
    memset(dp,-1,sizeof(dp));
    cin>>s; n=s.size();
    for(int i=0;i<n;i++)digits[i]=s[i]-'0';
    cout<<solve(n-1,0,0,0)<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
