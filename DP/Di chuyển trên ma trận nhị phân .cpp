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
  โโโโโโโโโโโโโo
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
int a[105][105];
/*Main*/
string dp[105][105];
void init()
{
}
void convert()
{
}
string alpha = "#0123456789ABCDEF";
void convert(string str)
{
    while (str.size() % 4 != 0)
        str = "0" + str;
    string ans = "";
    for (int i = 0; i < str.size(); i += 4)
    {
        int d = 0;
        For(j, 0, 3)
        {
            // int d=0;
            if (str[i + 3 - j] == '1')
                d += 1 << j;
        }
        if (d <= 9)
            ans += to_string(d);
        else
            ans += "A" + d - 10;
    }
    cout << ans << endl;
}
void solution()
{
    cin >> n;
    For(i, 1, n)
    {
        For(j, 1, n) cin >> a[i][j];
    }
    For(i, 1, n)
    {
        For(j, 1, n)
        {
            dp[i][j] = "";
            if (i == 1 && j == 1)
                dp[i][j] = to_string(a[i][j]);
            else if (i == 1)
                dp[i][j] = dp[i][j - 1] + to_string(a[i][j]);
            else if (j == 1)
                dp[i][j] = dp[i - 1][j] + to_string(a[i][j]);
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + to_string(a[i][j]);
            }
        }
    }
    convert(dp[n][n]);
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
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
