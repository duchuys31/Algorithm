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
// #define int long long
#define ll long long
#define db double
#define fi first
#define se second
#define reset(a, val) memset(a, val, sizeof(a));
#define For(i, a, b) for (int i = a; i <= b; i++)
#define rFor(i, a, b) for (int i = a; i >= b; i--)
 
typedef pair<int, int> ii;
typedef vector<int> v;
 
int mod = 1e9 + 7;
 
/**/
int dp[2001][2001][2][2];
int m, d, len;
string a, b;
/*Main*/
int solve(int i, int _m, int _a, int _b)
{
    if (i == len)
        return !_m;
    int x = dp[i][_m][_a][_b];
    if (x != -1)
        return x;
    x = 0;
    for (int j = 0; j <= 9; j++)
    {
        if (i % 2 && j != d)
            continue;
        if (i % 2 == 0 && j == d)
            continue;
        if (!_a && a[i] - '0' > j)
            continue;
        if (!_b && b[i] - '0' < j)
            continue;
        bool new_a = _a | (a[i] - '0' < j);
        bool new_b = _b | (b[i] - '0' > j);
        x = x + solve(i + 1, (_m * 10 + j) % m, new_a, new_b);
        x %= mod;
    }
    dp[i][_m][_a][_b] = x;
    return x;
}
void init() {}
void solution()
{
    memset(dp, -1, sizeof(dp));
    cin >> m >> d >> a >> b;
    len=a.size();
    cout << solve(0, 0, 0, 0) << endl;
}
/**/
main()
{
    solution();
    return 0;
}
/*THE END*/
