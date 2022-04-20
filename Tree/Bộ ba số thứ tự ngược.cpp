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
const int N=1e5+5;
int n;
int bit[N];
void update(int i){
    for(;i<N;i+=i&-i)bit[i]++;
}
int get(int i){
    int ans=0;
    for(;i;i-=i&-i)ans+=bit[i];
    return ans;
}
int ans(int a[]){
    int right[n+1];
    int left[n+1];
    for(int i=n-1;i>=0;i--){
        right[i]=get(a[i]-1);
        update(a[i]);
    }
    for(int i=0;i<=n;i++)bit[i]=0;
    for(int i=0;i<n;i++){
        left[i]=i-get(a[i]);
        update(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=left[i]*right[i];
    }
    return res;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        memset(bit,0,sizeof(bit));
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<ans(a)<<endl;
    }
    return 0;
}
//TheEnd
