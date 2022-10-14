
/* Created by Tran Duc Huy */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;
using namespace __gnu_pbds;

// #define int long long
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
    return out << x.fi << "," << x.se;
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
int n;

vector<int> calc(vector<vector<int>> a)
{
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i)
    {
        l[i] = {a[i][0], i};
        r[i] = {a[i][1], i};
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    vector<vector<pair<int, int>>> suf(n);
    vector<pair<int, int>> curr;
    for (int i0 = n - 1; i0 >= 0; --i0)
    {
        int xr = r[i0].first;
        int i = r[i0].second;
        int xl = a[i][0];
        int c = a[i][2];
        if (curr.empty())
        {
            curr.emplace_back(xl, c);
        }
        else if (curr.size() == 1)
        {
            if (curr[0].second == c)
            {
                curr[0].first = min(curr[0].first, xl);
            }
            else
            {
                curr.emplace_back(xl, c);
            }
        }
        else
        {
            if (curr[0].second == c)
            {
                curr[0].first = min(curr[0].first, xl);
            }
            else if (curr[1].second == c)
            {
                curr[1].first = min(curr[1].first, xl);
            }
            else
            {
                curr.emplace_back(xl, c);
            }
        }
        sort(curr.begin(), curr.end());
        if (curr.size() == 3)
        {
            curr.pop_back();
        }
        suf[i0] = curr;
    }
    // for(auto x: suf)
    //     cout << x << endl;
    vector<int> ans(n, 1e9);
    int j = 0;
    for (int i0 = 0; i0 < n; ++i0)
    {
        int xl = l[i0].first, i = l[i0].second;
        int xr = a[i][1], c = a[i][2];
        while (j < n && r[j].first < xl)
        {
            j++;
        }
        if (j < n)
        {
            vector<pair<int, int>> s = suf[j];
            if (s[0].second != c)
            {
                ans[i] = min(ans[i], max(0, s[0].first - xr));
            }
            else if (s.size() == 2)
            {
                ans[i] = min(ans[i], max(0, s[1].first - xr));
            }
        }
    }
    return ans;
}

const int K = 1e9 + 1;

void solution()
{
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3)), b(n, vector<int>(3));
    vector<pair<int, int>> l(n), r(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> a[i][j];
            if (j == 2)
            {
                b[i][j] = a[i][j];
            }
            else
            {
                b[i][1 - j] = K - a[i][j];
            }
        }
    }
    vector<int> ans1 = calc(a);
    v ans2 = calc(b);
    // cout << ans1 << endl;
    // cout << ans2 << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << min(ans1[i], ans2[i]) << ' ';
    }
    cout << '\n';
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
        solution();
        db end = (db)(clock());
        // cout << "Time : " << (end - start) / CLOCKS_PER_SEC << "s" << endl;
    }
    return 0;
}
