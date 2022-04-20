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
typedef pair<db, db> dd;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
struct note
{
    int u, v;
    db w;
    note(int a, int b, db c)
    {
        this->u = a;
        this->v = b;
        this->w = c;
    }
};
int n;
int dad[N];
int find(int i)
{
    if (dad[i] == -1)
        return i;
    dad[i] = find(dad[i]);
    return dad[i];
}
bool Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return 0;
    }
    dad[v] = u;
    return 1;
}
dd a[N];
vector<note> edge;
bool cmp(note x, note y)
{
    return x.w < y.w;
}
/*Main*/
void init()
{
    edge.clear();
    reset(dad, -1);
}
db cal_d(dd x, dd y)
{
    dd ans = {y.fi - x.fi, y.se - x.se};
    return sqrt(ans.fi * ans.fi + ans.se * ans.se);
}
void solution()
{
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i].fi >> a[i].se;
    }
    For(i, 1, n)
    {
        For(j, i + 1, n)
        {
            edge.push_back(note(i, j, cal_d(a[i], a[j])));
            // cout<<cal_d(a[i],a[j])<<endl;
        }
    }
    db ans = 0;
    sort(edge.begin(), edge.end(), cmp);
    for (auto x : edge)
    {
        if (!Union(x.u, x.v))
            continue;
        ans += x.w;
    }
    printf("%.6lf\n", ans);
    // cout << endl;
}
/**/
main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
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
