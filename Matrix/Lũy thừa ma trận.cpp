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
const int p=1e9+7;
int n,kk;
struct matrix{
    int d[25][25];
};
matrix tich(matrix a,matrix b){
    matrix ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int s=0;
            for(int k=1;k<=n;k++){
                s=(s%p+a.d[i][k]*b.d[k][j]%p)%p;
            }
            ans.d[i][j]=s;
        }
    }
    return ans;
}
matrix tong(matrix a,matrix b){
    matrix ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans.d[i][j]=(a.d[i][j]+b.d[i][j])%p;
        }
    }
    return ans;
}
matrix pow(matrix a,int p){
    if(p==1)return a;
    matrix ans=pow(a,p/2);
    ans=tich(ans,ans);
    if(p%2==1)ans=tich(ans,a);
    return ans;
}
matrix dv(matrix a,int k){
    int t=1;
    a=pow(a,k);
    while(t<=n){
        a.d[t][t]+=1;
        t+=1;
    }
    return a;
}

matrix luythua(matrix a,int k){
    if(k==1)return a;
    matrix a1=dv(a,k/2);
    matrix a2=luythua(a,k/2);
    matrix ans=tich(a1,a2);
    if(k%2==1){
        matrix b=pow(a,k);
        ans=tong(ans,b);
    }
    return ans;
}

//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>kk;
    matrix a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>a.d[i][j];
    }
    a=luythua(a,kk);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<a.d[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
//TheEnd
