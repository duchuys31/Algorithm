int n;
int a[N];
int dp[N][30];
int merge(int x, int y)
{
    return max(x, y);
    // return min(x, y);
    // return __gcd(x, y);
}
int get(int l, int r)
{
    int m = log2(r - l + 1);
    return merge(dp[l][m], dp[r - (1 << m) + 1][m]);
}
/*Main*/
void init()
{
}
void solution()
{
    cin >> n;
    read(a, n);
    For(i, 1, n) dp[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            dp[i][j] = merge(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
        }
    }
}
