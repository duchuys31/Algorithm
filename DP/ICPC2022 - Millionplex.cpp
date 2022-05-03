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
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
string s;
int len;
int a[N];
int pre[N];
int dp[N];
/*Main*/
void init() {}
void solution()
{
    cin >> s;
    len = s.size();
    For(i, 1, len) a[i] = s[i - 1] - '0';
    For(i, 1, len) pre[i] = (pre[i - 1] * 10 + a[i] * i) % mod;
    int ans = 0;
    For(i, 1, len)
    {
        dp[i] = (dp[i - 1] * 100 + 20 * pre[i - 1] * a[i] + a[i] * a[i] * i) % mod;
        ans = (ans + dp[i]) % mod;
    }
    // For(i, 1, len) cout << dp[i] << " ";
    // cout << endl;
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
