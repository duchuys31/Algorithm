#include <bits/stdc++.h>
using namespace std;
/*Start*/
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒████
  █▒▒▒▒▒▒▒▒████      █
 ██▒█▒▒▒▒▒█▒▒████  █▒█
 █▒█●█▒▒▒█●█▒▒███ █▒▒█
 █▒▒█▒▒▒▒▒█▒▒▒██ █▒▒█
  █▒▒▒=▲=▒▒▒▒███ ██▒█
  ██▒▒█♥█▒▒▒▒███  ██▒█
    ███▒▒▒▒████    █▒█
      ██████        ███
       █▒▒████      ██
       █▒▒▒▒▒████ _██
       █▒██▒██████▒█
       █▒███▒▒▒█████
     █▒████▒▒▒▒████
      █▒███▒██████
*/
#define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 9;
const int N = 1e3 + 1;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, m, s;
int a[N], b[N];
int dp[11][N][N];
// int col[11][N][N];
int pre[11][N][N];
/*Main*/
void init()
{
    // reset(dp, 0);
}
void solve()
{
    int ans = 0;
    For(i, 1, s)
    {
        // cout << "u:" << i << endl;
        For(j, 1, n)
        {
            For(k, 1, m)
            {
                dp[i][j][k] = 0;
                if (a[j] <= b[k])
                {
                    dp[i][j][k] = 0;
                }
                else if (i == 1)
                {
                    dp[i][j][k] = 1;
                }
                else
                {
                    dp[i][j][k] = pre[i - 1][j - 1][k - 1];
                }
                pre[i][j][k] = (pre[i][j - 1][k] + dp[i][j][k]) % mod;
                // cout << dp[i][j][k] << "-" << pre[i-1][j-1][k-1] << "  ";
                if (i == s)
                    ans = (ans + dp[i][j][k]) % mod;
            }
            // cout << endl;
        }
        For(j, 1, n)
        {
            For(k, 1, m)
            {
                pre[i][j][k] = (pre[i][j][k] + pre[i][j][k - 1]) % mod;
                // cout<<pre[i][j][k]<<" ";
            }
        }
    }
    cout << ans << endl;
}
void solution()
{
    cin >> n >> m >> s;
    For(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    For(i, 1, m) cin >> b[i];
    sort(b + 1, b + m + 1);
    solve();
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;
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
/*THE END*/
