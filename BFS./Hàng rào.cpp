#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int inf = 1 << 30;
int x[3010], y[3010];
int t[3010];
int compress(int a[3010], int z) 
{
    memcpy(t,a,sizeof(t));
    sort(t,t+z);
    int nz=unique(t,t+z)-t;
    for(int i=0;i<z; i++) 
	{
        a[i]=(lower_bound(t,t+nz,a[i])-t)*2;
    }
    return nz*2;
}
int xz, yz;
char arr[6010][6010];
int gz;
int mx[4]={-1,0,1,0};
int my[4]={0,-1,0,1};
stack<short>sx,sy;
void put(int x, int y) 
{
    if(x<0||x>=xz||y<0||y>=yz) return;
    if(arr[x][y]=='X') return;
	gz+=(arr[x][y]=='C');
    arr[x][y]='X';
    sx.push(x);
    sy.push(y);
}
void dfs(int startx, int starty)
{
    put(startx, starty);
    while(sx.size()) 
	{
        int x=sx.top();sx.pop();
        int y=sy.top();sy.pop();
        for(int i=0;i<4;i++)
		{
            int nx=x+mx[i];
            int ny=y+my[i];
            put(nx,ny);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int z=0;
    x[z]=y[z]=-inf; z++;
    x[z]=y[z]=inf; z++;
    for(int i=0;i<2*n;i++) 
	{
        cin>>x[z]>>y[z]; z++;
    }
    for(int i=0;i<m;i++)
	{
        cin>>x[z]>>y[z]; z++;
    }
    xz=compress(x,z);
    yz=compress(y, z);
    memset(arr,'.',sizeof(arr));
    for (int i=0;i<n;i++) 
	{
        int a=i*2+2;
        int b=i*2+3;
        int x1=x[a],y1=y[a],x2=x[b],y2=y[b];
        if(x1==x2) 
		{
            if(y1>y2) swap(y1, y2);
            while(y1<=y2) 
			{
                arr[x1][y1]='X';
                y1++;
            }
        } 
		else 
		{
            if(x1>x2) swap(x1, x2);
            while(x1<=x2) 
			{
                arr[x1][y1]='X';
                x1++;
            }
        }
    }
    for(int i=0;i<m;i++) 
	{
        int a=i+2*n+2;
        arr[x[a]][y[a]]='C';
    }
    int ans=0;
    for (int i=0;i<m;i++) 
	{
        int a=i+2*n+2;
        gz=0;
        dfs(x[a],y[a]);
        ans=max(ans,gz);
    }
    cout<<ans<<endl;
}
