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
struct matrix{
    int d[3][3];
};
matrix tich(matrix a,matrix b){
    matrix ans;
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            int s=0;
            for(int k=1;k<3;k++){
                s=(s%p+a.d[i][k]*b.d[k][j]%p)%p;
            }
            ans.d[i][j]=s;
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
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        matrix a;
        a.d[1][1]=1;a.d[1][2]=1;
        a.d[2][1]=1;a.d[2][2]=0;
        a=pow(a,n-1);
        cout<<(a.d[1][1]+a.d[1][2])%p<<endl;
    }
    return 0;
}
//TheEnd
