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
// #define int long long 
#define ll long long
#define db double
#define fi first 
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e13;
const ll mod=1e15+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
struct matrix{
    ll d[5][5];
};
matrix A,I;
/*Main*/
ll mul(ll x,ll y){
    ll ans=0;
    x%=mod; y%=mod;
    while(y){
        if(y&1)ans=(ans+x)%mod;
        x=(x*2)%mod;
        y/=2;
    }
    return ans;
}
void init(){
    I.d[1][1]=1; I.d[1][2]=1; I.d[1][3]=0; I.d[1][4]=0;
    I.d[2][1]=0; I.d[2][2]=1; I.d[2][3]=1; I.d[2][4]=1;
    I.d[3][1]=0; I.d[3][2]=1; I.d[3][3]=0; I.d[3][4]=0;
    I.d[4][1]=0; I.d[4][2]=0; I.d[4][3]=1; I.d[4][4]=0;
}
matrix operator * (matrix a,matrix b){
    matrix ans;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            ll s=0;
            for(int k=1;k<=4;k++){
                ll val=mul(a.d[i][k],b.d[k][j]);
                s=(s+val)%mod;
            }
            ans.d[i][j]=s;
        }
    }
    return ans;
}
matrix operator ^ (matrix a,ll k){
    if(k==1)return a;
    matrix ans= a ^ (k/2);
    if(k&1)return ans * ans * a;
    return ans * ans;
}
void solution(){
    ll n;
    cin>>n;
    if(n==0)cout<<0<<endl;
    else if(n==1)cout<<1<<endl;
    else if(n==2)cout<<3<<endl;
    else if(n==3)cout<<6<<endl;
    else{
        A=I ^ (n-2);
        cout<<(A.d[1][1]*3+A.d[1][2]*3+A.d[1][3]*2+A.d[1][4])%mod<<endl;
    }
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	  // freopen("output.txt", "w", stdout);
    init();
    int t=1;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
