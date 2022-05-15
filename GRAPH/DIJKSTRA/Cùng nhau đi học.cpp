/* 𝑪𝒓𝒆𝒂𝒕𝒆𝒅 𝒃𝒚 𝑻𝒓𝒂𝒏 𝑫𝒖𝒄 𝑯𝒖𝒚 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

// #define FILE_ON
// #define CLOCK_ON
#define int long long
#define ll long long
// #define db double
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)
#define lb(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define ub(a, x) (upper_bound(all(a), x) - a.begin())
#define uniq(a) a.resize(unique(all(a)) - a.begin())

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> ii;
// typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<int> v;
typedef vector<v> vv;

const ll oo = 9223372036854775807;
// const db PI = 3.14159265358979323846;
const int mod = 1e9 + 7;
const int N = 5e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
struct cmp
{
    bool operator()(ii x, ii y)
    {
        return x.fi >= y.fi;
    }
};
int ans;
int n, m;
int H1, S1, H2, S2;
int da[N], db[N];
vii List[N];
set<int> pa[N], pb[N];
bool visa[N], visb[N];
v waya, wayb;
/*𝑴𝒂𝒊𝒏*/
void Dijkstra_a(int u)
{
    da[u] = 0;
    priority_queue<ii, vector<ii>, cmp> pq;
    pq.push({0, u});
    while (!pq.empty())
    {
        u = pq.top().se;
        pq.pop();
        for (auto x : List[u])
        {
            int d_u_s = x.fi;
            int s = x.se;
            if (da[u] + d_u_s < da[s])
            {
                da[s] = da[u] + d_u_s;
                pq.push({da[s], s});
                pa[s].clear();
                pa[s].insert(u);
            }
            else if (da[u] + d_u_s == da[s])
                pa[s].insert(u);
        }
    }
}
void trace_a(int u)
{
    queue<int> q;
    q.push(u);
    visa[u] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        waya.push_back(u);
        for (auto x : pa[u])
        {
            if (!visa[x])
            {
                visa[x] = 1;
                q.push(x);
            }
        }
    }
}
void Dijkstra_b(int u)
{
    db[u] = 0;
    priority_queue<ii, vector<ii>, cmp> pq;
    pq.push({0, u});
    while (!pq.empty())
    {
        u = pq.top().se;
        pq.pop();
        for (auto x : List[u])
        {
            int d_u_s = x.fi;
            int s = x.se;
            if (db[u] + d_u_s < db[s])
            {
                db[s] = db[u] + d_u_s;
                pq.push({db[s], s});
                pb[s].clear();
                pb[s].insert(u);
            }
            else if (db[u] + d_u_s == db[s])
                pb[s].insert(u);
        }
    }
}
void trace_b(int u)
{
    queue<int> q;
    q.push(u);
    visb[u] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        wayb.push_back(u);
        for (auto x : pb[u])
        {
            if (!visb[x])
            {
                visb[x] = 1;
                q.push(x);
            }
        }
    }
}
void init()
{
    ans = 0;
    waya.clear();
    wayb.clear();
}
void solution()
{
    cin >> n >> m;
    cin >> H1 >> S1 >> H2 >> S2;
    unordered_map<int, int> len[n + 1];
    For(i, 1, n)
    {
        visa[i] = 0;
        visb[i] = 0;
        da[i] = oo;
        db[i] = oo;
        List[i].clear();
        pa[i].clear();
        pb[i].clear();
    }
    For(i, 1, m)
    {
        int x, y, c;
        cin >> x >> y >> c;
        List[x].push_back({c, y});
        List[y].push_back({c, x});
        len[x][y] = c;
        len[y][x] = c;
    }
    Dijkstra_a(H1);
    trace_a(S1);
    sort(all(waya));
    uniq(waya);

    Dijkstra_b(H2);
    trace_b(S2);
    sort(all(wayb));
    uniq(wayb);

    // for (auto x : waya)
    //     cout << x << " ";
    // cout << endl;
    // for (auto x : wayb)
    //     cout << x << " ";
    // cout << endl;

    if (binary_search(all(wayb), S1))
        ans++;
    if (binary_search(all(waya), S2))
        ans++;
    if (S1 == S2)
        ans--;
    for (auto x : waya)
    {
        if (x == S1 || x == S2)
            continue;
        if (binary_search(all(wayb), x) && da[x] == db[x])
        {
            // cout<<x<<endl;
            ans++;
            for (auto i : pa[x])
            {
                if (pb[x].find(i) != pb[x].end())
                {
                    cout << "infinity" << endl;
                    return;
                }
            }
        }
    }
    for (auto x : waya)
    {
        for (auto i : pa[x])
        {
            if (binary_search(all(wayb), i) && pb[i].find(x) != pb[i].end())
            {
                if (abs(da[i] - db[i]) < len[x][i])
                    ans++;
            }
        }
    }
    cout << ans << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef FILE_ON
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    For(i, 1, t)
    {
        // cout << "#Case " << i << " :\n";
        // db start = (db)(clock());
        init();
        solution();
#ifdef CLOCK_ON
        db end = (db)(clock());
        cout << "Time : " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
#endif
    }
    return 0;
}
/*
    𝐆𝐢𝐭𝐡𝐮𝐛: 𝐡𝐭𝐭𝐩𝐬://𝐠𝐢𝐭𝐡𝐮𝐛.𝐜𝐨𝐦/𝐝𝐮𝐜𝐡𝐮𝐲𝐬𝟑𝟏
    𝐅𝐚𝐜𝐞𝐛𝐨𝐨𝐤: 𝐡𝐭𝐭𝐩𝐬://𝐰𝐰𝐰.𝐟𝐚𝐜𝐞𝐛𝐨𝐨𝐤.𝐜𝐨𝐦/𝐭𝐟.𝐡𝐮𝐲𝟐𝟖𝟑𝟗/
    𝐂𝐨𝐝𝐞𝐟𝐨𝐫𝐜𝐞𝐬: 𝐡𝐭𝐭𝐩𝐬://𝐜𝐨𝐝𝐞𝐟𝐨𝐫𝐜𝐞𝐬.𝐜𝐨𝐦/𝐩𝐫𝐨𝐟𝐢𝐥𝐞/𝐡𝐮𝐲𝟑𝟏
*/
