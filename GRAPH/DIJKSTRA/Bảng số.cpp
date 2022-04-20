#include <bits/stdc++.h>
using namespace std;
// S31[:v]
#define int long long
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> v;
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};
//
int n, m;
struct matrix
{
    int d[505][505];
};
struct qnote
{
    ii note;
    int dd;
};
bool checkij(int i, int j)
{
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}
struct cmp
{
    bool operator()(qnote a, qnote b)
    {
        return a.dd >= b.dd;
    }
};
void dijkstra(matrix a)
{
    priority_queue<qnote, vector<qnote>, cmp> pq;
    matrix dp, check;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp.d[i][j] = INT_MAX;
            check.d[i][j] = 0;
        }
    }
    dp.d[1][1] = a.d[1][1];
    pq.push({{1, 1}, dp.d[1][1]});
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            while (1)
            {
                qnote z = pq.top();
                if (check.d[z.note.fi][z.note.se] == 0)
                    break;
                else
                    pq.pop();
            }
            qnote c = pq.top();
            pq.pop();
            ii u = c.note;
            check.d[u.fi][u.se] = 1;
            for (int k = 0; k < 4; k++)
            {
                if (!checkij(u.fi + di[k], u.se + dj[k]))
                    continue;
                ii id = {u.fi + di[k], u.se + dj[k]};
                if (check.d[id.fi][id.se] == 0)
                {
                    int sum = dp.d[u.fi][u.se] + a.d[id.fi][id.se];
                    if (sum < dp.d[id.fi][id.se] || dp.d[id.fi][id.se] == INT_MAX)
                    {
                        dp.d[id.fi][id.se] = sum;
                        pq.push({id, sum});
                    }
                }
            }
            // print(dp);
        }
    }
    cout << dp.d[n][m] << endl;
}
//
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        matrix a;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a.d[i][j];
        }
        dijkstra(a);
    }
    return 0;
}
// TheEnd
