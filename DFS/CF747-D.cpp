
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
umap<T, int> compress(const vector<T> &u)
{
    vector<T> sorted = u;
    sort(all(sorted));
    int l = sorted.size();
    umap<T, int> m;
    for (int i = 0; i < l; i++)
        m[sorted[i]] = i;
    return m;
}
template <typename T>
T power(T a, int b)
{
    assert(b >= 0);
    T r = 1;
    while (b)
    {
        if (b & 1)
        {
            r *= a;
            // r = (r * a) % mod;
        }
        b >>= 1;
        a *= a;
        // a = (a * a) % mod;
    }
    return r;
}
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
typedef vector<v> vv;

int __lcm(int a, int b) { return a / __gcd(a, b) * b; }
int _max(int a, int b, int c) { return max(a, max(b, c)); }
int _min(int a, int b, int c) { return min(a, min(b, c)); }

template <typename T>
T random(const T &a, const T &b)
{
    T m = b - a + 1;
    return a + rand() % m;
}
string join(const vector<string> &vec, const string &t)
{
    int l = vec.size();
    string s;
    for (int i = 0; i < l; i++)
    {
        s += vec[i];
        if (i != l - 1)
            s += t;
    }
    return s;
}
ll to_int(string s)
{
    ll ans = 0;
    for (auto x : s)
        ans = ans * 10 + (x - '0');
    return ans;
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
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
vii g[N];
int fac[N];
int n, m;
bool flag;
int p1, p2;
void dfs(int u, int p)
{
    for (auto x : g[u])
    {
        int obs = x.fi, type = x.se;
        if (fac[obs] && fac[u] * type != fac[obs])
            flag = 1;
        if (!fac[obs])
        {
            type *= p;
            if (type == 1)
                p1++;
            else
                p2++;
            fac[obs] = type;
            dfs(obs, type);
        }
    }
}
/*Main*/
void init()
{

    flag = 0;
}
void solution()
{
    cin >> n >> m;
    For(i, 1, n)
    {
        fac[i] = 0;
        g[i].clear();
    }
    For(i, 1, m)
    {
        int x, y;
        string c;
        cin >> x >> y >> c;
        int type = 1;
        if (c == "imposter")
            type = -1;
        g[x].pb({y, type});
        g[y].pb({x, type});
    }
    int ans = 0;
    For(i, 1, n)
    {
        if (fac[i])
            continue;
        p1 = 1, p2 = 0;
        fac[i] = 1;
        dfs(i, 1);
        ans += max(p1, p2);
    }
    if (flag)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

/**/
main()
{
    FAST;
    int t = 1;
    cin >> t;
    For(i, 1, t)
    {
        // cout << "#Case " << i << " :\n";
        db start = (db)(clock());
        init();
        solution();
        db end = (db)(clock());
        // cout << "Time : " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
