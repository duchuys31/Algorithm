#include<bits/stdc++.h>
using namespace std; 
//
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
//
const int N=1e5+5;
const int p=1e9+13;
int n,k,ans;
bool ok;
string s;
int Pow[N],Hash[N];
int d[N],f[N];
void set_pow(){
    Pow[0]=1;
    for(int i=1;i<=N;i++)
        Pow[i]=(Pow[i-1]*26)%p;
}
void set_hash(){
    Hash[0]=0;
    for(int i=1;i<=n;i++)
        Hash[i]=(Hash[i-1]*26+ s[i]-'a')%p;
}
int get(int i,int j){
    return (Hash[j]-Hash[i]*Pow[j-i]+p*p)%p;
}
void solution(){
    ans=0;ok=0;
    int left=1,right=n;
    while(left<=right){
        int mid=(left+right)/2;
        for(int i=mid;i<=n;i++){
            d[i]=get(i-mid,i);
        }
        sort(d+mid,d+n+1);
        f[mid]=1;ok=0;
        for(int i=mid+1;i<=n;i++){
            if(d[i]==d[i-1])f[i]=f[i-1]+1;
            else f[i]=1;
            if(f[i]>=k){
                ok=1;
                break;
            }
        }
        if(ok){
            left=mid+1;
            ans=mid;
        }
        else right=mid-1;
    }
    cout<<ans<<endl;
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    set_pow();
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        s=" " + s;
        set_hash(); 
        if(k==1)cout<<n<<endl;
        else solution();
    }
    return 0;
}
//
