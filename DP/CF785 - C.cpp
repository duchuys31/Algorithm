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
const int N = 4e4 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
/*Main*/
int dp[N];
/*Main*/
void init()
{
    dp[0] = 1;
    For(i, 1, N)
    {
        int d = i, rd = 0;
        while (d)
        {
            rd = rd * 10 + d % 10;
            d /= 10;
        }
        if (i != rd)
            continue;
        For(j, i, N)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
}
void solution()
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        // db start = (db)(clock());
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
