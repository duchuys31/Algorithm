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
int search(int a[],int x,int left,int right){
    int ans=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]<=x){
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    return ans;
}
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n;
        int l[n+1],h[n+1];
        int sum[n+1]; sum[0]=0;
        int dp[n+1];
        for(int i=1;i<=n;i++)cin>>l[i];
        for(int i=1;i<=n;i++){
            cin>>h[i];
            sum[i]=sum[i-1]+h[i];
        }
        h[0]=INT_MAX;  dp[0]=0; l[0]=-1;
        stack<int>st;
        st.push(0);
        for(int i=1;i<=n;i++){
            while(h[i]>h[st.top()])st.pop();
            int id=st.top();
            dp[i]=dp[id];
            int len=l[i]-l[id]-1;
            int s=len*h[i];
            dp[i]+=s;
            dp[i]-=(sum[i-1]-sum[id]);
            st.push(i);
        }
        // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
        // cout<<endl;
        cin>>q;
        while(q--){
            int u;
            cin>>u;
            int k=lower_bound(dp,dp+n+1,u)-dp;
            if(k==0)cout<<0<<endl;
            else cout<<k-1<<endl;
        }
    }
    return 0;
}
//TheEnd
