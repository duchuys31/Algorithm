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
const int N=1000111;
const int p=1000000003;
string T,P;
int Pow[N],Hash[N];
int n,m;
void set_pow(){
    Pow[0]=1;
    for(int i=1;i<=m;i++)
        Pow[i]=(Pow[i-1]*26)%p;
}
void set_hash(){
    for(int i=1;i<=m;i++)
        Hash[i]=(Hash[i-1]*26+ T[i]-'a')%p;
}
int get_hash(int i,int j){
    return (Hash[j]-Hash[i-1]*Pow[j-i+1]+p*p)%p;
}
void solution(){
    cin>>T>>P;
    m=T.size(),n=P.size();
    T=" "+T;  P=" "+P;
    set_pow();    set_hash();
    int hash_p=0;
    for(int i=1;i<=n;i++)
        hash_p=(hash_p*26+ P[i]-'a')%p;
    for(int i=1;i<=m-n+1;i++){
        if(hash_p==get_hash(i,i+n-1))cout<<i<<" ";
    }
}
//
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solution();
    return 0;
}
//TheEnd
// 2*3^0=2 + 3 + 18 
