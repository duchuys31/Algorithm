
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
#define rev greater
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
void read(int a[], int n)
{
    For(i, 1, n) cin >> a[i];
}
void print(v a, int n)
{
    For(i, 1, n) cout << a[i] << " ";
    cout << endl;
}
const ll oo = 999999999999999999;
const db PI = 3.14159265358979323846;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n;
v a(N), b(N);
set<int> os;
int convert(int i)
{
    while (os.size() && *os.begin() < i)
        os.erase(os.begin());
    int x = os.size();
    if (x % 2 == 0)
        return a[i];
    return (1 - a[i]);
}
/*Main*/
void init()
{
    os.clear();
}
void solution()
{
    int ans = 0;
    cin >> n;
    set<int> same, dif;
    For(i, 1, n)
    {
        char x;
        cin >> x;
        a[i] = (x == '1');
    }
    For(i, 1, n)
    {
        char x;
        cin >> x;
        b[i] = (x == '1');
    }
    For(i, 2, n - 1)
    {
        if (a[i] != a[i + 1])
            dif.insert(i);
        else
            same.insert(i);
    }
    For(i, 1, n)
    {
        int x = convert(i);
        int next = convert(i + 1);
        int pre = a[i - 1];
        // cout << a[i] << ' ';
        if (x == b[i])
        {
            // cout << i << " ";
            a[i] = b[i];
            continue;
        }
        if (i == 1 || i == n)
        {
            cout << -1 << endl;
            return;
        }
        if (pre != next)
        {
            ans++;
            a[i] = b[i];
        }
        else
        {
            if (pre == x && x == next)
            {
                while (dif.size() && *dif.begin() <= i)
                    dif.erase(dif.begin());
                if (dif.empty())
                {
                    cout << -1 << endl;
                    return;
                }
                auto it = dif.begin();
                ans += *it - i + 1;
                // For(j, i, *it) a[j] = !a[j];
                os.insert(*it);
                a[i] = b[i];
                dif.erase(dif.begin());
            }
            else
            {
                while (same.size() && *same.begin() <= i)
                    same.erase(same.begin());
                if (same.empty())
                {
                    cout << -1 << endl;
                    return;
                }
                auto it = same.begin();
                ans += *it - i + 1;
                // For(j, i, *it) a[j] = !a[j];
                os.insert(*it);
                a[i] = b[i];
                same.erase(same.begin());
            }
        }
    }
    // cout << endl;
    cout << ans << endl;
}
// 001 0 101011
// 000 0 111111
// 000101
// 001101 - 1
// 011101 - 2
// 011001 - 3
// 010001 - 4
// 010011 - 5
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
