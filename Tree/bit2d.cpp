
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
#define all(a) a.begin(), a.end()
#define For(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define Ford(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define uniq(a) a.resize(unique(all(a)) - a.begin())
#define FILEIN freopen("input.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &x)
{
    return out << x.fi << ',' << x.se;
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

typedef pair<ll, ll> ii;
typedef pair<ll, ii> i_ii;
typedef pair<ii, ll> ii_i;
typedef pair<ii, ii> ii_ii;
typedef pair<ll, char> ic;
typedef pair<char, ll> ci;
typedef pair<ll, string> is;
typedef pair<string, ll> si;
typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<ll> v;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<v> vv;

ll _max(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll _min(ll a, ll b, ll c) { return min(a, min(b, c)); }

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
        a[i] = lower_bound(all(c), a[i]) - c.begin();
    }
    return a;
}
ll powermod(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ans;
}

const ll mod = 1e9 + 7;
const ll oo = (ll)1 << 60;
const db PI = 3.14159265358979323846;
const ll N = 1e3 + 5;

ll di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
ll dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
ll q;

struct bit2d
{
    ll a[N][N][2], b[N][N][2];
    bit2d()
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    void update2(ll t[N][N][2], ll x, ll y, ll mul, ll add)
    {
        for (ll i = x; i < N; i += i & -i)
        {
            for (ll j = y; j < N; j += j & -j)
            {
                t[i][j][0] += mul;
                t[i][j][1] += add;
            }
        }
    }
    void update1(ll x, ll y1, ll y2, ll mul, ll add)
    {
        update2(a, x, y1, mul, -mul * (y1 - 1));
        update2(a, x, y2, -mul, mul * y2);
        update2(b, x, y1, add, -add * (y1 - 1));
        update2(b, x, y2, -add, add * y2);
    }
    void update(ll x1, ll y1, ll x2, ll y2, ll val)
    {
        update1(x1, y1, y2, val, -val * (x1 - 1));
        update1(x2, y1, y2, -val, val * x2);
    }
    ll query2(ll t[N][N][2], int x, int y)
    {
        ll mul = 0, add = 0;
        for (int i = y; i > 0; i -= i & -i)
        {
            mul += t[x][i][0];
            add += t[x][i][1];
        }
        return mul * x + add;
    }
    ll query1(int x, int y)
    {
        ll mul = 0, add = 0;
        for (int i = x; i > 0; i -= i & -i)
        {
            mul += query2(a, i, y);
            add += query2(b, i, y);
        }
        return mul * x + add;
    }
    ll query(int x1, int y1, int x2, int y2)
    {
        return query1(x2, y2) - query1(x1 - 1, y2) - query1(x2, y1 - 1) + query1(x1 - 1, y1 - 1);
    }
} t;

/*Main*/
void init()
{
}
void solution()
{
    cin >> q;
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x, y;
            cin >> x >> y;
            t.update(x, y, x, y, 1);
        }
        else
        {
            ll a, b, x, y;
            cin >> a >> b >> x >> y;
            ll k = t.query(a, b, x, y);
            cout << k * (k - 1) * (k - 2) / 6 << endl;
        }
    }
}
/**/
main()
{
    // FILEIN;
    // FILEOUT;
    FAST;
    ll T = 1;
    // cin >> T;
    For(i, 1, T)
    {
        // cout << "TEST " << i << ":\n";
        db start = (db)(clock());
        solution();
        db end = (db)(clock());
        cerr << "TEST " << i << ": " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
