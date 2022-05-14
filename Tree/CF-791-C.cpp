
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
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)
#define lb(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define ub(a, x) (upper_bound(all(a), x) - a.begin())
#define uniq(a) a.resize(unique(all(a)) - a.begin())

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
int n, q;
ordered_set<int> X, Y;
int dx[N], dy[N];
/*𝑴𝒂𝒊𝒏*/
void init()
{
}
void solution()
{
    cin >> n >> q;
    For(i, 1, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            dx[x]++;
            dy[y]++;
            if (dx[x] == 1)
                X.insert(x);
            if (dy[y] == 1)
                Y.insert(y);
        }
        else if (t == 2)
        {
            int x, y;
            cin >> x >> y;
            dx[x]--;
            dy[y]--;
            if (!dx[x])
                X.erase(x);
            if (!dy[y])
                Y.erase(y);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x2 < x1)
                swap(x1, x2);
            int k = X.order_of_key(x2 + 1) - X.order_of_key(x1);
            if (k == x2 - x1 + 1)
            {
                cout << "YES\n";
                continue;
            }
            if (y2 < y1)
                swap(y1, y2);
            k = Y.order_of_key(y2 + 1) - Y.order_of_key(y1);
            if (k == y2 - y1 + 1)
            {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
    }
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
    // cin >> t;
    For(i, 1, t)
    {
        // cout<<"#Case "<<i<<" :\n";
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
