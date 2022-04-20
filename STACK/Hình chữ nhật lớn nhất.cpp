#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
//
const int N=1e6+5;


void solve(int a[],int n){
    int left[n+2],right[n+2];
    // cout<<1<<endl;
    for(int i=1;i<=n;i++){
        left[i]=i;
        while(a[left[i]-1]>=a[i])left[i]=left[left[i]-1];
    }
    // cout<<1<<endl;
    for(int i=n;i>=1;i--){
        right[i]=i;
        while(a[right[i]+1]>=a[i])right[i]=right[right[i]+1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]*(right[i]-left[i]+1));
    }
    cout<<ans<<endl;
}
void solution(){
    int n;
    cin>>n;
    int a[n+2];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=a[n+1]=-1;
    solve(a,n);
}
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt","r", stdin);
	// freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solution();
    }
}
//TheEnd
