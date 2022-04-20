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
/*Main*/
int w, k;
// v tmp;
void init()
{
}
void solution()
{
    cin >> w >> k;
    if (w % 1000)
    {
        cout << 0 << endl;
        return;
    }
    w /= 1000;
    int cnt = 0;
    int way = 1;
    while (w && k--)
    {
        if (w % 10 == 1 || w % 10 == 2 || w % 10 == 3 || w % 10 == 5)
        {
            cnt++;
        }
        else if (w % 10 == 4 || w % 10 == 6)
        {
            cnt += 2;
            way *= 2;
        }
        else if (w % 10 == 7 || w % 10 == 8)
        {
            cnt += 2;
        }
        else if (w % 10 == 9)
        {
            // 3 3 3,5 2 2,5 3 1
            cnt += 3;
            way *= 3;
        }
        w /= 10;
    }
    if (w)
    {
        int x = w;
        cnt += x / 5;
        int d = w % 5;
        if (d == 4)
            cnt += 2;
        else if (d != 0)
            cnt++;
        if (d == 1 && x > 1 || x == 4)
            way *= 2;
        if (d == 4 && x > 4)
            way *= 3;
    }
    cout << cnt << " " << way << endl;
}
/**/
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
/*THE END*/
