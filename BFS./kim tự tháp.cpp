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
            ans = ans * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ans;
}

const ll mod = 1e9 + 7;
const ll oo = (ll)1 << 60;
const db PI = 3.14159265358979323846;
const ll N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n;

struct node
{
    string r;
    ll step;
    node()
    {
        r = "";
        step = 0;
    }
    node(string x, ll y)
    {
        r = x;
        step = y;
    }
};

node a, ans = node();

vv type, ls;

void init()
{
    ls = {
        {0},
        {1, 2},
        {3, 4, 5},
        {6, 7, 8, 9},
    };
    For(i, 1, n - 1)
    {
        For(j, 0, i - 1)
        {
            ll x = ls[i][j], y = ls[i][j + 1];
            for (auto z : ls[i - 1])
            {
                type.pb({z, y, x});
            }
            if (i != n - 1)
                for (auto z : ls[i + 1])
                {
                    type.pb({x, y, z});
                }
        }
    }
}

void clean(string &s)
{
    if (n >= 2)
    {
        if (s[2] < s[1])
            swap(s[1], s[2]);
    }
    if (n >= 3)
    {

        if (s[4] < s[3] && s[4] < s[5])
        {
            // 3 4 5
            // 4 5 3
            char x = s[4];
            s[4] = s[5];
            s[5] = s[3];
            s[3] = x;
        }
        else if (s[5] < s[3] && s[5] < s[4])
        {
            // 3 4 5
            // 5 3 4
            char x = s[3];
            s[3] = s[5];
            s[5] = s[4];
            s[4] = x;
        }
    }
    if (n == 4)
    {
        if (s[7] < s[6] && s[7] < s[8] && s[7] < s[9])
        {
            // 6 7 8 9
            // 7 8 9 6
            char x = s[6];
            s[6] = s[7];
            s[7] = s[8];
            s[8] = s[9];
            s[9] = x;
        }
        else if (s[8] < s[6] && s[8] < s[7] && s[8] < s[9])
        {
            // 6 7 8 9
            // 8 9 6 7
            swap(s[6], s[8]);
            swap(s[7], s[9]);
        }
        else if (s[9] < s[8] && s[9] < s[7] && s[9] < s[6])
        {
            // 6 7 8 9
            // 9 6 7 8
            char x = s[6];
            s[6] = s[9];
            s[9] = s[8];
            s[8] = s[7];
            s[7] = x;
        }
    }
}

string rotated(string s, ll x, ll y, ll z)
{
    char c = s[x];
    s[x] = s[z];
    s[z] = s[y];
    s[y] = c;
    return s;
}

unordered_map<string, bool> vis;

void solution()
{
    cin >> n;
    init();
    For(i, 0, n * (n + 1) / 2 - 1)
    {
        ll x;
        cin >> x;
        a.r += (x - 1) + '0';
        ans.r += i + '0';
    }
    ll limit = n * (n + 1) / 2 - 1;
    // cout << ans.r << endl;
    queue<node> q;
    clean(a.r);
    vis[a.r] = 1;
    // a.r = rotated(a.r, 0, 2, 1);
    // cout << a.r << endl;
    q.push(a);
    while (q.size())
    {
        node u = q.front();
        q.pop();
        // cout << u.r << endl;
        if (u.r == ans.r)
        {
            cout << u.step << endl;
            return;
        }
        for (auto x : type)
        {
            if (limit < *max_element(all(x)))
                break;
            string s = rotated(u.r, x[0], x[1], x[2]);
            clean(s);
            if (vis[s] == 0)
            {
                vis[s] = 1;
                q.push(node(s, u.step + 1));
                // s = rotated(s, x[0], x[1], x[2]);
                // clean(s);
                // vis[s] = 1;
                // q.push(node(s, u.step + 1));
            }
        }
    }
}

main()
{
    // FILEIN;
    // FILEOUT;
    init();
    FAST;
    ll T = 1;
    // cin >> T;
    For(i, 1, T)
    {
        // cout << "TEST " << i << ":\n";
        solution();
        db end = (db)(clock());
        // cerr << "TEST " << i << ":" << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
