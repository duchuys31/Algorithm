#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
int n;
const int p=1e9+7;
int nCr[55][55];
struct matrix{
    int d[55][55];
};
matrix tich(matrix a,matrix b,int dd){
    matrix ans;
    for(int i=0;i<=dd+1;i++){
        for(int j=0;j<=dd+1;j++){
            int s=0;
            for(int k=0;k<=dd+1;k++){
                s=(s%p+a.d[i][k]*b.d[k][j]%p)%p;
            }
            ans.d[i][j]=s;
        }
    }
    return ans;
}
matrix powmatrix(matrix a,int k,int dd){
    if(k==1)return a;
    matrix ans=powmatrix(a,k/2,dd);
    ans=tich(ans,ans,dd);
    if(k%2==1)ans=tich(ans,a,dd);
    return ans;
}
void ncr(){
    int k;
    for(int i=0;i<=50;i++){
        nCr[i][0] = 1;
        nCr[i][i] = 1;
        k = i >> 1;
        for(int j=1;j<=k;j++){
            nCr[i][j] = nCr[i][i-j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % p;
        }
    }
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ncr();
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>n>>k;
        matrix a;
        memset(a.d,0,sizeof(a.d));
        for(int i=0;i<=k;i++){
            for(int j=0;j<=i;j++){
                a.d[i][j]=nCr[i][j];
            }
        }
        for(int i=0;i<=k;i++)a.d[k+1][i]=a.d[k][i];
        a.d[k+1][k+1]=1;
        matrix res=powmatrix(a,n-1,k);
        // for(int i=0;i<=k+1;i++){
        //     for(int j=0;j<=k+1;j++){
        //         cout<<a.d[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // matrix res=powmatrix(a,k-1);
        int ans=0;
        for(int i=0;i<=k+1;i++){
            ans=(ans+res.d[k+1][i])%p;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//TheEnd
