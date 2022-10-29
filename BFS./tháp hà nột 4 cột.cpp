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
const ll N = 15;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};

ll n;
v ls[5];
v c(4, 9);
ll p[20];

struct node
{
    v u;
    ll k, h;
};

ll len(ll x)
{
    ll cnt = 0;
    for (; x; cnt++)
        x /= 10;
    return cnt;
}

ll get(v a)
{
    ll s = 0;
    for (auto x : a)
    {
        s = (s * p[11] + x) % mod;
    }
    return s;
}

unordered_set<ll> have;

void init()
{
    p[0] = 1;
    For(i, 1, 18) p[i] = p[i - 1] * 10;
}

void solution()
{
    cin >> n;
    For(i, 1, n)
    {
        ll x;
        cin >> x;
        ls[x - 1].pb(i - 1);
    }
    For(i, 0, 3)
    {
        sort(all(ls[i]), greater<ll>());
        for (auto x : ls[i])
        {
            c[i] = c[i] * 10 + x;
        }
    }

    v ans(4, 9);
    Ford(i, n - 1, 0) ans[0] = ans[0] * 10 + i;
    ll answer = get(ans);
    // cout << answer << endl;
    // cout << get(c) << endl;
    queue<node> q;
    q.push({c, 0, get(c)});
    have.insert(get(c));
    while (q.size())
    {
        c = q.front().u;
        ll k = q.front().k;
        ll h = q.front().h;
        q.pop();
        // cout << c << endl;
        if (h == answer)
        {
            cout << k << endl;
            return;
        }
        For(i, 0, 3)
        {
            For(j, 0, 3)
            {
                if (i != j)
                {
                    if (c[i] % 10 <= c[j] % 10 && c[i] / 10)
                    {
                        v newc = c;
                        ll x = c[i] % 10;
                        newc[i] /= 10;
                        newc[j] = newc[j] * 10 + x;
                        ll h = get(newc);
                        if (!have.count(h))
                        {
                            have.insert(h);
                            q.push({newc, k + 1, h});
                        }
                    }
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
    init();
    ll T = 1;
    // cin >> T;
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
