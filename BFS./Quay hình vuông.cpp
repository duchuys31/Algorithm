#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vv;
vv a(2,vector<int>(3));
vv s(2,vector<int>(3));
struct note{
    vv v;
    int d;//cach
};
vv qleft(vv arr){
    vv ans=arr;
    ans[0][0]=arr[1][0];
    ans[0][1]=arr[0][0];
    ans[1][1]=arr[0][1];
    ans[1][0]=arr[1][1];
    return ans;
}
vv qright(vv arr){
    vv ans=arr;
    ans[0][1]=arr[1][1];
    ans[0][2]=arr[0][1];
    ans[1][2]=arr[0][2];
    ans[1][1]=arr[1][2];
    return ans;
}
int main(){
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)cin>>a[i][j];
    
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)cin>>s[i][j];
    queue<note>q;
    note aa={a,0};
    q.push(aa);
    while(!q.empty()){
        note c=q.front();
        q.pop();
        if(c.v==s){
            cout<<c.d;
            return 0;
        }
        vv adj1=qleft(c.v);
        vv adj2=qright(c.v);
        q.push({adj1,c.d+1});
        q.push({adj2,c.d+1});
    }
}
