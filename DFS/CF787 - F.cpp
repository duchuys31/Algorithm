#include <bits/stdc++.h>
using namespace std;
/* ๐ด๐ ๐๐๐ ๐๐ ๐๐๐๐๐๐๐ ๐๐ ๐๐๐ โโฟโ. */
/* ๐ญ๐๐๐ ๐๐ ๐๐๐ ๐๐ ๐๐๐๐ ๐๐๐๐ ๐๐๐ ๐๐๐๐๐๐๐๐๐๐ ๐๐๐ ๐๐๐๐๐๐๐ (๏ฝกโโฟโ๏ฝก). */
/*
   โโ          โโ
   โโโ        โโโ
  โโโโโ    โโโโโ
  โโโโโโโโโโโโโ
  โโโโโโโโโโโโโ
  โโโโโโโโโโโโโ
   โโโโโโโโโโโ
  โโโโโโโโโโโโโ      โ
 โโโโโโโโโโโโโโโโ  โโโ
 โโโโโโโโโโโโโโโโ โโโโ
 โโโโโโโโโโโโโโโ โโโโ
  โโโโ=โฒ=โโโโโโโ โโโโ
  โโโโโโฅโโโโโโโโ  โโโโ
    โโโโโโโโโโโ    โโโ
      โโโโโโ        โโโ
       โโโโโโโ      โโ
       โโโโโโโโโโ _โโ
       โโโโโโโโโโโโโ
       โโโโโโโโโโโโโ
     โโโโโโโโโโโโโโ
      โโโโโโโโโโโโ
*/
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> ii;
typedef pair<db, db> dd;
typedef vector<int> v;

const ll oo = 9223372036854775807;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, k, vlad, nastya;
int ans[N], mark[N];
v List[N];
/*Main*/
int DFS(int u, int dad)
{
    int m = mark[u];
    for (auto x : List[u])
    {
        if (x != dad)
            m = max(DFS(x, u), m);
    }
    if (m == 1)
        ans[u] = 2;
    else if (m)
        ans[u] = 1;
    return m;
}
void init()
{
}
void solution()
{
    cin >> n >> k >> vlad >> nastya;
    For(i, 1, n)
    {
        ans[i] = mark[i] = 0;
        List[i].clear();
    }
    For(i, 1, k)
    {
        int x;
        cin >> x;
        mark[x] = 1;
    }
    mark[nastya] = 2;
    For(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        List[u].push_back(v);
        List[v].push_back(u);
    }
    DFS(vlad, 0);
    cout << accumulate(ans + 1, ans + n + 1, -ans[vlad]) << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
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
/* ๐ด๐ ๐๐๐๐ ๐๐๐ ๐๐๐๐๐. */
/* ๐บ๐๐ ๐๐๐ ๐๐๐๐๐ โค */
/*
โซ โช โซ โช โซ โช โซ โช
โ โ โ โ โ โ โ โ โ โ โ
Min- - - - - - - - - - - -โMax
*/
