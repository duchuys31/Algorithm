#include <bits/stdc++.h>
using namespace std;
/* ๐ด๐ ๐๐๐ ๐๐ ๐๐๐๐๐๐๐ ๐๐ ๐๐๐ โโฟโ. */
/* ๐ญ๐๐๐ ๐๐ ๐๐๐ ๐๐ ๐๐๐๐ ๐๐๐๐ ๐๐๐ ๐๐๐๐๐๐๐๐๐๐ ๐๐๐ ๐๐๐๐๐๐๐ (๏ฝกโโฟโ๏ฝก). */
/*
   โโ          โโ
   โโโ        โโโ
  โโโโโ    โโโโโ
  โโโโโโโโโโโโโ
  โโโโโโโโโโโโโ
  โโโโโโโโโโโโโ
   โโโโโโโโโโโ
  โโโโโโโโโโโโโ      โ
 โโโโโโโโโโโโโโโโ  โโโ
 โโโโโโโโโโโโโโโโ โโโโ
 โโโโโโโโโโโโโโโ โโโโ
  โโโโ=โฒ=โโโโโโโ โโโโ
  โโโโโโฅโโโโโโโโ  โโโโ
    โโโโโโโโโโโ    โโโ
      โโโโโโ        โโโ
       โโโโโโโ      โโ
       โโโโโโโโโโ _โโ
       โโโโโโโโโโโโโ
       โโโโโโโโโโโโโ
     โโโโโโโโโโโโโโ
      โโโโโโโโโโโโ
*/
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> ii;
typedef pair<db, db> dd;
typedef vector<int> v;

const ll oo = 9223372036854775807;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n;
string s;
int pre[N][2];
int a[N];
/*Main*/
void init()
{
}
void solution()
{
    cin >> s;
    n = s.size();
    For(i, 0, n + 1)
    {
        pre[i][1] = pre[i][0] = 0;
    }
    For(i, 1, n)
    {
        if (s[i - 1] == '1')
            a[i] = 1;
        else
            a[i] = 0;
        pre[i][1] = pre[i - 1][1] + (a[i] == 1);
        pre[i][0] = pre[i - 1][0] + (a[i] == 0);
    }
    int ans = oo;
    For(i, 0, n)
    {
        int S = oo;
        int l = i + 1, r = n + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int s1 = pre[i][1] + pre[n][1] - pre[m - 1][1];
            int s0 = pre[n][0] - (pre[i][0] + pre[n][0] - pre[m - 1][0]);
            if (s1 < s0)
            {
                S = min(S, s0);
                r = m - 1;
            }
            else
            {
                S = min(S, s1);
                l = m + 1;
            }
        }
        ans = min(ans, S);
    }
    cout << ans << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        // db start = (db)(clock());
        init();
        solution();
        // db end = (db)(clock());
        // cout << (end - start) / CLOCKS_PER_SEC <<"s"<<endl;
    }
    return 0;
}
/* ๐ด๐ ๐๐๐๐ ๐๐๐ ๐๐๐๐๐. */
/* ๐บ๐๐ ๐๐๐ ๐๐๐๐๐ โค */
/*
โซ โช โซ โช โซ โช โซ โช
โ โ โ โ โ โ โ โ โ โ โ
Min- - - - - - - - - - - -โMax
*/
