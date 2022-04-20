#include <bits/stdc++.h>
using namespace std;
/* 𝑴𝒚 𝒄𝒂𝒕 𝒊𝒔 𝒍𝒐𝒐𝒌𝒊𝒏𝒈 𝒂𝒕 𝒚𝒐𝒖 ◉‿◉. */
/* 𝑭𝒆𝒆𝒅 𝒊𝒕 𝒂𝒏𝒅 𝒊𝒕 𝒘𝒊𝒍𝒍 𝒉𝒆𝒍𝒑 𝒚𝒐𝒖 𝒖𝒏𝒅𝒆𝒓𝒔𝒕𝒂𝒏𝒅 𝒕𝒉𝒆 𝒑𝒓𝒐𝒃𝒍𝒆𝒎 (｡◕‿◕｡). */
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒███
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
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n;
int a[N], dd[N], level[N];
bool vis[N];
v List[N];
int dp[N];
/*Main*/
void init()
{
}
void DFS(int u)
{
    if (vis[u])
        return;
    if (List[u].empty())
    {
        vis[u] = 1;
        return;
    }
    vis[u] = 1;
    dd[u] = 1;
    for (auto x : List[u])
    {
        if (!vis[x])
            DFS(x);
        dd[u] += dd[x];
    }
}
int solve(int u)
{
    if (dp[u])
        return dp[u];
    if (List[u].empty())
    {
        dp[u] = 1;
        return 1;
    }
    dp[u] = dd[u];
    for (auto x : List[u])
    {
        dp[u] += solve(x);
    }
    return dp[u];
}
void solution()
{
    cin >> n;
    dd[1] = 1;
    For(i, 2, n)
    {
        cin >> a[i];
        List[a[i]].push_back(i);
        dd[i] = 1;
    }
    DFS(1);
    For(i, 1, n)
    {
        cout << solve(i) << " ";
    }
    cout << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // db start = (db)(clock());
        init();
        solution();
        // db end = (db)(clock());
        // cout << (end - start) / CLOCKS_PER_SEC <<"s"<<endl;
    }
    return 0;
}
/* 𝑴𝒚 𝒄𝒐𝒅𝒆 𝒉𝒂𝒔 𝒆𝒏𝒅𝒆𝒅. */
/* 𝑺𝒆𝒆 𝒚𝒐𝒖 𝒂𝒈𝒂𝒊𝒏 ❤ */
/*
♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪
▄ █ ▄ █ ▄ ▄ █ ▄ █ ▄ █
Min- - - - - - - - - - - -●Max
*/
