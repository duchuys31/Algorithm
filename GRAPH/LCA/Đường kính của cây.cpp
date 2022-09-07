
/* Created by Tran Duc Huy */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ll long long
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define in binary_search
#define vec vector
#define pb push_back
#define Pop pop_back
#define rv greater
#define umap unordered_map
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i >= b; i--)
#define lb lower_bound
#define ub upper_bound
#define uniq(a) a.resize(unique(all(a)) - a.begin())
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x)
{
    return out << x.fi << ' ' << x.se;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &x) { return in >> x.fi >> x.se; }
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
istream &operator>>(istream &in, deque<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, deque<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxpq = priority_queue<T, vector<T>>;
template <class A, class B>
using pq = priority_queue<A, vector<A>, B>;

typedef pair<int, int> ii;
typedef pair<int, ii> i_ii;
typedef pair<ii, int> ii_i;
typedef pair<ii, ii> ii_ii;
typedef pair<int, char> ic;
typedef pair<char, int> ci;
typedef pair<int, string> is;
typedef pair<string, int> si;
typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<int> v;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<v> vv;

const int mod = 1e9 + 7;

int _max(int a, int b, int c) { return max(a, max(b, c)); }
int _min(int a, int b, int c) { return min(a, min(b, c)); }

template <typename T>
T random(const T &a, const T &b)
{
    T m = b - a + 1;
    return a + rand() % m;
}
ll to_int(string s)
{
    ll ans = 0;
    for (auto x : s)
        ans = ans * 10 + (x - '0');
    return ans;
}
v compress(v a)
{
    v c = a;
    sort(all(c));
    uniq(c);
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = lb(all(c), a[i]) - c.begin();
    }
    return a;
}
ll power(ll a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            // r *= a;
            r = (r * a) % mod;
        }
        b >>= 1;
        // a *= a;
        a = (a * a) % mod;
    }
    return r;
}
void read(int a[], int n)
{
    For(i, 1, n) cin >> a[i];
}
void print(int a[], int n)
{
    For(i, 1, n) cout << a[i] << " ";
    cout << endl;
}
const ll oo = (ll)1 << 60;
const db PI = 3.14159265358979323846;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, m;
v g[N], id[N], pos[N];
bool vis[N];
int height[N];
v euler, a;

void dfs(int node, int h = 0)
{
    vis[node] = 1;
    height[node] = h;
    euler.pb(node);
    a.pb(height[node]);
    for (auto x : g[node])
    {
        if (vis[x])
            continue;
        dfs(x, h + 1);
        euler.pb(node);
        a.pb(height[node]);
    }
}
void init()
{
    euler.pb(-1);
    a.pb(-1);
    dfs(1);
}
struct Seg
{
    int seg[4 * N];
    void to_set(int x, int n)
    {
        for (int i = 0; i <= 4 * n; i++)
        {
            seg[i] = x;
        }
    }
    int merge(int x, int y)
    {
        return max(x, y);
    }

    int get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u || l > r)
            return -1;
        if (l >= u && r <= v)
        {
            return seg[id];
        }
        int mid = (l + r) >> 1;
        int v1 = get(id << 1, l, mid, u, v);
        int v2 = get(id << 1 | 1, mid + 1, r, u, v);
        return merge(v1, v2);
    }

    void build(int id, int l, int r)
    {
        if (l == r)
        {
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }
};
int left(int it, int start)
{
    int l = 0, r = id[it].size() - 1;
    int k = r;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (id[it][m] >= start)
        {
            k = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return k;
}
int right(int it, int end)
{
    int l = 0, r = id[it].size() - 1;
    int k = l;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (id[it][m] <= end)
        {
            k = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return k;
}
int solve(int x, int l, int r)
{
    int start = left(x, l), end = right(x, r);
    return end - start + 1;
}
Seg T;
/*Main*/
void solution()
{
    cin >> n;
    m = n;
    For(i, 1, n - 1)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    init();
    n = euler.size() - 1;
    For(i, 1, n)
    {
        int k = height[euler[i]];
        id[k].pb(i);
        pos[euler[i]].pb(i);
    }
    T.to_set(-1, n);
    T.build(1, 1, n);
    map<int, int> cnt;
    For(i, 1, m)
    {
        if (pos[i].size() <= 1)
        {
            continue;
        }
        if (pos[i].size() == 2)
        {
            int l = pos[i][0], r = pos[i].back();
            int max_height = T.get(1, 1, n, l + 1, r - 1);
            int len = max_height - height[i];
            cnt[len] += solve(max_height, l, r);
        }
        else
        {
            int l = pos[i][0], r = pos[i].back();
            for (int j = 1; j < pos[i].size() - 1; j++)
            {
                int m = pos[i][j];
                int max_left_height = T.get(1, 1, n, l + 1, m - 1);
                int max_right_height = T.get(1, 1, n, m + 1, r - 1);
                int len = max_left_height + max_right_height - 2 * height[i];
                cnt[len] += solve(max_left_height, l + 1, m - 1) * solve(max_right_height, m + 1, r - 1);
                l = pos[i][j];
            }
        }
    }
    cout << cnt.rbegin()->fi << " " << cnt.rbegin()->se << endl;
}
/**/
main()
{
    FAST;
    int t = 1;
    // cin >> t;
    For(i, 1, t)
    {
        // cout << "#Case " << i << " :\n";
        db start = (db)(clock());
        solution();
        db end = (db)(clock());
        // cout << "Time : " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
