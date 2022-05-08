#include <bits/stdc++.h>
using namespace std;
int t, n, m, sx, sy;
char mp[1000010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool check(int x, int y)
{
    return x >= 1 && y >= 1 && x <= n && y <= m && mp[(x - 1) * m + y] == '.';
}
void dfs(int x, int y)
{
    int now = (x - 1) * m + y, cnt = 0;
    for (int i = 0; i < 4; i++)
        if (check(x + dx[i], y + dy[i]))
            cnt++;
    if (mp[now] == '.' && cnt > 1)
        return;
    if (mp[now] == '.')
        mp[now] = '+';
    for (int i = 0; i < 4; i++)
        if (check(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= m; j++)
            {
                mp[(i - 1) * m + j] = getchar();
                if (mp[(i - 1) * m + j] == 'L')
                    sx = i, sy = j;
            }
        }
        dfs(sx, sy);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                putchar(mp[(i - 1) * m + j]);
            putchar('\n');
        }
    }
    return 0;
}
