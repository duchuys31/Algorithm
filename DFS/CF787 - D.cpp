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
int a[N];
int cnt[N];
v List[N];
bool vis[N];
/*Main*/
void DFS(int root)
{
    if (List[root].size() == 0)
    {
        return;
    }
    int Max = 0;
    for (auto x : List[root])
    {
        if (x == root)
            continue;
        DFS(x);
        Max = max(Max, cnt[x] + 1);
    }
    cnt[root] = Max;
}
void init()
{
}
bool ss(int x, int y)
{
    return cnt[x] < cnt[y];
}
void solution()
{
    int root;
    int n;
    cin >> n;
    For(i, 1, n)
    {
        List[i].clear();
        cnt[i] = 0;
        vis[i] = 0;
    }
    For(i, 1, n)
    {
        cin >> a[i];
        if (a[i] != i)
            List[a[i]].push_back(i);
        if (a[i] == i)
            root = i;
    }
    DFS(root);
    vector<ii> tmp;
    For(i, 1, n)
    {
        tmp.push_back({cnt[i], i});
        sort(all(List[i]), ss);
    }
    sort(all(tmp), greater<ii>());
    vector<v> ans;
    int cnt = 0;
    For(i, 0, n - 1)
    {
        if (vis[tmp[i].se])
            continue;
        vis[tmp[i].se] = 1;
        v d;
        d.push_back(tmp[i].se);
        int id = tmp[i].se;
        while (List[id].size())
        {
            int x = List[id].back();
            List[id].pop_back();
            id = x;
            vis[id] = 1;
            d.push_back(id);
        }
        // cout << d.size() << endl;
        // for (auto x : d)
        //     cout << x << " ";
        // cout << endl;
        ans.push_back(d);
        cnt++;
    }
    cout << cnt << endl;
    for (auto d : ans)
    {
        cout << d.size() << endl;
        for (auto x : d)
            cout << x << " ";
        cout << endl;
    }
    cout<<endl;
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
