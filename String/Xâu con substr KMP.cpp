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
     █▒████▒▒▒▒████n
      █▒███▒██████
*/
#define int long long 
#define ll long long
#define db double
#define fi first 
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e13;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int n,m;
string T,P;
int lps[N];
/*Main*/
void set_LPS(){
    for(int i=2;i<=m;i++){
        int j=lps[i-1];
        while(j>0&&P[j+1]!=P[i])j=lps[j];
        if(P[j+1]==P[i])lps[i]=j+1;
        else lps[i]=0;
    }
}
void KMP_search(){
    int j=0;
    for(int i=1;i<=n;i++){
        while(P[j+1]!=T[i]&&j>0) j=lps[j];
        if(P[j+1]==T[i])j++;
        if(j==m){
            cout<<i-j+1<<" ";
            j=lps[j];
        }
    }
}
void init(){
    memset(lps,0,sizeof(lps));
}
void solution(){
    cin>>T>>P;
    n=T.size(),m=P.size();
    T=" "+T;P=" "+P;
    set_LPS();
    KMP_search();
    cout<<endl;
}
/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	  // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    while(t--){
        init();
        solution();
    }
    return 0;
}
/*THE END*/
