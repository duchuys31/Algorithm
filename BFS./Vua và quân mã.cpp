#include<bits/stdc++.h>
using namespace std; 
//S31[:v]
#define int long long 
#define fi first
#define se second
typedef pair <int,int> ii;
typedef vector<int> v;
typedef vector<vector<int>> vv;
int di[]={-1,0,0,1,-1,-1,1,1};
int dj[]={0,-1,1,0,-1,1,-1,1};
int dima[]={2,2,1,1,-1,-1,-2,-2};
int djma[]={1,-1,2,-2,2,-2,1,-1};
//
struct note{
    ii d;
    int val;
};
ii vua;
vector<ii>ma;
int n;
int a[105][105];
int dvua[105][105];
int dma[105][105];
bool check(ii dd){
    return (dd.fi>0&&dd.fi<=n&&dd.se>0&&dd.se<=n);
}
void BFS(ii src){
    queue<note>q;
    q.push({src,0});
    dvua[src.fi][src.se]=0;
    while(!q.empty()){
        note c=q.front();   q.pop();
        ii id=c.d;
        for(int i=0;i<8;i++){
            ii dd={id.fi+di[i],id.se+dj[i]};
            if(dvua[dd.fi][dd.se]==-1&&a[dd.fi][dd.se]==0&&check(dd)){
                dvua[dd.fi][dd.se]=c.val+1;
                q.push({dd,c.val+1});
            }
        }
    }
}
int BFSma(ii src){
    int ans=INT_MAX;
    queue<note>q;
    q.push({src,0});
    dma[src.fi][src.se]=0;
    if(dvua[src.fi][src.se]!=-1){
        int maxd=max(dma[src.fi][src.se],dvua[src.fi][src.se]);
        ans=min(ans,maxd);
    }
    while(!q.empty()){
        note c=q.front();   q.pop();
        ii id=c.d;
        for(int i=0;i<8;i++){
            ii dd={id.fi+dima[i],id.se+djma[i]};
            if(dma[dd.fi][dd.se]==-1&&a[dd.fi][dd.se]==0&&check(dd)){
                dma[dd.fi][dd.se]=c.val+1;
                if(dvua[dd.fi][dd.se]!=-1){
                    int maxd=max(dma[dd.fi][dd.se],dvua[dd.fi][dd.se]);
                    ans=min(ans,maxd);
                }
                q.push({dd,c.val+1});
            }
        }
    }
    return ans;
}
//
// 
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dvua,-1,sizeof(dvua));
    cin>>n;
    string s[n+1];
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<n;j++){
            if(s[i][j]!='#')a[i][j+1]=0;
            else a[i][j+1]=1;
            if(s[i][j]=='T')vua={i,j+1};
            if(s[i][j]=='M')ma.push_back({i,j+1});
        }
    }
    BFS(vua);
    int ans=INT_MAX;
    for(int i=0;i<ma.size();i++){
        memset(dma,-1,sizeof(dma));
        ans=min(ans,BFSma(ma[i]));
    }
    cout<<ans<<endl;
}
//TheEnd
