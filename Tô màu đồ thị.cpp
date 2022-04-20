#include <bits/stdc++.h>
using namespace std;
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
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
// #define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)
#define reset(a, val) memset(a, val, sizeof(a));

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 20;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
int n, m, e;
bool ok;
v List[N];
int color[N];
void init()
{
    ok = 1;
    For(i, 1, N) List[i].clear();
    reset(color, 0);
}
void DFS(int u)
{
    set<int> c;
    For(i, 1, e) c.insert(i);
    for (auto x : List[u])
    {
        if (color[x])
            c.erase(x);
    }
    if (c.empty())
    {
        ok = 0;
        return ;
    }
    color[u] = *c.begin();
    for (auto x : List[u])
    {
        if (!color[x])
        {
            DFS(x);
        }
    }
}
void solution()
{
    // db start = (db)(clock());
    cin >> n >> m >> e;
    For(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    DFS(1);
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    // db end = (db)(clock());
    // cout << (end - start) / CLOCKS_PER_SEC <<"s"<<endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin>>t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
