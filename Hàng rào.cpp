#include <bits/stdc++.h>
using namespace std;
/* 𝑴𝒚 𝒄𝒂𝒕 𝒊𝒔 𝒍𝒐𝒐𝒌𝒊𝒏𝒈 𝒂𝒕 𝒚𝒐𝒖 ◉‿◉. */
/* 𝑭𝒆𝒆𝒅 𝒊𝒕 𝒂𝒏𝒅 𝒊𝒕 𝒘𝒊𝒍𝒍 𝒉𝒆𝒍𝒑 𝒚𝒐𝒖 𝒖𝒏𝒅𝒆𝒓𝒔𝒕𝒂𝒏𝒅 𝒕𝒉𝒆 𝒑𝒓𝒐𝒃𝒍𝒆𝒎 (｡◕‿◕｡). */
/*
   ██          ██
   █▒█        █▒█
  █▒███    ███▒█
  █▒████████▒▒█
  █▒████▒▒█▒▒██
  ████▒▒▒▒▒████
   █▒▒▒▒▒▒▒███
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

const int inf = 1 << 30;

int x[3010], y[3010];

int t[3010];
int compress(int a[3010], int z)
{
    memcpy(t, a, sizeof(t));
    sort(t, t + z);
    int nz = unique(t, t + z) - t;
    for (int i = 0; i < z; i++)
    {
        a[i] = (lower_bound(t, t + nz, a[i]) - t) * 2;
    }
    return nz * 2;
}

int xz, yz;
char arr[6010][6010];

int gz;
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, -1, 0, 1};

stack<short> sx, sy;
void put(int x, int y)
{
    if (x < 0 || x >= xz || y < 0 || y >= yz)
        return;
    if (arr[x][y] == 'X')
        return;
    gz += (arr[x][y] == 'C');
    arr[x][y] = 'X';
    sx.push(x);
    sy.push(y);
}

void dfs(int startx, int starty)
{
    put(startx, starty);
    while (sx.size())
    {
        int x = sx.top();
        sx.pop();
        int y = sy.top();
        sy.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];
            put(nx, ny);
        }
    }
}

void solution()
{
    int n, m;
    cin >> n >> m;
    int z = 0;
    x[z] = y[z] = -inf;
    z++;
    x[z] = y[z] = inf;
    z++;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> x[z] >> y[z];
        z++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x[z] >> y[z];
        z++;
    }
    xz = compress(x, z);
    yz = compress(y, z);
    memset(arr, '.', sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        int a = i * 2 + 2;
        int b = i * 2 + 3;
        int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
        if (x1 == x2)
        {
            if (y1 > y2)
                swap(y1, y2);
            while (y1 <= y2)
            {
                arr[x1][y1] = 'X';
                y1++;
            }
        }
        else
        {
            if (x1 > x2)
                swap(x1, x2);
            while (x1 <= x2)
            {
                arr[x1][y1] = 'X';
                x1++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a = i + 2 * n + 2;
        arr[x[a]][y[a]] = 'C';
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a = i + 2 * n + 2;
        gz = 0;
        dfs(x[a], y[a]);
        ans = max(ans, gz);
    }
    cout << ans << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output1.txt", "w", stdout);
    int t = 1;
    cin >> t;
    For(i, 1, t)
    {
        // db start = (db)(clock());
        solution();
        // db end = (db)(clock());
        // cout << (end - start) / CLOCKS_PER_SEC <<"s"<<endl;
    }
    return 0;
}
/* 𝑴𝒚 𝒄𝒐𝒅𝒆 𝒉𝒂𝒔 𝒆𝒏𝒅𝒆𝒅. */
/* 𝑺𝒆𝒆 𝒚𝒐𝒖 𝒂𝒈𝒂𝒊𝒏 ❤ */
/*
♫ ♪ ♫ ♪ ♫ ♪ ♫ ♪
▄ █ ▄ █ ▄ ▄ █ ▄ █ ▄ █
Min- - - - - - - - - - - -●Max
*/
