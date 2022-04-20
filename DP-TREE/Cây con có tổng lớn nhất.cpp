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

typedef pair<int, int> ii;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
int n, ans;
int a[N];
v List[N];
int dp[N];
bool check[N];
/*Main*/
void DFS(int id,int before)
{
    for (auto x : List[id])
    {
        if(x==before)continue;
        DFS(x,id);
        dp[id] += dp[x];
    }
    ans = max(ans, dp[id]);
    return;
}
void init()
{
    // memset(check,0,sizeof(check));
}
void solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        List[x].push_back(y);
        List[y].push_back(x);
    }
    ans = -oo;
    DFS(1,0);
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
        init();
        solution();
    }
    return 0;
}
/*THE END*/
