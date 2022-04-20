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
const int p=1000000003;
int n,ans;
string s;
int Pow[N];
int hash_left[N],hash_right[N];
void set_pow(){
    Pow[0]=1;
    for(int i=1;i<=N;i++)
        Pow[i]=(Pow[i-1]*26)%p;
}
void set_left(){
    for(int i=1;i<=n;i++){
        hash_left[i]=(hash_left[i-1]*26+s[i]-'a')%p;
    }
}
void set_right(){
    for(int i=n;i>0;i--){
        hash_right[i]=(hash_right[i+1]*26+s[i]-'a')%p;
    }
}
int get_left(int i,int j){
    return (hash_left[j]-hash_left[i-1]*Pow[j-i+1]+p*p)%p;
}
int get_right(int i,int j){
    return (hash_right[i]-hash_right[j+1]*Pow[j-i+1]+p*p)%p;
}
bool check(int x,int y){
    return (get_left(x,y)==get_right(x,y));
}
void solution(){
    set_left(); set_right();
    for(int i=1;i<=n;i++){
        // le
        int left=0,right=min(i,n-i);
        while(left<=right){
            int mid=(left+right)/2;
            if(check(i-mid+1,i+mid)){
                ans=max(ans,mid*2);
                left=mid+1;
            }
            else right=mid-1;
        }
        // chan
        left=0,right=min(i-1,n-i);
        while(left<=right){
            int mid=(left+right)/2;
            if(check(i-mid,i+mid)){
                ans=max(ans,mid*2+1);
                left=mid+1;
            }
            else right=mid-1;
        }
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
        ans=0;
        cin>>n>>s;
        s=" "+s;
        solution();
    }
    return 0;
}
//
