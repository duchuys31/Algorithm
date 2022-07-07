
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
#define db double
#define fi first
#define se second
#define in binary_search
#define umap unordered_map
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i >= b; i--)
#define lb(a, x) (lower_bound(all(a), x) - a.begin())
#define ub(a, x) (upper_bound(all(a), x) - a.begin())
#define uniq(a) a.resize(unique(all(a)) - a.begin())
#define FILE                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

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
    a.push_back(0);
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
umap<T, int> compress(const vector<T> &vec)
{
    vector<T> sorted = vec;
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
            r *= a;
        b >>= 1;
        a *= a;
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
typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<int> v;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<v> vv;

int __lcm(int a, int b) { return a / __gcd(a, b) * b; }
// int _max(int a, int b, int c) { return max(a, max(b, c)); }
// int _min(int a, int b, int c) { return min(a, min(b, c)); }

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

const ll oo = 9223372036854775807;
const db PI = 3.14159265358979323846;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, m;
int a[N];
int s[N];
int Max[4 * N], Min[4 * N];
void build(int node, int l, int r)
{
    if (l == r)
    {
        Max[node] = s[l];
        Min[node] = s[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(node * 2, l, m);
        build(node * 2 + 1, m + 1, r);
        Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
        Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
    }
}
int _max(int node, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return -oo;
    if (l >= left && r <= right)
        return Max[node];
    return max(_max(node * 2, l, (l + r) / 2, left, right), _max(node * 2 + 1, (l + r) / 2 + 1, r, left, right));
}
int _min(int node, int l, int r, int left, int right)
{
    if (l > right || r < left)
        return oo;
    if (l >= left && r <= right)
        return Min[node];
    return min(_min(node * 2, l, (l + r) / 2, left, right), _min(node * 2 + 1, (l + r) / 2 + 1, r, left, right));
}
/*Main*/
void init()
{
}
void solution()
{
    cin >> n >> m;
    For(i, 1, 4 * n)
    {
        Max[i] = oo;
        Min[i] = -oo;
    }
    For(i, 1, n)
    {
        char x;
        cin >> x;
        if (x == '+')
            a[i] = 1;
        else
            a[i] = -1;
    }
    For(i, 1, n)
    {
        s[i] = s[i - 1] + a[i];
        // cout << s[i] << " ";
    }
    // cout << endl;
    build(1, 1, n);
    For(q, 1, m)
    {
        int l, r;
        cin >> l >> r;
        int mn = 0, mx = 0;
        if (l > 1)
        {
            mn = min(mn, _min(1, 1, n, 1, l - 1));
            mx = max(mx, _max(1, 1, n, 1, l - 1));
        }
        if (r < n)
        {
            mn = min(mn, _min(1, 1, n, r + 1, n) - s[r] + s[l - 1]);
            mx = max(mx, _max(1, 1, n, r + 1, n) - s[r] + s[l - 1]);
        }
        // cout << mn << " " << mx << endl;
        cout << mx - mn + 1 << endl;
    }
}
/**/
main()
{
    FAST;
    int t = 1;
    cin >> t;
    For(i, 1, t)
    {
        // cout<<"#Case "<<i<<" :\n";
        db start = (db)(clock());
        init();
        solution();
        db end = (db)(clock());
        // cout << "Time : " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
