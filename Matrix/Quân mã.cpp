#include<bits/stdc++.h>
#define MAX 100
#define MOD 1000000007
#define clr(ar) memset(ar,0,sizeof(ar))
#define getbit(x,i) (((x)&(1<<(i)))?(1):(0))
using namespace std;
struct Matrix{
	int n,ar[MAX][MAX];
	Matrix()
	{	
	}
	Matrix(int x)
	{
		n=x;
		clr(ar);
	}
};
struct Matrix mul(struct Matrix& A, struct Matrix& B)
{
	int i,j,k,n=A.n;
	struct Matrix C= Matrix(n);
	long long res=0, MODSQ=(long long)MOD*MOD;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0,res=0;k<n;k++)
			{
				res=res+((long long)A.ar[i][k]*B.ar[k][j]);
				if(res>=MODSQ) res-=MODSQ;
			}
			C.ar[i][j]=res%MOD;
		}
	}
	return C;
}
struct Matrix pow(struct Matrix mat, int n)
{
	int c=0;
	struct Matrix res = Matrix(mat.n);
	for(int i=0;i<mat.n;i++)
	{
		res.ar[i][i]=1;
	}
	while(n)
	{
		if(n&1)
		{
			if(!c++)
			{
				res=mat;
			}
			else res=mul(res,mat);
		}
		n>>=1;
		mat=mul(mat,mat);
	}
	return res;
}
int t,m,n,r,num[16][16];
int main()
{
	int i,j,k,x,y,z,u,v,lim,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		memset(num,-1,sizeof(num));
		r=0,lim=1<<m;
		for(x=0;x<lim;x++)
		{
			for(y=0;y<lim;y++)
			{
				flag=1;
				for(i=0;i<m&&flag;i++)
				{
					if(getbit(x,i)&&(i+2)<m&&getbit(y,i+2)) flag=0;
					if(getbit(x,i)&&(i-2)>=0&&getbit(y,i-2)) flag=0;
				}
				if(flag) num[x][y]=r++;
			}
		}
		struct Matrix mat=Matrix(r);
		for(x=0;x<lim;x++)
		{
			for(y=0;y<lim;y++)
			{
				for(z=0;z<lim;z++)
				{
					u=num[x][y],v=num[y][z];
					if(u!=-1&&v!=-1)
					{
						flag=1;
						for(i=0;i<m&&flag;i++)
						{
							if(getbit(x,i)&&(i+1)<m&&getbit(z,i+1)) flag=0;
							if(getbit(x,i)&&(i-1)>=0&&getbit(z,i-1)) flag=0;
						}
						if(flag) mat.ar[u][v]=1;
					}
				}
			}
		}
		long long res=0;
		if(n==1) res=1<<m;
		else{
			mat=pow(mat,n-2);
			for(i=0;i<mat.n;i++)
			{
				for(j=0;j<mat.n;j++)
				{
					res+=mat.ar[i][j];
				}
			}
		}
		printf("%lld\n",res%MOD);
	}
	return 0;
}
