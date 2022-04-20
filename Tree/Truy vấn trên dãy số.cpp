#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<cstdlib>
#include<time.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y0 asdfasdf
#define y1 fdsafdsa
ll MOD = 1000000007;
const int maxn = 200003;
ll a[maxn], sum[maxn], l[maxn];
vector < ll > r[maxn];
vector < pair < int , int > > toadd;
int n, q;
ll getans(int x)
{
	ll ans = sum[x];
	for (int i = 0; i < (int)toadd.size(); i++)
		if (toadd[i].fst <= x)
		{
			ll y = min(x, toadd[i].snd) - toadd[i].fst + 1;
			ans = (ans + y * (y + 1) * (y + 2) / 3) % MOD;
		}
	return ans;
}

void combine()
{
	for (int i = 0; i < (int)toadd.size(); i++)
	{
		l[toadd[i].fst]++;
		r[toadd[i].snd].pb(toadd[i].snd - toadd[i].fst + 1);
	}
	toadd.clear();
	ll x = 0;
	ll delta = 0;
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += l[i];
		delta += 2 * cnt;
		x += delta;
		a[i] = (a[i] + x) % MOD;
		sum[i] = (sum[i-1] + a[i]) % MOD;
		for (int j = 0; j < (int)r[i].size(); j++)
		{
			cnt--;
			delta -= 2 * r[i][j];
			x -= r[i][j] * (r[i][j] + 1);
		}
		l[i] = 0;
		r[i].clear();
	}
}
int main()
{
	cin >> n >> q;
	int C = 700;
	for (int query = 1; query <= q; query++)
	{
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		if (type == 2)
			printf("%lld\n", (getans(y) - getans(x - 1) + MOD) % MOD);
		else
			toadd.pb(mp(x, y));
		if (query % C == 0)
			combine();
	}
	return 0;
}
