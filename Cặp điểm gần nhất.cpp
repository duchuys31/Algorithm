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
typedef pair<double, double> dd;
typedef vector<int> v;

const ll oo = 1e13;
const int mod = 1e9 + 7;
const int N = 1e5;

int di[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dj[] = {0, -1, 1, 0, -1, 1, -1, 1};
/**/
struct point
{
    double x, y;
};

bool cmp_x(const point &a, const point &b)
{
    return a.x < b.x;
}

bool cmp_y(const point &a, const point &b)
{
    return a.y < b.y;
}

#define MAXN 100000
point a[MAXN];
double mindist;
void upd_ans(const point &a, const point &b)
{
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (dist < mindist)
        mindist = dist;
}

void find(int l, int r)
{
    if (r <= l)
        return;
    if (r == l + 1)
    {
        upd_ans(a[l], a[r]);
        if (!cmp_y(a[l], a[r]))
            swap(a[l], a[r]);
        return;
    }

    int m = (l + r) / 2;
    double midx = a[m].x;
    find(l, m);
    find(m + 1, r);

    static point t[MAXN];
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, cmp_y);
    copy(t, t + r - l + 1, a + l);
    int tm = 0;
    for (int i = l; i <= r; i++)
        if (abs(a[i].x - midx) < mindist)
        {
            for (int j = tm - 1; j >= 0 && t[j].y > a[i].y - mindist; j--)
                upd_ans(a[i], t[j]);
            t[tm++] = a[i];
        }
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].x >> a[i].y;

        mindist = 1E20;
        sort(a, a + n, cmp_x);
        find(0, n - 1);

        printf("%.6lf\n", mindist);
    }

    return 0;
}
