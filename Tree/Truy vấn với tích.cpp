
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
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
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
istream &operator>>(istream &in, pair<T1, T2> &x)
{
    return in >> x.fi >> x.se;
}
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
            ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

const ll oo = (ll)1 << 60;
const ll mod = 1e9 + 7;
const db PI = 3.14159265358979323846;
const ll N = 5e4 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n, q;
ll e[155];
v prime;

void era()
{
    For(i, 1, 150) e[i] = i;
    for (ll i = 2; i * i <= 150; i++)
    {
        if (e[i] == i)
            for (ll j = i * i; j <= 150; j += i)
                e[j] = i;
    }
    For(i, 2, 150) if (e[i] == i) prime.pb(i);
}

struct Seg
{
    int seg[4 * N], lazy[4 * N];
    void set(int x, int n)
    {
        for (int i = 0; i <= 4 * n; i++)
        {
            seg[i] = x;
            lazy[i] = 0;
        }
    }
    int merge(int x, int y)
    {
        return x + y;
    }
    int add(int l, int r, int x)
    {
        return (r - l + 1) * x;
        // return x;
    }
    void down(int id, int l, int r)
    {
        int t = lazy[id];
        lazy[id] = 0;
        int m = (l + r) >> 1;

        seg[id << 1] += add(l, m, t);
        lazy[id << 1] += t;

        seg[id << 1 | 1] += add(m + 1, r, t);
        lazy[id << 1 | 1] += t;
    }
    void update(int id, int l, int r, int u, int v, int val)
    {
        if (l > v || r < u || l > r)
            return;
        if (l >= u && r <= v)
        {
            seg[id] += add(l, r, val);
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u || l > r)
            return 0;
        if (l >= u && r <= v)
        {
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        int v1 = get(id << 1, l, mid, u, v);
        int v2 = get(id << 1 | 1, mid + 1, r, u, v);
        return merge(v1, v2);
    }
};

Seg t[150];
map<ll, ll> cnt;

void convert(ll x)
{
    cnt.clear();
    while (x > 1)
    {
        cnt[e[x]]++;
        x /= e[x];
    }
}

void init()
{
    for (auto x : prime)
    {
        t[x].set(0, n);
    }
}

void solution()
{
    cin >> n >> q;
    init();
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 0)
        {
            ll l, r, p;
            cin >> l >> r >> p;
            ll ans = 1;
            if (l <= r)
            {
                for (auto x : prime)
                {
                    ll s = t[x].get(1, 1, n, l, r);
                    ans = (ans * powermod(x, s, p)) % p;
                }
            }
            else{
                for (auto x : prime)
                {
                    ll s = t[x].get(1, 1, n, l, n);
                    s += t[x].get(1, 1, n, 1, r);
                    ans = (ans * powermod(x, s, p)) % p;
                }
            }
            cout << ans << endl;
        }
        else if (type == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            convert(x);
            for (auto it : cnt)
            {
                if (l <= r)
                    t[it.fi].update(1, 1, n, l, r, it.se);
                else
                {
                    t[it.fi].update(1, 1, n, l, n, it.se);
                    t[it.fi].update(1, 1, n, 1, r, it.se);
                }
            }
        }
        else
        {
            ll l, r, y;
            cin >> l >> r >> y;
            convert(y);
            for (auto it : cnt)
            {
                if (l <= r)
                    t[it.fi].update(1, 1, n, l, r, -it.se);
                else
                {
                    t[it.fi].update(1, 1, n, l, n, -it.se);
                    t[it.fi].update(1, 1, n, 1, r, -it.se);
                }
            }
        }
    }
}

main()
{
    // FILEIN;
    // FILEOUT;
    FAST;
    era();
    ll T = 1;
    cin >> T;
    For(i, 1, T)
    {
        // cout << "TEST " << i << ":\n";
        db start = (db)(clock());
        solution();
        db end = (db)(clock());
        // cerr << "TEST " << i << ":" << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
