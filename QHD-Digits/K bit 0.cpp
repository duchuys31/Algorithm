#include<bits/stdc++.h>
using namespace std; 
/*S31*/
// #define int long long 
#define ll long long
#define db double
#define fi first
#define se second

typedef pair <int,int> ii;
typedef vector<int> v;

const ll oo=1e18;
const int mod=1e9+7;
const int N=1e6+5;

int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
/**/
int k;
v convert(int n){
    v bit;
    while(n>0){
        bit.push_back(n%2);
        n/=2;
    }
    reverse(bit.begin(),bit.end());
    return bit;
}
int n;
/*main*/
void solve1(){
    int ans=0;
    if(k==1)ans++;
    for(int i=1;i<=n;i++){
        v bit=convert(i);
        int cnt=0;
        for(int i=0;i<bit.size();i++){
            if(bit[i]==0)cnt++;
        }
            if(cnt==k)ans++;
    }
    cout<<ans<<endl;
}

void solve2(){
    v bit=convert(n);
    // if(n==0)bit.push_back(0);
    if(n==0&&k==1){
        cout<<1<<endl;
        return ;
    }
    int len=bit.size();
    // cout<<len<<endl;
     bit.insert(bit.begin(),-1);
    ll dp[len+1][2][k+2][2];
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    for(int i=0;i<len;i++){
        for(int islower=0;islower<2;islower++){
            for(int kk=0;kk<=k;kk++){
                for(int pos=0;pos<=1;pos++){
                    for(int digit=0;digit<=1;digit++){
                        if(islower==0&&digit>bit[i+1])continue;
                        int newk;
                        if(digit==0&&pos>0)newk=kk+1;
                        else newk=kk;
                        int newpos=0;
                        if(digit==1||pos==1){
                            newpos=1;
                        }
                        int newislower=0;
                        if(islower==1)newislower=1;
                        else if(digit<bit[i+1])newislower=1;
                        dp[i+1][newislower][newk][newpos]+=dp[i][islower][kk][pos];
                        // cout<<i<<" "<<kk<<" "<<newk<<endl;
                    }
                }
            }
        }
    }
    cout<<dp[len][0][k][1]+dp[len][1][k][1]<<endl;
}
void solution(){
    cin>>n>>k;
    int d=n;
    // v bit=convert(d);
    // len=bit.size();
    // cout<<len<<endl;
    // solve1();
    // cout<<endl;
    solve2();

}

/**/
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
/*THE END*/
