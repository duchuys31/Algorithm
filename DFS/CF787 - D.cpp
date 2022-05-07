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
/* 𝑴𝒚 𝒄𝒐𝒅𝒆 𝒉𝒂𝒔 𝒆𝒏𝒅𝒆𝒅. */
/* 𝑺𝒆𝒆 𝒚𝒐𝒖 𝒂𝒈𝒂𝒊𝒏 ❤ */
/*
♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪
▄ █ ▄ █ ▄ ▄ █ ▄ █ ▄ █
Min- - - - - - - - - - - -●Max
*/
