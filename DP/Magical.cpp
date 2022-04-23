int n;
int a[N];
int dp[N][200], last[N][200];
/*Main*/
void init() {
    memset(dp,0,sizeof(dp));
    memset(last,0,sizeof(last));
}
void solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int s = 1; s <= 100; s++)
        {
            if (s == a[i])
                last[i + 1][s] = i;
            else
                last[i + 1][s] = last[i][s];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int s = 1; s <= 200; s++)
        {
            dp[i][s] = dp[i - 1][s];
            if (s <= a[i])
                continue;
            if (last[i][s - a[i]])
            {
                int id=last[i][s-a[i]];
                dp[i][s] = max(dp[i][s], dp[id - 1][s] + 2);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=200;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
}

