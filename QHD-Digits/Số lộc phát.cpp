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
int n, length;
string s;
int a[20];
int dp[20][20][8][2][20];
/*Main*/
void init()
{
    reset(dp, -1);
}
int cal(int len, int id, int d, int islower, int cnt)
{
    // cout << id << "-" << d << "-" << cnt << endl;
    if (id == len + 1)
    {
        if (!d)
            return cnt;
        return 0;
    }
    int x = dp[len][id][d][islower][cnt];
    if (x != -1)
        return x;
    x = 0;
    For(i, 0, 9)
    {
        if (!islower && i > a[id])
            break;
        int new_islower = islower | (i < a[id]);
        int new_d = (d * 10 + i) % 8;
        int new_cnt = cnt + (i == 6 || i == 8);
        x += cal(len, id + 1, new_d, new_islower, new_cnt);
        // cout<<x<<endl;
    }
    dp[len][id][d][islower][cnt] = x;
    return x;
}
void solve()
{
    int x = cal(length, 1, 0, 0, 0);
    cout << x << endl;
}
void solution()
{
    cin >> n;
    s = to_string(n);
    length = s.size();
    For(i, 1, length) a[i] = s[i - 1] - '0';
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
/*THE END*/
