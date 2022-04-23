int n, k;
bool isclear[N], was[N];
int dp[20][2][N];
v a;
int sumsqr(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += (x % 10) * (x % 10);
        x /= 10;
    }
    return ans;
}
/*Main*/
void init()
{
    isclear[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        memset(was, 0, sizeof(was));
        for (int j = i; !was[j]; j = sumsqr(j))
        {
            was[j] = 1;
            if (j < i)
            {
                isclear[i] = isclear[j];
                break;
            }
        }
    }
}
int solve(int i, bool bigger, int sum)
{
    if (i < 0)
        return bigger && isclear[sum];
    ll &ans = dp[i][bigger][sum];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int x = (bigger ? 0 : a[i]); x <= 9; ++x)
    {
        ans += solve(i - 1, bigger | (x > a[i]), sum + x * x);
    }
    return ans;
}
void solution()
{
    cin >> n >> k;
    int _n = n;
    a.clear();
    while (_n > 0)
    {
        a.push_back(_n % 10);
        _n /= 10;
    }
    a.resize(18);
    memset(dp, -1, sizeof(dp));
    int ans = 0, sum = 0;
    bool bigger = 0;
    for (int i = 17; i >= 0; i--)
    {
        for (int x = (bigger ? 0 : a[i]); x <= 9; x++)
        {
            int now = solve(i - 1, bigger | (x > a[i]), sum + x * x);
            if (k > now)
                k -= now;
            else
            {
                ans = ans * 10 + x;
                bigger |= x > a[i];
                sum += x * x;
                break;
            }
        }
    }
    cout << ans << endl;
}
