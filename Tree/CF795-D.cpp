
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
#define db double
#define fi first
#define se second
#define in binary_search
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)
#define lb(a, x) (lower_bound(all(a), x) - a.begin())
#define ub(a, x) (upper_bound(all(a), x) - a.begin())
#define uniq(a) a.resize(unique(all(a)) - a.begin())

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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> ii;
typedef pair<db, db> dd;
typedef vector<ii> vii;
typedef vector<int> v;
typedef vector<v> vv;

const ll oo = 1e9 + 7;
const db PI = 3.14159265358979323846;
const int mod = 1e18 + 7;
const int N = 2e5 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
struct Segment_Tree
{
    int seg[4 * N], lazy[4 * N];

    void down(int id)
    {
        int t = lazy[id];
        seg[id << 1] += t;
        seg[id << 1 | 1] += t;
        lazy[id << 1] += t;
        lazy[id << 1 | 1] += t;
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int val)
    {
        if (r < u)
            return;
        if (l >= u)
        {
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, val);
        update(id << 1 | 1, mid + 1, r, u, val);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return -oo;
        if (l >= u && r <= v)
        {
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        int v1 = get(id << 1, l, mid, u, v);
        int v2 = get(id << 1 | 1, mid + 1, r, u, v);
        return max(v1, v2);
    }

    void build(int a[], int id, int l, int r)
    {
        if (l == r)
        {
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, id << 1, l, mid);
        build(a, id << 1 | 1, mid + 1, r);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }
}; 
int n;
int a[N];
int pre[N], suf[N];
int l[N], r[N];
void setlr()
{
    For(i, 1, n)
    {
        l[i] = i;
        while (l[i] > 1 && a[i] >= a[l[i] - 1])
            l[i] = l[l[i] - 1];
    }
    rFor(i, n, 1)
    {
        r[i] = i;
        while (r[i] < n && a[i] >= a[r[i] + 1])
            r[i] = r[r[i] + 1];
    }
}
/*𝑴𝒂𝒊𝒏*/
void init()
{
}
void solution()
{
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) pre[i] = pre[i - 1] + a[i];
    suf[n + 1] = 0;
    rFor(i, n, 1) suf[i] = suf[i + 1] + a[i];

    Segment_Tree tp, ts;
    tp.build(pre, 1, 1, n);
    ts.build(suf, 1, 1, n);
    setlr();
    For(i, 1, n)
    {
        int x1 = tp.get(1, 1, n, i + 1, r[i]) - pre[i];
        int x2 = ts.get(1, 1, n, l[i], i - 1) - suf[i];
        if (max(x1, x2) > 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
        db start = (db)(clock());
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
