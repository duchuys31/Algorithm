#include<bits/stdc++.h>
using namespace std;
struct note{
    string u;
    int d;
};
string arr="";
string qleft(string q){
    string ans=q;
    ans[1]=q[0];
    ans[5]=q[1];
    ans[8]=q[5];
    ans[7]=q[8];
    ans[3]=q[7];
    ans[0]=q[3];
    return ans;
}
string qleft1(string q){
    string ans=q;
    ans[0]=q[1];
    ans[1]=q[5];
    ans[5]=q[8];
    ans[8]=q[7];
    ans[7]=q[3];
    ans[3]=q[0];
    return ans;
}
string qright(string q){
    string ans=q;
    ans[2]=q[1];
    ans[6]=q[2];
    ans[9]=q[6];
    ans[8]=q[9];
    ans[4]=q[8];
    ans[1]=q[4];
    return ans;
}
string qright1(string q){
    string ans=q;
    ans[1]=q[2];
    ans[2]=q[6];
    ans[6]=q[9];
    ans[9]=q[8];
    ans[8]=q[4];
    ans[4]=q[1];
    return ans;
}
unordered_map<string,int>check1;
unordered_map<string,int>check2;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int ans=INT_MAX;
    int x;
    for(int i=0;i<10;i++){
        cin>>x;
        arr=arr+to_string(x);
    }
    string s="1238004765";
    queue<note>q;
    q.push({arr,0});
    check1[arr]=1;
    while(!q.empty()){
        note c=q.front();
        q.pop();
        if(c.d==13)continue;
        string adj1=qleft(c.u);
        string adj2=qright(c.u);
        if(check1[adj1]==0){
            q.push({adj1,c.d+1});
            check1[adj1]=c.d+1;
        }
        if(check1[adj2]==0){
            q.push({adj2,c.d+1});
            check1[adj2]=c.d+1;
        }
    }
    q.push({s,0});
    check2[s]=1;
    while(!q.empty()){
        note c=q.front();
        q.pop();
        if(check1[c.u]!=0){
            ans=min(ans,check1[c.u]+c.d);
        }
        if(c.d==13)continue;
        string adj1=qleft1(c.u);
        string adj2=qright1(c.u);
        if(check2[adj1]==0){
            q.push({adj1,c.d+1});
            check2[adj1]=c.d+1;
        }
        if(check2[adj2]==0){
            q.push({adj2,c.d+1});
            check2[adj2]=c.d+1;
        }
    }
    cout<<ans;
}
