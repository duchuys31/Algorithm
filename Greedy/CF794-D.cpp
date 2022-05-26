
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

const ll oo = 9223372036854775807;
const db PI = 3.14159265358979323846;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
bool cmp(deque<char> x, deque<char> y)
{
    return x.size() < y.size();
}
int a, b, c, d;
string s;
/*𝑴𝒂𝒊𝒏*/
void init()
{
}
void solution()
{
    cin >> a >> b >> c >> d;
    cin >> s;
    vector<deque<char>> tmp;
    deque<char> str;
    str.push_back(s[0]);
    For(i, 1, s.size() - 1)
    {
        if (s[i] != str.back())
            str.push_back(s[i]);
        else
        {
            tmp.push_back(str);
            str.clear();
            str.push_back(s[i]);
        }
    }

    tmp.push_back(str);
    sort(all(tmp), cmp);
    for (auto &x : tmp)
    {
        if (x.size() & 1)
            continue;
        while (x.size())
        {
            if (x.back() == 'B')
            {
                if (c)
                {
                    c--;
                    x.pop_back();
                    x.pop_back();
                }
                else
                    break;
            }
            else
            {
                if (d)
                {
                    d--;
                    x.pop_back();
                    x.pop_back();
                }
                else
                    break;
            }
        }
    }

    for (auto &x : tmp)
    {
        if (x.size() & 1)
            continue;
        while (x.size())
        {
            if (x.back() == 'B')
            {
                if (!c)
                {
                    if (a && b)
                    {
                        x.pop_back();
                        x.pop_front();
                        a--;
                        b--;
                    }
                    else
                        break;
                }
                else
                {
                    c--;
                    x.pop_back();
                    x.pop_back();
                }
            }
            else if (x.back() == 'A')
            {
                if (!d)
                {
                    if (a && b)
                    {
                        x.pop_back();
                        x.pop_front();
                        a--;
                        b--;
                    }
                    else
                        break;
                }
                else
                {
                    d--;
                    x.pop_back();
                    x.pop_back();
                }
            }
        }
    }
    for (auto &x : tmp)
    {
        if (x.size() % 2 == 0)
            continue;
        while (x.size() > 1)
        {
            if (c)
                c--;
            else if (d)
                d--;
            else
                break;
            x.pop_back();
            x.pop_back();
        }
    }
    for (auto &x : tmp)
    {
        for (auto c : x)
        {
            if (c == 'A')
            {
                if (a)
                    a--;
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            else
            {
                if (b)
                    b--;
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
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
