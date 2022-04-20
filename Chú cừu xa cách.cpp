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
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 101;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
set<ii> st;
int n, k, m;
int ans;
int vis[N][N];
map<ii, bool> fence[N][N];
bool check(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}
void solve(int x, int y)
{
    queue<ii> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        // cout << u.fi << " " << u.se << endl;
        For(i, 0, 3)
        {
            int dx = u.fi + di[i], dy = u.se + dj[i];
            if (check(dx, dy) && !fence[u.fi][u.se][{dx, dy}] && !vis[dx][dy])
            {
                vis[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
    }
    vector<ii> tmp;
    for (auto u : st)
    {
        if (vis[u.fi][u.se])
        {
            tmp.push_back(u);
        }
    }
    for (auto u : tmp)
    {
        st.erase(u);
    }
    ans += tmp.size() * st.size();
    // cout << "ans:" << ans << endl;
}
void init()
{
    ans = 0;
    reset(vis, 0);
}
void solution()
{
    // db start = (db)(clock());
    cin >> n >> k >> m;
    For(i, 1, m)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fence[x1][y1][{x2, y2}] = 1;
        fence[x2][y2][{x1, y1}] = 1;
    }
    vector<ii> tmp;
    For(i, 1, k)
    {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
        tmp.push_back({x, y});
    }
    for (auto x : tmp)
    {
        if (vis[x.fi][x.se])
            continue;
        solve(x.fi, x.se);
        // cout<<endl;
    }
    cout << ans << endl;
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
    // cin>>t;
    while (t--)
    {
        init();
        solution();
    }
    return 0;
}
/*THE END*/
